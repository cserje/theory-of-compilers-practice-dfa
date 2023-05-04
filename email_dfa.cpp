#include <iostream>

using namespace std;

class IllegalInput
{
};

class Email
{
  char state;

private:
  bool isNumber(char c)
  {
    return (int)c >= 48 && (int)c <= 57;
  };

  bool isAlphabetical(char c)
  {
    return (int)c >= 97 && (int)c <= 122;
  };

  bool isDot(char c)
  {
    return (int)c == 46;
  };

  bool isAt(char c)
  {
    return (int)c == 64;
  };
  void A(char c)
  {
    if (isNumber(c))
    {
      state = 'B';
    }
    else if (isAlphabetical(c))
    {
      state = 'C';
    }
    else if (isDot(c))
    {
      state = 'D';
    }
    else if (isAt(c))
    {
      state = 'E';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void B(char c)
  {
    if (isNumber(c))
    {
      state = 'B';
    }
    else if (isAlphabetical(c))
    {
      state = 'C';
    }
    else if (isDot(c))
    {
      state = 'D';
    }
    else if (isAt(c))
    {
      state = 'E';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void C(char c)
  {
    if (isNumber(c))
    {
      state = 'B';
    }
    else if (isAlphabetical(c))
    {
      state = 'C';
    }
    else if (isDot(c))
    {
      state = 'D';
    }
    else if (isAt(c))
    {
      state = 'E';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void D(char c)
  {
    if (isNumber(c))
    {
      state = 'B';
    }
    else if (isAlphabetical(c))
    {
      state = 'C';
    }
    else if (isDot(c))
    {
      state = 'D';
    }
    else if (isAt(c))
    {
      state = 'E';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void E(char c)
  {
    if (isNumber(c))
    {
      state = 'F';
    }
    else if (isAlphabetical(c))
    {
      state = 'G';
    }
    else if (isDot(c))
    {
      state = 'H';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void F(char c)
  {
    if (isNumber(c))
    {
      state = 'F';
    }
    else if (isAlphabetical(c))
    {
      state = 'G';
    }
    else if (isDot(c))
    {
      state = 'H';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void G(char c)
  {
    if (isNumber(c))
    {
      state = 'F';
    }
    else if (isAlphabetical(c))
    {
      state = 'G';
    }
    else if (isDot(c))
    {
      state = 'H';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void H(char c)
  {
    if (isNumber(c))
    {
      state = 'F';
    }
    else if (isAlphabetical(c))
    {
      state = 'J';
    }
    else if (isDot(c))
    {
      state = 'H';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void I(char c)
  {
    if (isNumber(c))
    {
      state = 'I';
    }
    else if (isAlphabetical(c))
    {
      state = 'I';
    }
    else if (isDot(c))
    {
      state = 'I';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }
  void J(char c)
  {
    if (isNumber(c))
    {
      state = 'F';
    }
    else if (isAlphabetical(c))
    {
      state = 'J';
    }
    else if (isDot(c))
    {
      state = 'H';
    }
    else if (isAt(c))
    {
      state = 'I';
    }
    else
    {
      throw IllegalInput();
    }
  }

public:
  bool isValid(const string input)
  {
    state = 'A';
    cout << state;
    for (int i = 0; i < input.size(); i++)
    {
      cout << " --" << input[i] << "--> ";
      switch (state)
      {
      case 'A':
        A(input[i]);
        break;
      case 'B':
        B(input[i]);
        break;
      case 'C':
        C(input[i]);
        break;
      case 'D':
        D(input[i]);
        break;
      case 'E':
        E(input[i]);
        break;
      case 'F':
        F(input[i]);
        break;
      case 'G':
        G(input[i]);
        break;
      case 'H':
        H(input[i]);
        break;
      case 'I':
        I(input[i]);
        break;
      case 'J':
        J(input[i]);
        break;
      }
      cout << state << '\n';
      if (i < input.size() - 1)
      {
        cout << state;
      }
    }
    return state == 'H' || state == 'J';
  }
};

int main()
{
  string s;
  cin >> s;
  try
  {
    if (Email().isValid(s))
    {
      cout << "Accepted.\n";
    }
    else
    {
      cout << "Not accepted.\n";
    }
  }
  catch (IllegalInput)
  {
    cout << "Not accepted.\n";
  }
  return 0;
}

// ---------------- Accepted ----------------
/*
Input:
  cserjesi.kristof.jeno@hallgato.sze.hu
Output:
    A --c--> C
    C --s--> C
    C --e--> C
    C --r--> C
    C --j--> C
    C --e--> C
    C --s--> C
    C --i--> C
    C --.--> D
    D --k--> C
    C --r--> C
    C --i--> C
    C --s--> C
    C --t--> C
    C --o--> C
    C --f--> C
    C --.--> D
    D --j--> C
    C --e--> C
    C --n--> C
    C --o--> C
    C --@--> E
    E --h--> G
    G --a--> G
    G --l--> G
    G --l--> G
    G --g--> G
    G --a--> G
    G --t--> G
    G --o--> G
    G --.--> H
    H --s--> J
    J --z--> J
    J --e--> J
    J --.--> H
    H --h--> J
    J --u--> J
    Accepted.

Input:
    teszt.elek@sze.hu
Output:
    A --t--> C
    C --e--> C
    C --s--> C
    C --z--> C
    C --t--> C
    C --.--> D
    D --e--> C
    C --l--> C
    C --e--> C
    C --k--> C
    C --@--> E
    E --s--> G
    G --z--> G
    G --e--> G
    G --.--> H
    H --h--> J
    J --u--> J
    Accepted.

Input:
    r0ka@koma.hu
Output:
    A --r--> C
    C --0--> B
    B --k--> C
    C --a--> C
    C --@--> E
    E --k--> G
    G --o--> G
    G --m--> G
    G --a--> G
    G --.--> H
    H --h--> J
    J --u--> J
    Accepted.
*/

// ---------------- Not accepted ----------------
/*
Input:
    localhost
Output:
    A --l--> C
    C --o--> C
    C --c--> C
    C --a--> C
    C --l--> C
    C --h--> C
    C --o--> C
    C --s--> C
    C --t--> C
    Not accepted.

Input:
    teszt.elek.hu
Output:
    A --t--> C
    C --e--> C
    C --s--> C
    C --z--> C
    C --t--> C
    C --.--> D
    D --e--> C
    C --l--> C
    C --e--> C
    C --k--> C
    C --.--> D
    D --h--> C
    C --u--> C
    Not accepted.

Input:
    info@r0ka.k0ma
Output:
    A --i--> C
    C --n--> C
    C --f--> C
    C --o--> C
    C --@--> E
    E --r--> G
    G --0--> F
    F --k--> G
    G --a--> G
    G --.--> H
    H --k--> J
    J --0--> F
    F --m--> G
    G --a--> G
    Not accepted.
*/