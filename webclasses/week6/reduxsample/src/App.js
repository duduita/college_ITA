import React, { Component } from "react";
import CalcButton from "./components/CalcButton";

class CalculatorComponent extends Component {
  render() {
    return (
      <div className="calculator">
        <div className="calculator-inputs-row">
          <CalcButton value={7} />
          <CalcButton value={8} />
          <CalcButton value={9} />
          <CalcButton value="/" htmlCode="247" additionalClass="operator" />
        </div>
        <div className="calculator-inputs-row">
          <CalcButton value={4} />
          <CalcButton value={5} />
          <CalcButton value={6} />
          <CalcButton value="*" htmlCode="215" additionalClass="operator" />
        </div>
        <div className="calculator-inputs-row">
          <CalcButton value={1} />
          <CalcButton value={2} />
          <CalcButton value={3} />
          <CalcButton value="-" htmlCode="8722" additionalClass="operator" />
        </div>
        <div className="calculator-inputs-row">
          <CalcButton value={0} additionalClass="zero" />
          <CalcButton value="+" htmlCode="43" additionalClass="operator" />
        </div>
      </div>
    );
  }
}

export default CalculatorComponent;
