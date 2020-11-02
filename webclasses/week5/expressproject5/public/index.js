class MyForm extends React.Component {
  verifyAge(event) {
    event.preventDefault();
    var form = new FormData(event.target);
    if (!Number(form.get("age"))) {
      alert("Age must be a number");
      return;
    }
    if (form.get("age") < 18) {
      alert("Your age must be over 18");
      return;
    }
    fetch("/sendData", {
      method: "POST",
      body: form,
    });
  }
  render() {
    return (
      <form onSubmit={this.verifyAge}>
        <br></br>
        <input type="text" name="name" placeholder="Name" />
        <input type="text" name="age" placeholder="Age" />
        <br />
        <input type="submit" class="btn btn-dark" value="Send" />
      </form>
    );
  }
}

ReactDOM.render(<MyForm />, document.getElementById("root"));

class MyTable extends React.Component {
  constructor(props) {
    super(props);
    this.data = props.data;
  }
  getRows() {
    return this.data["database"].map((key, index) => {
      return (
        <tr>
          <td>{key["name"]}</td>
          <td>{key["age"]}</td>
        </tr>
      );
    });
  }
  render() {
    return (
      <table>
        <thead>
          <tr>
            <th>Name</th>
            <th>Age</th>
          </tr>
        </thead>
        <tbody>{this.getRows()}</tbody>
      </table>
    );
  }
}

class MyButton extends React.Component {
  get_Data() {
    fetch("/getData")
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
        <button class="btn btn-dark" onClick={this.get_Data}>
          Get Data!
        </button>
        <div id="myTable"></div>
      </div>
    );
  }
}

ReactDOM.render(<MyButton />, document.getElementById("table"));
