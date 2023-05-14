const byte chromatic[] = {1};
const byte ionian[] = {2, 2, 1, 2, 2, 2, 1};
const byte dorian[] = {2, 1, 2, 2, 2, 1, 2};
const byte phrygian[] = {1, 2, 2, 2, 1, 2, 2};
const byte lydian[] = {2, 2, 2, 1, 2, 2, 1};
const byte mixolydian[] = {2, 2, 1, 2, 2, 1, 2};
const byte aeolian[] = {2, 1, 2, 2, 1, 2};
const byte locrian[] = {1, 2, 2, 2, 1, 2, 2};
const byte melodicMinor[] = {2, 1, 2, 2, 1, 3, 1};
const byte pentatonicMajor[] = {2, 2, 3, 2, 3};
const byte pentatonicMinor[] = {3, 2, 2, 3, 2};
const byte wholeTone[] = {2};
const byte octatonic21[] = {2, 1};
const byte octatonic12[] = {1, 2};

const byte *scales[] = {
  chromatic,
  ionian,
  dorian,
  phrygian,
  lydian,
  mixolydian,
  aeolian,
  locrian,
  melodicMinor,
  pentatonicMajor,
  pentatonicMinor,
  wholeTone,
  octatonic12,
  octatonic21,
};

byte scaleLengths[] = {1, 7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 1, 2, 2 };
