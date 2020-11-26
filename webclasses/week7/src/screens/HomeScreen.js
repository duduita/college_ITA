import React, { useReducer } from "react";
import { Text, StyleSheet, View, TextInput } from "react-native";
import OperatorControl from "../components/OperatorControl";

const reducer = (state, action) => {
  switch (action.type) {
    case "sum":
      return {
        ...state,
        result: parseFloat(state.result) + parseFloat(action.payload),
      };
    case "sub":
      return {
        ...state,
        result: parseFloat(state.result) - parseFloat(action.payload),
      };
    case "div":
      return {
        ...state,
        result: parseFloat(state.result) / parseFloat(action.payload),
      };
    case "mult":
      return {
        ...state,
        result: parseFloat(state.result) * parseFloat(action.payload),
      };
    case "update":
      return { ...state, value: action.payload };
  }
};

const HomeScreen = () => {
  const [state, dispatch] = useReducer(reducer, {
    count: 0,
    value: 0,
    result: 0,
  });
  const { count, value, results } = state;
  console.log(state);

  return (
    <View>
      <Text style={styles.text}>{state.result}</Text>
      <OperatorControl
        title="Somar"
        onUse={(e) => dispatch({ type: "sum", payload: state.value })}
      />
      <OperatorControl
        title="Subtrair"
        onUse={(e) => dispatch({ type: "sub", payload: state.value })}
      />
      <OperatorControl
        title="Dividir"
        onUse={(e) => dispatch({ type: "div", payload: state.value })}
      />
      <OperatorControl
        title="Multiplicar"
        onUse={(e) => dispatch({ type: "mult", payload: state.value })}
      />
      <TextInput
        id="test"
        type="number"
        onChangeText={(e) => dispatch({ type: "update", payload: e })}
        style={{ height: 40, borderColor: "gray", borderWidth: 1 }}
      />
    </View>
  );
};

const styles = StyleSheet.create({
  text: {
    fontSize: 30,
  },
});

export default HomeScreen;
