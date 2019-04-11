open BsReactNative;

module Styles = {
  open Style;

  let main = style([flex(1.), height(Pct(100.)), justifyContent(Center)]);

  let speech = style([marginHorizontal(Pt(20.))]);
  let speechText = style([fontSize(Float(20.))]);
};

[@react.component]
let make = () => {
  let (speechInProgress, setSpeechInProgress) = React.useState(() => false);
  let (speech, setSpeech) = React.useState(() => [||]);

  React.useEffect(() => {
    Voice.voice##onSpeechStart #= (() => Js.log("Speech Started"));
    Voice.voice##onSpeechRecognized #= (() => Js.log("Speech Recognized"));
    Voice.voice##onSpeechResults #= (e => setSpeech(_ => e##value));
    Voice.voice##onSpeechError
    #= (err => Js.log("Speech ERROR " ++ Js.Json.stringify(err##error)));
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
              setSpeechInProgress(_ => false);
              Voice.(voice->stop);
            }
          }
        /> :
        <Button
          title="Start voice recognition"
          onPress={
            () => {
              setSpeechInProgress(_ => true);
              Voice.(start(voice, "en-US"));
            }
          }
        />
    }
  </View>;
};