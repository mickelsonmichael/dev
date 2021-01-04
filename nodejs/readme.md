# NodeJS Notes

## Introduction to NodeJS - December 23, 2020

NodeJS runs on the V8 JavaScript engine, which is the same engine that Google Chrome utlizes. There is only one process and one thread. _Unlike ASP.NET Core, a thread is *not* created per request_. But, like ASP.NET, when a blocking task is started, it will be started on a worker thread and will be resumed on the main thread once the response is ready.

Unlike when working with browser compatibility, NodeJS allows the latest and greatest ECMA versions, only dependent on which version of NodeJS you are running your server with. You can also enable special experimental features using flags

Since the NodeJS JavaScript is not being run in the browser, you will not have access to `window` and `document` (or any other browser-related properties and methods). But, you have new modules provided by NodeJS including file IO. The main advantages of not running in the browser is knowing which version of JavaScript you have access to, while with a browser you would be a slave to <http://caniuse.com> or Babel/Webpack.

> Another difference is that Node.js uses the CommonJS module system, while in the browser we are starting to see the ES Modules standard being implemented.  
> In practice, this means that for the time being you use require() in Node.js and import in the browser.

Hopefully this changes with later versions of NodeJS, but for now it is an unfortunate dichotomy.

### The V8 Engine (for JavaScript)

There are many different engines used by browsers, but all of them implement the ECMAScript standards for JavaScript. The V8 engine in particular is used as the engine for Chrome and the latest version of Edge running on Chromium.

The engine itself provides the runtime environment which executes the JavaScript code. It does not provide any modules, which is why NodeJS lacks components such as the DOM. It is written in C++, and further reading can be done at the offical website <https://v8.dev>.

In 2009, the SpiderMonkey engine utilized by Firefox introduced the concept of compiling JavaScript, which allows for faster processing. This was eventually ported over to the V8 Engine, which now "compiles" the JavaScript as well as provides a JIT compiler to provide even more performance improvements.

### Running a NodeJS application

