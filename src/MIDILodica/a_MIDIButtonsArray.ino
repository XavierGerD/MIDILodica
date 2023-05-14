const byte debounceDelay = 10;
unsigned long lastDebounce = 0;

bool pressedNavButtonStates[] = { HIGH, HIGH, HIGH, HIGH, HIGH };

void playMIDINotes() {
  for (byte i = 0; i < rowsLength; i++) {
    pinMode(rows[i], OUTPUT);
    digitalWrite(rows[i], LOW);

    for (byte j = 0; j < columnsLength; j++) {
      bool pressedButtonState = digitalRead(columns[j]);

      // Only detect state changes.
      if (pressedButtonState == noteButtons[i][j]->lastState || (millis() - lastDebounce) <= debounceDelay) {
        continue;
      }


      if (!pressedButtonState) {
        noteButtons[i][j]->sendNote();
      }

      if (pressedButtonState) {
        noteButtons[i][j]->cancelNote();
      }


      noteButtons[i][j]->lastState = pressedButtonState;
      lastDebounce = millis();
    }

    if ((millis() - lastDebounce) > debounceDelay) {
      bool pressedButtonState = digitalRead(C8);
      if (pressedButtonState != pressedNavButtonStates[i]) {
        handleNavButtons(i, pressedButtonState);
        lastDebounce = millis();
      }

    }

    pinMode(rows[i], INPUT);
  }
}
