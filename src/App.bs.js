// Generated by BUCKLESCRIPT VERSION 5.0.1, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Text$BsReactNative = require("bs-react-native/src/components/text.js");
var View$BsReactNative = require("bs-react-native/src/components/view.js");
var ReactNativeVoice = require("react-native-voice");
var Style$BsReactNative = require("bs-react-native/src/style.js");
var Button$BsReactNative = require("bs-react-native/src/components/button.js");

var main = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.flex(1),
      /* :: */[
        Style$BsReactNative.height(/* Pct */Block.__(1, [100])),
        /* :: */[
          Style$BsReactNative.justifyContent(/* Center */2),
          /* [] */0
        ]
      ]
    ]);

var speech = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.marginHorizontal(/* Pt */Block.__(0, [20])),
      /* [] */0
    ]);

var speechText = Style$BsReactNative.style(/* :: */[
      Style$BsReactNative.fontSize(/* Float */Block.__(0, [20])),
      /* [] */0
    ]);

var Styles = /* module */[
  /* main */main,
  /* speech */speech,
  /* speechText */speechText
];

function App(Props) {
  var match = React.useState((function () {
          return false;
        }));
  var setSpeechInProgress = match[1];
  var match$1 = React.useState((function () {
          return /* array */[];
        }));
  var setSpeech = match$1[1];
  React.useEffect((function () {
          ReactNativeVoice.default.onSpeechStart = (function (param) {
              console.log("Speech Started");
              return /* () */0;
            });
          ReactNativeVoice.default.onSpeechRecognized = (function (param) {
              console.log("Speech Recognized");
              return /* () */0;
            });
          ReactNativeVoice.default.onSpeechResults = (function (e) {
              return Curry._1(setSpeech, (function (param) {
                            return e.value;
                          }));
            });
          ReactNativeVoice.default.onSpeechError = (function (err) {
              console.log("Speech ERROR " + JSON.stringify(err.error));
              return /* () */0;
            });
          return undefined;
        }));
  return ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Caml_option.some(main), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[
                  ReasonReact.element(undefined, undefined, View$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, Caml_option.some(speech), undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined)(/* array */[$$Array.mapi((function (index, s) {
                                    return ReasonReact.element(String(index), undefined, Text$BsReactNative.make(undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, undefined, /* array */[s]));
                                  }), match$1[0])])),
                  match[0] ? ReasonReact.element(undefined, undefined, Button$BsReactNative.make(undefined, undefined, undefined, (function (param) {
                                  Curry._1(setSpeechInProgress, (function (param) {
                                          return false;
                                        }));
                                  ReactNativeVoice.default.stop();
                                  return /* () */0;
                                }), undefined, "Stop voice recognition")(/* array */[])) : ReasonReact.element(undefined, undefined, Button$BsReactNative.make(undefined, undefined, undefined, (function (param) {
                                  Curry._1(setSpeechInProgress, (function (param) {
                                          return true;
                                        }));
                                  ReactNativeVoice.default.start("en-US");
                                  return /* () */0;
                                }), undefined, "Start voice recognition")(/* array */[]))
                ]));
}

var make = App;

exports.Styles = Styles;
exports.make = make;
/* main Not a pure module */
