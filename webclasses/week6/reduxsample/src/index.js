import React from "react";
import ReactDOM from "react-dom";
import "./assets/index.css";

import calculatorReducer from "./reducers";
import { createStore } from "redux";

import { Provider } from "react-redux";

import App from "./App";

let store = createStore(calculatorReducer);

ReactDOM.render(
  <Provider store={store}>
    <App />
  </Provider>,
  document.getElementById("root")
);
