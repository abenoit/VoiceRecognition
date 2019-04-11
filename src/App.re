open BsReactNative;

module Styles = {
  open Style;

  let main = style([flex(1.)]);
};

[@react.component]
let make = () =>
  <View> <Text> {ReasonReact.string("Hello world")} </Text> </View>;