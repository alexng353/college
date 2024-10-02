import fs from "fs/promises";
import { exec } from "child_process";

const templateData = await fs.readFile("./documentTemplate.txt", "utf-8");
if (
  !templateData.includes("{content}") || false
  // !templateData.includes("{questionNumber}")
) {
  throw new Error("Document Template Invalid");
}

const argv = process.argv;

const assignment = argv[2];
const fileName = assignment.split("/").pop();
if (!fileName) throw new Error("bruh");

const out = "./Assignments/Assignment 1";

function packageQuestions(data: string[]) {
  const pairedResult = [];

  for (let i = 0; i < data.length; i += 2) {
    const pair = data.slice(i, i + 2);
    pairedResult.push(pair);
  }

  return pairedResult;
}

function scrub(text: string) {
  const startTag = '\\maketitle';
  const endTag = '\\end{document}';

  const startIndex = text.indexOf(startTag);
  const endIndex = text.indexOf(endTag);

  if (startIndex !== -1 && endIndex !== -1) {
    const split = text.substring(startIndex + startTag.length, endIndex);
    return split.trim();
  } else {
    return null; // Return null if the tags are not found
  }
}

function template(questionNumber: number, content: string) {
  const templatedNumber = `\\section*{Question ${questionNumber}}`;

  return templateData
    .replace('{content}', templatedNumber + "\n" + content);
}

async function generateLatexPdf(filename: string): Promise<string> {
  return new Promise<string>((resolve, reject) => {
    exec(`latexmk -pdf ${filename}`, (error, stdout, stderr) => {
      if (error) {
        reject(`Error executing latexmk: ${error.message}`);
        return;
      }

      if (stderr) {
        console.warn(`stderr: ${stderr}`);
      }

      resolve(stdout);
    });
  });
}

async function clean() {
  const dir = await fs.readdir(".");

  const files = dir.filter((b) => !Number.isNaN(Number.parseInt(b.at(0) ?? "NaN")));

  if (files.length === 0) return

  console.log(files)

  for (const file of files) {
    await fs.rm(file);
  }
}

const file = await fs.readFile(assignment, 'utf-8');
const scrubbed = scrub(file)
if (!scrubbed) {
  throw new Error("Scrub Failed");
}

let splits = scrubbed.split(/\\subsection\*{Question (\d*)}/g);

if (splits[0] === "") splits = splits.slice(1);

const packaged = packageQuestions(splits);

for (const [idx, split] of packaged.entries()) {
  if (split.length !== 2) {
    console.error(`split ${idx} doesn't fit the correct size`);
    console.debug("split:", split);
    continue;
  };
  const questionNumber = Number.parseInt(split[0]);
  const content = split[1];

  if (Number.isNaN(questionNumber)) {
    console.error("questionNumber is not an integer")
    console.debug("questionNumber:", questionNumber);
    continue;
  };

  console.log(`Writing ${idx}.tex`);
  await fs.writeFile(`./${idx}.tex`, template(questionNumber, content));
  console.log(`Generating ${idx}.tex`);
  await generateLatexPdf(`./${idx}.tex`).catch((error) => {
    console.error(error);
  });
  console.log(`Successfully generated ${idx}.pdf`);

  const folderName = fileName.split(".").slice(0, fileName.split(".").length - 1).join(".");

  if (!await fs.exists(`${out}/${folderName}/`)) {
    await fs.mkdir(`${out}/${folderName}/`);
  }

  await fs.copyFile(`./${idx}.pdf`, `${out}/${folderName}/Question ${questionNumber}.pdf`)
    .catch((error) => {
      console.error("Failed to Copy File");
      console.error(error);
    });
}

await clean();

process.exit(0);
