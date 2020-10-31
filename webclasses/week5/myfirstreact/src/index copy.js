import React from "react";
import ReactDOM from "react-dom";

const element = <h1>Hello, world!</h1>;

const element2 = React.createElement(
  "h1",
  { className: "greeting" },
  "hello, world!"
);
ReactDOM.render(element2, document.getElementById("root"));
