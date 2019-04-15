open BsReactNative;

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

  <View>
    <Speech speech />
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