import fs from "fs/promises";

const dir = await fs.readdir(".");

const files = dir.filter((b) => !Number.isNaN(Number.parseInt(b.at(0) ?? "NaN")));

console.log(files)

for (const file of files) {
  await fs.rm(file);
}
