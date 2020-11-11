import React, { Component } from "react";
import { connect } from "react-redux";

class CalcButtonComponent extends Component {
  render() {
    return (
      <button
        className={`calc-input ${this.props.additionalClass}`}
        onClick={() =>
          this.props.updateCalculation(
            this.props.value,
            this.props.calculation,
            this.props.result
          )
        }
      >
        {" "}
        {this.props.htmlCode
          ? String.fromCharCode(this.props.htmlCode)
          : this.props.value}
      </button>
    );
  }
}

const mapStateToProps = (state) => {
  return {
    ctr: state.counter,
    value: state.value,
  };
};

const mapDispatchToProps = (dispatch) => {
  return {
    Subtraction: (e) => dispatch({ type: "SUBTRACTION", payLoad: e }),
    Multiplication: (e) => dispatch({ type: "MULTIPLICATION", payLoad: e }),
    Sum: (e) => dispatch({ type: "SUM", payLoad: e }),
    Division: (e) => dispatch({ type: "DIVISION", payLoad: e }),
  };
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(CalcButtonComponent);
