console.log("node path: " + process.argv[0]);

console.log("file path: " + process.argv[1]);

const args = process.argv.slice(2);

console.log("additional arguments:");

args.forEach((arg, i) => {
  console.log(i + ": " + arg);
});
