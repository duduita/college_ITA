import React from "react";
import { View, Text, StyleSheet, Image } from "react-native";

const ImageDetail = (props) => {
  return (
    <View>
      <Image source={props.imageSource} />
      <Text>Minha props é {props.title}</Text>
    </View>
  );
};

const styles = StyleSheet.create({});

export default ImageDetail;
