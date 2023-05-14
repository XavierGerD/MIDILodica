#include <EEPROM.h>

void savePatchInternal(byte startingLocation) {
  byte startingAddress = startingLocation * settingsLength;
  for (byte i = 0; i < settingsLength; i++) {
    byte currentAddress = i + startingAddress;
    switch (i) {
      case 0:
        EEPROM.write(currentAddress, sensorMode);
        break;
      case 1:
        EEPROM.write(currentAddress, underButtonMode);
        break;
      case 2:
        EEPROM.write(currentAddress, currentScale);
        break;
      case 3:
        EEPROM.write(currentAddress, currentStartingNote);
        break;
      case 4:
        EEPROM.write(currentAddress, currentStartingOctave);
        break;
      case 5:
        EEPROM.write(currentAddress, currentSensitivity);
        break;
      case 6:
        EEPROM.write(currentAddress, stripSensorMode);
        break;
      case 7:
        EEPROM.write(currentAddress, currentChannel);
        break;
      case 8:
        EEPROM.write(currentAddress, sensorMIDICC);
        break;
      case 9:
        EEPROM.write(currentAddress, stripMIDICC);
        break;
      default:
        break;
    }
  }
}

void loadProgramInternal(byte startingLocation) {
  byte startingAddress = startingLocation * settingsLength;
  for (byte i = 0; i < settingsLength; i++) {
    byte currentAddress = i + startingAddress;
    byte EEPROMVal = EEPROM.read(currentAddress);
    switch (i) {
      case 0:
        sensorMode = EEPROMVal;
        break;
      case 1:
        underButtonMode = EEPROMVal;
        break;
      case 2:
        currentScale = EEPROMVal;
        break;
      case 3:
        currentStartingNote = EEPROMVal;
        break;
      case 4:
        currentStartingOctave = EEPROMVal;
        break;
      case 5:
        currentSensitivity = EEPROMVal;
        break;
      case 6:
        stripSensorMode = EEPROMVal;
        break;
      case 7:
        currentChannel = EEPROMVal;
        break;
      case 8:
        sensorMIDICC = EEPROMVal;
        break;
      case 9:
        stripMIDICC = EEPROMVal;
        break;
    }
  }
}
