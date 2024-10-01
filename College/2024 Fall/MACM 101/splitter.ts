import fs from "fs/promises";
import { exec } from "child_process";

const assignment = "./Assignments/Assignment 1.tex";
const out = "./Assignments/Assignment 1";

function packageQuestions(dataArray: string[]) {
  const trimmedArray = dataArray.slice(1);

  const pairedResult = [];

  for (let i = 0; i < trimmedArray.length; i += 2) {
    const pair = trimmedArray.slice(i, i + 2);
    pairedResult.push(pair);
  }

  return pairedResult;
}

function template(questionNumber: number, content: string) {
  `
\\documentclass[12pt]{article}
\\usepackage{amsmath}
\\usepackage{amssymb}
\\usepackage{amsthm}
\\usepackage{amsfonts}
\\usepackage{graphicx}
\\usepackage{textcomp}
\\usepackage{hyperref}
\\usepackage{tikz}
\\usepackage{enumitem}
\\usepackage{mathtools}
\\usepackage{float}
\\usepackage{cleveref}
\\usepackage{hyperref}
\\usepackage{csquotes}

\\begin{document}

\\section*{Question {questionNumber}}

{content}

\\end{document}`
    .replace('{content}', content)
    .replace('{questionNumber}', questionNumber.toString());
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

  console.log(files)

  for (const file of files) {
    await fs.rm(file);
  }
}

const file = await fs.readFile(assignment, 'utf-8');

const splits = file.split(/\\subsection\*{Question (\d+)}/g);
const packaged = packageQuestions(splits);

for (const [idx, split] of packaged.entries()) {
  if (split.length !== 2) {
    console.log(`split ${idx} doesn't fit the correct size`);
    console.debug("split:", split);
    continue;
  };
  const questionNumber = Number.parseInt(split[0]);
  const content = split[1];

  if (Number.isNaN(questionNumber)) {
    console.log("questionNumber is not an integer")
    console.debug("questionNumber:", questionNumber);
  };

  await fs.writeFile(`./${idx}.tex`, template(questionNumber, content));
  await generateLatexPdf(`./${idx}.tex`).catch((error) => {
    console.log(error);
  });

  await fs.copyFile(`./${idx}.pdf`, `${out}/Question ${questionNumber}.pdf`)
    .catch((error) => {
      console.error("Failed to Copy File");
      console.log(error);
    });
}

await clean();

process.exit(0);