The `node` command can be utlized with any file, simply by running `node filename.js`. Once running, you can then exit the application by either entering the keystroke `Ctrl+C` in the terminal, or by calling the `process.exit(int)` method in you code. `0` is the default parameter to the `exit` method and indicates a normal exit. You can alternatively provide an [exit code](https://nodejs.org/api/process.html#process_exit_codes) to the method, or set the `process.exitCode` itself.

However, since calling `exit` stops any requests in process, it is best to send a `SIGTERM` message to the process, which you can then gracefully call the `close` method as below.

```js
const express = require("express");
const app = express();

// adds a GET listener for "/ping"
app.get("/ping", (req, res) => {
  res.send("pong");
});

// starts the app listening to port 3000
const server = app.listen(3000, () => console.log("ready"));

// adds a listener for SIGTERM
app.on("SIGTERM", () => {
  // closes gracefully
  server.close(() => console.log("closed"));
});
```

Alternatively, you could also send a `SIGKILL` message to the application, which _should ideally_ have the same effect as calling `process.exit()`.

```js
app.on("SIGKILL", () => process.exit());
```

These messages are generally sent by processess supervisors and not manually sent unless being tested.

If needed, you can send the signal from _inside_ the program like `process.kill(process.pid, "SIGTERM");`. You can also use this method to kill othe running applications as long as you know their PID.

### Environmental Variables

`process` contains a property `env` which will hold a list of the environmental variables available on the server. There are several variables built into NODE, most notably the `NODE_ENV` which is set to `development` by default. You can change this value to `production` to tell the server that it should be running in production mode.

_NOTE:_ My `NODE_ENV` value was set to `undefined` when running in WSL.

### REPL - Read Evaluate Print Loop

REPL is a programming concept where a single command is sent in via the console, executed by the server, and the response printed back to the console again. The process is repeated until the user exists. This the same way the `python` command works, but instead can be called by simply typing `node`.

Node's REPL mode also allows for auto-completing in a manner similar to the `ls` command in bash. Typing `Number.` and pressing `Tab` will display a list of all _known_ commands starting with `Number.` (e.g. `Number.NaN`, `Number.toString()`, etc.). This can be used to inspect global objects using the `global.` command then pressing `tab`. You can further narrow down the results by entering more of the command name, for instance entering `global.p` and pressing `tab` will list all the methods and properties on `global` that start with the letter `p`. These filters are **case_sensitive**.

Typing `_` will print the result of the last operation, without re-running it.

```repl
> new DateTime();
// returns current time (e.g. 12:01:17)
// wait...
> _
// returns current time at the time of the last execution
// (e.g. 12:01:17 again)
```

There are some helper methods called "dot commands" that all begin with a period, like `.help`. `.help` shows the dot commands help and `.exit` will exit the REPL session.

Finally, REPL is smart enough to know when you haven't finished a statement and are instead attempting to go to a new line. If you have left a parenthesis or brace un-closed, REPL will allow you to continue on a new line once you press enter. You can cancel your multi-line command by typing `.break`.

### Command-line Arguments

You can pass any number of arguments to the command line, either by entering them free-form like `node app.js arg1 arg2`.

The values are passed to the `process.argv` property, and can be accessed as a list inside the program. The first two values are pre-defined and cannot be changed:

1. The path of the node command
2. The path to the file running the command

The rest can be accessed by iterating over the `argv` values, which are in order they appear in the `node` command. To quickly exclude the first two results, you can simply use `const args = process.argv.slice(2);`.

Using the [minimist](https://www.npmjs.com/package/minimist) libary, you can input your args in a `key=value` format, and retrieve them afterwards using `args[key]`.

### `console` features

The `console` provided by NodeJS is similar to the browser `console` in most ways. However there are a few noteworthy commands that could come in handy

- `console.trace()` prints the stack trace
- `console.count(obj)` will print the number of items in an iterable
- `console.time(string: name)` and `console.timeEnd(string: name)` can be used to time a segment of code

Additionally, `console.log` prints to `stdout` while `console.error` prints to `stderr`. Error messages will therefore not print to the console, but will still be logged.

You can color the console messages manually, but there are libraries like [Chalk](https://github.com/chalk/chalk) that can handle it for you much more easily.

You can also create a progress bar using the [Progress](https://www.npmjs.com/package/progress) library.

### An Interactive Node Application

Since Node v7, there is now the `readline` module, which can be imported using `const readline = require("readline");`. More specifically, it can be configured to listen to certain streams like `stdin` and `stdout`.

```js
const readline = require("readline").createInterface({
  input: proces.stdin,
  output: process.stdout,
});

readline.question("What day is it?", (answer) => {
  console.log(answer);
  readline.close(); // closes the readline for reading
});
```

There are several packages that provide more robust features if you require them, including [readline-sync](https://www.npmjs.com/package/readline-sync) and [Inquirer.js](https://github.com/SBoudrias/Inquirer.js), with the latter offering advanced features like radio buttons and multiple choice answers.

### Exporting

Unlike with the browser-based system of exports, you will need to utilize the `module.exports` property in order to define public methods and data from your files.

You can either define the `exports` property as entire object like:

```js
const server = {
  port: 3000,
  host: "www.test.com",
};

module.exports = server;
```

Or, you can add a property to exports like:

```js
const server = { ... };

exports.server = server;

// OR

exports.server = { ... }
```

The exports can then be imported in other files using `require("./path/to/file");`.

```js
// from info.js
const info = require("./info");
info.server; // OK

const server = require("./info").server; // OK
```

`module.exports` and `exports` are different, but only slightly. `exports` alone exposes only the properties of the object it points to, while `module.exports` exposes the entire thing.

### Notes on `npm`

The `--save` flag on `npm install <package>` will save the package as a dependency that **will be bundled with the application**, which the `--save-dev` flag will be excluded from the build and is meant for libraries that aren't used to run the application (e.g. ESLint, testing libraries, etc.).

You can utilize the `npm root -g` command to print the location of your globally installed packages.

Some packages install binaries that can be run, which can either be run manually by specifying the full path of the application, or by simply running `npx <library>`, which will allow `npx` to find the package location on its own.
