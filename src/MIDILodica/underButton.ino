void handleSustain() {
  byte sustainValue =  pressedNavButtonStates[0] ? 64 : 0;
  midiEventPacket_t sutainPacket = {0x0B, 0xB0 | currentChannel, 64, sustainValue};
  MidiUSB.sendMIDI(sutainPacket);
  MidiUSB.flush();
}

void handleUnderButtonModes(bool pressedButtonState) {
  byte newOctave;
  switch (underButtonMode) {
    case UNDER_BUTTON_8VA_UP:
      newOctave = !pressedButtonState ? currentStartingOctave + 1 : currentStartingOctave;
      assignNotesToButtons(currentStartingNote, newOctave, scales[currentScale], scaleLengths[currentScale]);
      break;
    case UNDER_BUTTON_8VA_DOWN:
      newOctave = !pressedButtonState ? currentStartingOctave - 1 : currentStartingOctave;
      assignNotesToButtons(currentStartingNote, newOctave, scales[currentScale], scaleLengths[currentScale]);
      break;
    case UNDER_BUTTON_SUSTAIN:
      handleSustain();
      break;
  }
}
