const express = require("express");
const session = require("express-session");

//TODO: find out if passing a code to exit overwrites exitCode
//process.exitCode = 2;
//process.exit(1);

console.log("Starting server...");

const app = express();

app.get("/", (request, response) => {
  response.send("Request responded to successfully");

  if (request.session.isLoggedIn) {
    response.send("<a href='/logout'>Logout</a>");
  } else {
    response.send("<a href='/login'>Login</a>");
  }
});

const defaultState = {
  isLoggedIn: true,
};

app.use(session(defaultState));

app.get("/login", (request, response) => {
  request.session.isLoggedIn = true;

  response.redirect("/");
});

app.listen(3000, "localhost", () =>
  console.log(`listening on ${process.env.HOST}:${process.env.PORT}`)
);
