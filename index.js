/**
 * @format
 */

import { AppRegistry } from "react-native";
import { name as appName } from "./app.json";
const App = require("./src/App.bs.js").make;

AppRegistry.registerComponent(appName, () => App);
