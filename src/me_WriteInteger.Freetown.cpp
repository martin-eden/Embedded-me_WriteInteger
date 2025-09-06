// Core functions for integer-to-ascii coder

/*
  Author: Martin Eden
  Last mod.: 2025-09-06
*/

#include <me_WriteInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_WriteInteger;

// [Internal] Convert integer in [0, 9] to ASCII value
TUint_1 DigToAscii(
  TUint_1 Digit
)
{
  return Digit + '0';
}

// [Internal] Write digit to stream
void PrintDigit(
  TUint_1 Digit,
  IOutputStream * OutputStream
)
{
  OutputStream->Write(DigToAscii(Digit));
}

/*
  [Core] Write TUint_4 as ASCII decimal to stream
*/
TBool me_WriteInteger::Freetown::Write_U4(
  TUint_4 Value,
  TUint_1 OutputLength,
  IOutputStream * OutputStream
)
{
  // Number of decimal digits required to represent 2^32
  const TUint_1 MaxNumDigits = 10;
  const TUint_4 MaxDigit = 9;

  TUint_1 NumDigitsUsed;
  TUint_4 ExtractrionBase;
  TUint_1 Digit;

  if (OutputLength > MaxNumDigits)
    return false;

  NumDigitsUsed = 1;
  ExtractrionBase = 1;

  while (NumDigitsUsed < OutputLength)
  {
    ExtractrionBase = ExtractrionBase * 10;
    NumDigitsUsed = NumDigitsUsed + 1;
  }

  // Fail when output length is too short for value
  if (Value / ExtractrionBase > MaxDigit)
    return false;

  while (NumDigitsUsed > 0)
  {
    Digit = Value / ExtractrionBase;

    PrintDigit(Digit, OutputStream);

    Value = Value - (Digit * ExtractrionBase);
    ExtractrionBase = ExtractrionBase / 10;
    NumDigitsUsed = NumDigitsUsed - 1;
  }

  return true;
}

/*
  Write TSint_4 as ASCII decimal to stream
*/
TBool me_WriteInteger::Freetown::Write_S4(
  TSint_4 Value_S4,
  TUint_1 OutputLength,
  IOutputStream * OutputStream
)
{
  TUint_4 Value_U4;

  if (Value_S4 < 0)
  {
    OutputStream->Write('-');
    Value_U4 = -Value_S4;
  }
  else
  {
    OutputStream->Write('+');
    Value_U4 = Value_S4;
  }

  if (OutputLength == 0)
    return false;

  return Write_U4(Value_U4, OutputLength - 1, OutputStream);
}

/*
  2024 # # # # #
  2025-09-06
*/
