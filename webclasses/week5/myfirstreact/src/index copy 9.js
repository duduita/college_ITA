import React from "react";
import ReactDOM, { render } from "react-dom";

class Football extends React.Component {
  ShadowRoot() {
    alert("Great Shot!");
  }
  render() {
    return <button onClick={this.shoot}>Take the shot!</button>;
  }
}
ReactDOM.render(<Football />, document.getElementById("root"));
