import React from "react";
import { View, Text, StyleSheet, Button } from "react-native";

const OperatorControl = ({ title, onUse }) => {
  return (
    <View>
      <Button onPress={() => onUse()} title={`${title}`} />
    </View>
  );
};

const styles = StyleSheet.create({});

export default OperatorControl;
