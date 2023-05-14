byte velocity = 127;

class NoteButton {
  public:
    NoteButton(byte row, byte col, byte note) {
      this -> note = note;
    }
    byte note;
    byte lastPlayedNote;
    byte channel = 0;
    boolean lastState = 1;

    void sendNote() {
      midiEventPacket_t noteOn = {0x09, 0x90 | channel, note, velocity};
      MidiUSB.sendMIDI(noteOn);
      MidiUSB.flush();
    }

    void cancelNote() {
      midiEventPacket_t noteOff = {0x08, 0x80 | channel, note, velocity};
      MidiUSB.sendMIDI(noteOff);
      MidiUSB.flush();
    }

    void updateChannel(byte newChannel) {
      channel = newChannel;
    }

    void changeButtonNote(byte newNote) {
      // Used for octave changes mainly. Rearticulates the note if it is changed while playing.
      if (!lastState) {
        cancelNote();
        note = newNote;
        sendNote();
      } else {
        note = newNote;
      }
    }
};
