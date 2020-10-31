import React from "react";
import ReactDOM, { render } from "react-dom";
import PostData from "./data/posts.json";

class MyTable extends React.Component {
  constructor(props) {
    super(props);
    this.data = props.data;
  }
  getRows() {
    return this.data["data"].map((key, index) => {
      return (
        <tr>
          <td>{key["nome"]}</td>
          <td>{key["idade"]}</td>
        </tr>
      );
    });
  }
  render() {
    return (
      <table>
        <thead>
          <tr>
            <th>Nome</th>
            <th>Idade</th>
          </tr>
        </thead>
        <tbody>{this.getRows()}</tbody>
      </table>
    );
  }
}
class MyForm extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      username: "",
      age: null,
      errormessage: "",
    };
  }
  myChangeHandler = (event) => {
    let nam = event.target.name;
    let val = event.target.value;
    let err = "";
    if (nam === "age") {
      if (val != "" && !Number(val)) {
        err = <strong>Your age must be a number</strong>;
      }
      if (val < 18) {
        err = <strong>You must be over 18</strong>;
      }
    }
    this.setState({ errormessage: err });
    this.setState({ [nam]: val });
    fetch("/send_data", {
      method: "POST",
      body: event,
    });
  };
  render() {
    return (
      <form>
        <h1>
          Hello {this.state.username} {this.state.age}
        </h1>
        <p>Enter your name:</p>
        <input type="text" name="username" onChange={this.myChangeHandler} />
        <p>Enter your age:</p>
        <input type="text" name="age" onChange={this.myChangeHandler} />
        {this.state.errormessage}
      </form>
    );
  }
}
class MyButton extends React.Component {
  obterDados() {
    fetch("/get_data")
      .then((response) => response.json())
      .then((data) => {
        ReactDOM.unmountComponentAtNode(document.getElementById("myTable"));
        ReactDOM.render(
          <MyTable data={data} />,
          document.getElementById("myTable")
        );
      });
  }

  render() {
    return (
      <div>
        <button onClick={this.obterDados}>Obter Dados!</button>
        <div id="myTable"></div>
      </div>
    );
  }
}
ReactDOM.render(<MyForm />, document.getElementById("root"));

ReactDOM.render(<MyButton />, document.getElementById("tabela"));
