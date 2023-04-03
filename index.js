import assert from "assert";

class StateMachine {
  constructor() {
    this.state = "A";
  }
  transitions = {
    A: {
      0: "B",
      1: "C",
      2: "D",
      3: "E",
    },
    B: {
      0: "B",
      1: "C",
      2: "D",
      3: "E",
    },
    C: {
      0: "B",
      1: "C",
      2: "D",
      3: "E",
    },
    D: {
      0: "B",
      1: "C",
      2: "D",
      3: "E",
    },
    E: {
      0: "F",
      1: "G",
      2: "H",
      3: "I",
    },
    F: {
      0: "F",
      1: "G",
      2: "H",
      3: "I",
    },
    G: {
      0: "F",
      1: "G",
      2: "H",
      3: "I",
    },
    H: {
      0: "F",
      1: "J",
      2: "H",
      3: "I",
    },
    I: {
      0: "I",
      1: "I",
      2: "I",
      3: "I",
    },
    J: {
      0: "F",
      1: "J",
      2: "H",
      3: "I",
    },
  };

  isNumber = (char) => {
    const charCode = `${char}`.charCodeAt(0);
    return charCode >= 48 && charCode <= 57;
  };

  isAlphabetical = (char) => {
    const charCode = `${char}`.charCodeAt(0);
    return charCode >= 97 && charCode <= 122;
  };

  isDot = (char) => {
    const charCode = `${char}`.charCodeAt(0);
    return charCode === 46;
  };

  isAt = (char) => {
    const charCode = `${char}`.charCodeAt(0);
    return charCode === 64;
  };

  transition(char) {
    const type = this.isNumber(char)
      ? 0
      : this.isAlphabetical(char)
      ? 1
      : this.isDot(char)
      ? 2
      : this.isAt(char)
      ? 3
      : 4;
    const nextState = this.transitions[this.state][type];
    if (nextState) {
      this.state = nextState;
    } else {
      throw new Error(`Invalid input: ${char} or invalid state: ${this.state}`);
    }
  }

  isFinal() {
    return this.state === "H" || this.state === "J";
  }
}

const isValidEmail = (input) => {
  if (!input || typeof input !== "string") {
    return false;
  }

  const stateMachine = new StateMachine();
  try {
    for (const char of input.split("")) {
      stateMachine.transition(char);
    }
    return stateMachine.isFinal();
  } catch (error) {
    return false;
  }
};

// Helyes e-mail címek
assert.strictEqual(isValidEmail("cserjesi.kristof.jeno@hallgato.sze.hu"), true);
assert.strictEqual(isValidEmail("teszt.elek@sze.hu"), true);
assert.strictEqual(isValidEmail("r0ka@koma.hu"), true);
assert.strictEqual(isValidEmail("roka@k0ma.hu"), true);
assert.strictEqual(isValidEmail("info@r0ka.k0ma.hu"), true);

// Helytelen e-mail címek
assert.strictEqual(isValidEmail("localhost"), false);
assert.strictEqual(isValidEmail("teszt.elek.hu"), false);
assert.strictEqual(isValidEmail("ab"), false);
assert.strictEqual(isValidEmail("info@r0ka.k0ma"), false);
