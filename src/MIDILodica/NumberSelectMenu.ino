const byte ASCII_OFFSET = 48;
const byte DIGITS_LENGTH = 3;

class NumberSelectMenu {
   
  public:
    byte menuNameLength;
    char* menuName;

    int (*getInitialValue)();

    // Current digit being edited.
    int selectedDigit = 0;

    // The selected value, with each digit stored separately.
    int digits[DIGITS_LENGTH];

    // Value to show to the user.
    // Length of +1 to account for null terminator.
    char digitsToShow[DIGITS_LENGTH + 1];

    // Only two digits if false.
    bool isThreeDigits;

    void (*updateScreen)(char* menuName, byte menuNameLength, char* value, byte selectedIndex, bool isMaximumThreeDigit);
    void (*onMenuConfirm)(byte newValue);

    NumberSelectMenu(char* menuName, byte menuNameLength, int (*getInitialValue)(), byte isThreeDigits, void (*onMenuConfirm)(int newValue), void (*updateScreen)(char* menuName, byte menuNameLength, char* value, byte selectedIndex, bool isMaximumThreeDigit)) {
      this -> menuName = menuName;
      this -> menuNameLength = menuNameLength;
      this -> isThreeDigits = isThreeDigits;
      this -> updateScreen = updateScreen;
      this -> onMenuConfirm = onMenuConfirm;
      this -> getInitialValue = getInitialValue;
    }

    void updatedigitsToShow() {
      digitsToShow[0] = digits[2];
      digitsToShow[1] = digits[1];
      digitsToShow[2] = digits[0];
    }

    void extractDigitsFromInitialValue() {
      int initialValue = getInitialValue();

      for (byte i = 0; i < DIGITS_LENGTH; i++) {
        byte digitSelector = 1;
        if (i > 0) {
          digitSelector = i * 10;
        }
        digits[i] = ((initialValue / digitSelector) % 10) + ASCII_OFFSET;
      }
    }

    void onLoad() {
      extractDigitsFromInitialValue();
      selectedDigit = isThreeDigits ? 2 : 1;
      updatedigitsToShow();
      updateScreen(menuName, menuNameLength, digitsToShow, selectedDigit, isThreeDigits);
    }

    char handlePressDown (char digit) {
      int newDigit = digits[selectedDigit] - 1;
      if (newDigit < ASCII_OFFSET) {
        newDigit = 9 + ASCII_OFFSET;
      }
      digits[selectedDigit] = newDigit;
    }


    char handlePressUp (int selectedDigit) {
      int newDigit = digits[selectedDigit] + 1;
      if (newDigit > 9 + ASCII_OFFSET) {
        newDigit = ASCII_OFFSET;
      }
      digits[selectedDigit] = newDigit;
    }

    void onPressDown() {
      handlePressDown(selectedDigit);
      updatedigitsToShow();
      updateScreen(menuName, menuNameLength, digitsToShow, selectedDigit, isThreeDigits);
    }


    void onPressUp() {
      handlePressUp(selectedDigit);
      updatedigitsToShow();
      updateScreen(menuName, menuNameLength, digitsToShow, selectedDigit, isThreeDigits);
    }

    void onConfirm() {
      selectedDigit--;
      if (selectedDigit < 0) {
        int newValueInt = digits[0] - ASCII_OFFSET + ((digits[1] - ASCII_OFFSET) * 10);
        if (isThreeDigits) {
          newValueInt = newValueInt + ((digits[2] - ASCII_OFFSET) * 100);
        }
        onMenuConfirm(newValueInt);
        endNumberSelectMenuInteraction();
        return;
      }

      updatedigitsToShow();
      updateScreen(menuName, menuNameLength, digitsToShow, selectedDigit, isThreeDigits);
    }

    void onCancel() {
      selectedDigit++;
      byte maxIndex = 1;
      if (isThreeDigits) {
        maxIndex = 2;
      }

      if (selectedDigit > maxIndex) {
        endNumberSelectMenuInteraction();
        return;
      }
      updatedigitsToShow();
      updateScreen(menuName, menuNameLength, digitsToShow, selectedDigit, isThreeDigits);
    }
};
