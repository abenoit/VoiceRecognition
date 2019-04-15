open ReactNative;

[@react.component]
let make = (~speech: array(string)) =>
  <View>
    {speech
     |> Array.mapi((index, s) =>
          <Text key={index->string_of_int}> {ReasonReact.string(s)} </Text>
        )
     |> ReasonReact.array}
  </View>;