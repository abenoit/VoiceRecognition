open BsReactNative;

type error = {. "error": Js.Json.t};
type result = {. "value": array(string)};

type voice = {
  .
  [@bs.set] "onSpeechStart": unit => unit,
  [@bs.set] "onSpeechRecognized": unit => unit,
  [@bs.set] "onSpeechResults": result => unit,
  [@bs.set] "onSpeechError": error => unit,
};

[@bs.module "react-native-voice"] external voice: voice = "default";
[@bs.send] external start: (voice, string) => unit = "start";
[@bs.send] external stop: voice => unit = "stop";