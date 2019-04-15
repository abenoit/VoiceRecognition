open BsReactNative;

module Styles = {
  open Style;
  let a = style([marginHorizontal(Pt(20.))]);
};

[@react.component]
let make = (~speech: array(string)) =>
  <View style=Styles.a>
    {
      speech
      |> Array.mapi((index, s) =>
           <Text key=index->string_of_int> {ReasonReact.string(s)} </Text>
         )
      |> ReasonReact.array
    }
  </View>;