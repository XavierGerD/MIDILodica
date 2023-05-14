
#define menusLength 10
#define settingsLength 10
#define sensorLength 6
#define stripLength 5
#define scaleLength 14
#define startingNoteLength 12
#define startingOctaveLength 9
#define sensitivityLength 4
#define underButtonLength 3
#define patchLength 10

byte currentMenu = 0;
int currentNumberSelectMenu = -1;
int currentMenuItem = 0;

int getSettingsMenuSelectedValue() {
  return -1;
}

Menu settingsMenuItems[settingsLength] = {
  Menu("Sensor Mode", 1, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Strip Mode", 2, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Scale", 3, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Tonic", 4, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Octave", 5, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Sensitivity", 6, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Under button", 7, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Save", 8, navigateToSubmenu, getSettingsMenuSelectedValue),
  Menu("Load", 9, navigateToSubmenu, getSettingsMenuSelectedValue),

  // submenu is 1 here because it belongs to the allNumberSelectMenus list and not the regular allMenus list.
  Menu("MIDI Channel", 0, navigateToNumberSelectSubmenu, getSettingsMenuSelectedValue),

};

int getSelectedSensorMode() {
  return sensorMode;
}

void changeSetting(byte setting) {
  sensorMode = setting;
  navigateToSubmenu(0);
}

Menu sensorModeMenuItems[sensorLength] = {
  Menu("Velocity", SENSOR_VELOCITY, changeSetting, getSelectedSensorMode),
  Menu("Mod Wheel", SENSOR_MOD_WHEEL, changeSetting, getSelectedSensorMode),
  Menu("Pitch Bend", SENSOR_PITCH_BEND, changeSetting, getSelectedSensorMode),
  Menu("Octave Shift", SENSOR_OCTAVE_SHIFT, changeSetting, getSelectedSensorMode),
  Menu("Off", SENSOR_OFF, changeSetting, getSelectedSensorMode),
  // submenu is 1 here because it belongs to the allNumberSelectMenus list and not the regular allMenus list.
  Menu("Custom CC", 1, navigateToNumberSelectSubmenu, getSelectedSensorMode),
};

int getSelectedStripMode() {
  return stripSensorMode;
}

void changeStripSetting(byte setting) {
  stripSensorMode = setting;

  // Restore velocity.
  if (setting != 0) {
    velocity = 127;
  }
  navigateToSubmenu(0);
}

Menu stripModeMenuItems[stripLength] = {
  Menu("Velocity", STRIP_VELOCITY, changeStripSetting, getSelectedStripMode),
  Menu("Mod Wheel", STRIP_MOD_WHEEL, changeStripSetting, getSelectedStripMode),
  Menu("Pitch Bend", STRIP_PITCH_BEND, changeStripSetting, getSelectedStripMode),
  Menu("Off", STRIP_OFF, changeStripSetting, getSelectedStripMode),
  // submenu is 1 here because it belongs to the allNumberSelectMenus list and not the regular allMenus list.
  Menu("Custom CC", 2, navigateToNumberSelectSubmenu, getSelectedStripMode),
};

int getSelectedScale() {
  return currentScale;
}

void changeScale(byte note) {
  currentScale = currentMenuItem;
  endMenuInteraction();
}

Menu scaleMenuItems[scaleLength] = {
  Menu("Chromatic", 0, changeScale, getSelectedScale),
  Menu("Ionian", 1, changeScale, getSelectedScale),
  Menu("Dorian", 2, changeScale, getSelectedScale),
  Menu("Phryigian", 3, changeScale, getSelectedScale),
  Menu("Lydian", 4, changeScale, getSelectedScale),
  Menu("Mixolydian", 5, changeScale, getSelectedScale),
  Menu("Aeolian", 6, changeScale, getSelectedScale),
  Menu("Locrian", 7, changeScale, getSelectedScale),
  Menu("Mel. Minor", 8, changeScale, getSelectedScale),
  Menu("Penta. Maj.", 9, changeScale, getSelectedScale),
  Menu("Penta. Min.", 10, changeScale, getSelectedScale),
  Menu("Whole Tone", 11, changeScale, getSelectedScale),
  Menu("Octa. 2, 1", 12, changeScale, getSelectedScale),
  Menu("Octa. 1, 2", 13, changeScale, getSelectedScale),
};

int getStartingNote() {
  return currentStartingNote;
}

void changeStartingNote(byte note) {
  currentStartingNote = note;
  endMenuInteraction();
}

Menu startingNoteMenuItems[startingNoteLength] = {
  Menu("C", 0, changeStartingNote, getStartingNote),
  Menu("Db", 1, changeStartingNote, getStartingNote),
  Menu("D", 2, changeStartingNote, getStartingNote),
  Menu("Eb", 3, changeStartingNote, getStartingNote),
  Menu("E", 4, changeStartingNote, getStartingNote),
  Menu("F", 5, changeStartingNote, getStartingNote),
  Menu("Gb", 6, changeStartingNote, getStartingNote),
  Menu("G", 7, changeStartingNote, getStartingNote),
  Menu("Ab", 8, changeStartingNote, getStartingNote),
  Menu("A", 9, changeStartingNote, getStartingNote),
  Menu("Bb", 10, changeStartingNote, getStartingNote),
  Menu("B", 11, changeStartingNote, getStartingNote),
};

int getStartingOctave() {
  return currentStartingOctave;
}

void changeStartingOctave(byte octave) {
  currentStartingOctave = octave;
  endMenuInteraction();
}

Menu startingOctaveMenuItems[startingOctaveLength] = {
  Menu("0", 0, changeStartingOctave, getStartingOctave),
  Menu("1", 1, changeStartingOctave, getStartingOctave),
  Menu("2", 2, changeStartingOctave, getStartingOctave),
  Menu("3", 3, changeStartingOctave, getStartingOctave),
  Menu("4", 4, changeStartingOctave, getStartingOctave),
  Menu("5", 5, changeStartingOctave, getStartingOctave),
  Menu("6", 6, changeStartingOctave, getStartingOctave),
  Menu("7", 7, changeStartingOctave, getStartingOctave),
  Menu("8", 8, changeStartingOctave, getStartingOctave),
};

int getSensitivity() {
  return currentSensitivity;
}

void changeSensitivity(byte setting) {
  currentSensitivity = setting;
  endMenuInteraction();
}

Menu sensitivityMenuItems[sensitivityLength] = {
  Menu("Low", 0, changeSensitivity, getSensitivity),
  Menu("Medium", 1, changeSensitivity, getSensitivity),
  Menu("High", 2, changeSensitivity, getSensitivity),
  Menu("Very High", 3, changeSensitivity, getSensitivity),
};

int getUnderButtonMode() {
  return underButtonMode;
}

void changeUnderButtonMode(byte newValue) {
  underButtonMode = newValue;
  endMenuInteraction();
}

Menu underButtonMenuItems[underButtonLength] = {
  Menu("Octave Up", UNDER_BUTTON_8VA_UP, changeUnderButtonMode, getUnderButtonMode),
  Menu("Octave Down", UNDER_BUTTON_8VA_DOWN, changeUnderButtonMode, getUnderButtonMode),
  Menu("Sustain", UNDER_BUTTON_SUSTAIN, changeUnderButtonMode, getUnderButtonMode),
};

int getPatch() {
  return -1;
}

void savePatch(byte startingLocation) {
  savePatchInternal(startingLocation);
  endMenuInteraction();
}

Menu savePatchMenuItems[patchLength] = {
  Menu("1", 0, savePatch, getPatch),
  Menu("2", 1, savePatch, getPatch),
  Menu("3", 2, savePatch, getPatch),
  Menu("4", 3, savePatch, getPatch),
  Menu("5", 4, savePatch, getPatch),
  Menu("6", 5, savePatch, getPatch),
  Menu("7", 6, savePatch, getPatch),
  Menu("8", 7, savePatch, getPatch),
  Menu("9", 8, savePatch, getPatch),
  Menu("10", 9, savePatch, getPatch),
};

void loadPatch(byte startingLocation) {
  loadProgramInternal(startingLocation);
  endMenuInteraction();
}

Menu loadPatchMenuItems[patchLength] = {
  Menu("1", 0, loadPatch, getPatch),
  Menu("2", 1, loadPatch, getPatch),
  Menu("3", 2, loadPatch, getPatch),
  Menu("4", 3, loadPatch, getPatch),
  Menu("5", 4, loadPatch, getPatch),
  Menu("6", 5, loadPatch, getPatch),
  Menu("7", 6, loadPatch, getPatch),
  Menu("8", 7, loadPatch, getPatch),
  Menu("9", 8, loadPatch, getPatch),
  Menu("10", 9, loadPatch, getPatch),
};

Menu *allMenus[menusLength] = {
  settingsMenuItems,
  sensorModeMenuItems,
  stripModeMenuItems,
  scaleMenuItems,
  startingNoteMenuItems,
  startingOctaveMenuItems,
  sensitivityMenuItems,
  underButtonMenuItems,
  savePatchMenuItems,
  loadPatchMenuItems
};

void onUpdateMIDIChannel(int newMIDIChannel) {
  // -1 because channels start a index 0 but are
  // presented at 1 top 16.
  currentChannel = newMIDIChannel - 1;
  assignNotesToButtons(currentStartingNote, currentStartingOctave, scales[currentScale], scaleLengths[currentScale]);
}

int getMidiChannel() {
  // +1 because the actual MIDI channel is 0 but
  // is shown as 1 to the user.
  return currentChannel + 1;
}

void onUpdateSensorMIDICC(int newMIDICC) {
  sensorMode = SENSOR_CUSTOM_CC;
  sensorMIDICC = newMIDICC;
}

int getSensorMIDICC() {
  return sensorMIDICC;
}

void onUpdateStripMIDICC(int newMIDICC) {
  stripSensorMode = STRIP_CUSTOM_CC;
  stripMIDICC = newMIDICC;
}

int getStripMIDICC() {
  return stripMIDICC;
}


NumberSelectMenu MIDIChannel = NumberSelectMenu("MIDI Channel", 12, getMidiChannel, false, onUpdateMIDIChannel, updateNumberSelectMenuScreen);
NumberSelectMenu SensorMIDICC = NumberSelectMenu("MIDI CC", 7, getSensorMIDICC, true, onUpdateSensorMIDICC, updateNumberSelectMenuScreen);
NumberSelectMenu StripMIDICC = NumberSelectMenu("MIDI CC", 7, getStripMIDICC, true, onUpdateStripMIDICC, updateNumberSelectMenuScreen);

NumberSelectMenu allNumberSelectMenus[] = {
  MIDIChannel,
  SensorMIDICC,
  StripMIDICC
};

byte menuLengths[menusLength] = {
  settingsLength,
  sensorLength,
  stripLength,
  scaleLength,
  startingNoteLength,
  startingOctaveLength,
  sensitivityLength,
  underButtonLength,
  patchLength,
  patchLength
};

void navigateToSubmenu(byte target) {
  currentMenuItem = target == 0 ? currentMenu - 1 : allMenus[target][0].getSelectedMenu();

  if (currentMenuItem < 0) {
    currentMenuItem = 0;
  }

  currentMenu = target;
}

void navigateToNumberSelectSubmenu(byte target) {
  currentNumberSelectMenu = target;
}

void endMenuInteraction() {
  assignNotesToButtons(currentStartingNote, currentStartingOctave, scales[currentScale], scaleLengths[currentScale]);
  navigateToSubmenu(0);
}

void endNumberSelectMenuInteraction()
{
  currentNumberSelectMenu = -1;
  navigateToSubmenu(0);
  drawMenu();
}
