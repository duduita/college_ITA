import React from "react";
import { Text, StyleSheet, View } from "react-native";

const ComponentsScreen = () => {
  const greeting = <Text>Hello!!</Text>;
  return (
    <View>
      <Text style={styles.subHeaderStyle}>HomeScreen</Text>
      {greeting}
    </View>
  );
};

const styles = StyleSheet.create({
  text: {
    fontSize: 30,
  },
  subHeaderStyle: {
    fontSize: 50,
  },
});

export default ComponentsScreen;
