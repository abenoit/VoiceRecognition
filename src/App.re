open BsReactNative;

module Styles = {
  open Style;

  let main = style([flex(1.), height(Pct(100.)), justifyContent(Center)]);

  let speech = style([marginHorizontal(Pt(20.))]);
  let speechText = style([fontSize(Float(20.))]);
};

[@react.component]
let make = () => {
  let (speechInProgress, dispatch) = React.useState(() => false);
  let (speech, setSpeech) = React.useState(() => [||]);

  React.useEffect(() => {
    Voice.voice##onSpeechStart #= (() => Js.log("onSpeechStart"));
    Voice.voice##onSpeechRecognized #= (() => Js.log("onSpeechStart"));
    Voice.voice##onSpeechResults #= (e => setSpeech(_ => e##value));
    Voice.voice##onSpeechError
    #= (err => Js.log("Speech ERROR (using effect)"));
    None;
  });

  <View style=Styles.main>
    <View style=Styles.speech>
      {
        speech
        |> Array.mapi((index, s) =>
             <Text key=index->string_of_int> {ReasonReact.string(s)} </Text>
           )
        |> ReasonReact.array
      }
    </View>
    {
      speechInProgress ?
        <Button
          title="Stop voice recognition"
          onPress={
            () => {
              dispatch(_ => false);
              Voice.(voice->stop);
            }
          }
        /> :
        <Button
          title="Start voice recognition"
          onPress={
            () => {
              dispatch(_ => true);
              Voice.(start(voice, "us-US"));
            }
          }
        />
    }
  </View>;
};