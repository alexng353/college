import fs from "fs/promises";

const templateData = await fs.readFile("./documentTemplate.txt", "utf-8");

const input = `
Section 2.1: 12, 34, 44, 50.
Section 2.2: 6, 8, 10.
`.trim();

const splits = input.split("\n");

for (const split of splits) {
  const [section, problemsStr] = split.split(":").map(s => s.trim());
  const problems = problemsStr.replace(".", "").split(",").map(s => Number.parseInt(s.trim()));
  const sectionNumber = Number.parseFloat(section.split(" ").at(-1)!.trim());

  const header = `
\\title{MACM 101 Chapter ${sectionNumber} Homework}
\\author{Alexander Ng}
\\date{${today()}}

\\maketitle

`.trimStart();
  const problemsContent = problems.map(n => problemTemplate(n)).join("\n");

  const data = template(header + problemsContent);

  if (await fs.exists(`./Assignments/Assignment ${sectionNumber}.tex`)) {
    await fs.copyFile(
      `./Assignments/Assignment ${sectionNumber}.tex`,
      `./Assignments/Assignment ${sectionNumber} - ${Date.now()}.tex.bak`
    );
  }

  await fs.writeFile(`./Assignments/Assignment ${sectionNumber}.tex`, data);
}


function template(content: string) {
  return templateData.replace('{content}', content);
}

function problemTemplate(problemNumber: number) {
  return `\\subsection*{Question ${problemNumber}}`
}

function today() {
  return new Date().toLocaleDateString('en-US',
    {
      weekday: 'long',
      year: 'numeric',
      month: 'long',
      day: 'numeric'
    }
  );
}
