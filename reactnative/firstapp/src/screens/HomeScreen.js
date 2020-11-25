import React from "react";
import { Text, StyleSheet, View, Button, TouchableOpacity } from "react-native";
import DeprecatedViewPropTypes from "react-native/Libraries/DeprecatedPropTypes/DeprecatedViewPropTypes";

const HomeScreen = ({ navigation }) => {
  return (
    <View>
      <Text style={styles.text}>pai ta on</Text>
      <Button
        onPress={() => navigation.navigate("Components")}
        title="Go to Components Demo"
      />
      <Button
        title="Go to List Demo"
        onPress={() => navigation.navigate("List")}
      ></Button>
      <Button
        title="Go to Image Demo"
        onPress={() => navigation.navigate("Image")}
      ></Button>
      <Button
        title="Go to Counter"
        onPress={() => navigation.navigate("Counter")}
      ></Button>
      <Button
        title="Go to Color"
        onPress={() => navigation.navigate("Color")}
      ></Button>
      <Button
        title="Go to Square"
        onPress={() => navigation.navigate("Square")}
      ></Button>
    </View>
  );
};

const styles = StyleSheet.create({
  text: {
    fontSize: 30,
  },
});

export default HomeScreen;
