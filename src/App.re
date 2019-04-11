open BsReactNative;

module Styles = {
  open Style;

  let main = style([flex(1.), height(Pct(100.)), justifyContent(Center)]);
};

[@react.component]
let make = () =>
  <View style=Styles.main>
    <Button title="Start voice recognition" onPress={() => ()} />
  </View>;