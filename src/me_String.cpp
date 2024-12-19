// Free functions for [me_String]

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_String.h>

using namespace me_String;

using
  me_MemorySegment::TMemorySegment;

/*
  All integer formatting functions represent number as fixed-length
  string with leading zeroes.

  All signed integer formatting functions represent number with
  leading sign. Sign of zero is considered "+".
*/

// ( TString

/*
  Return our data span
*/
TMemorySegment TString::GetData()
{
  return Data.GetData();
}

// Copy from memory segment
TBool TString::CopyFrom(
  TMemorySegment Memseg
)
{
  return Data.LoadFrom(Memseg);
}

// Copy from ASCIIZ
TBool TString::CopyFrom(
  const TAsciiz Asciiz
)
{
  return Data.LoadFrom(Asciiz);
}

// Copy from our specie
TBool TString::CopyFrom(
  TString String
)
{
  return Data.LoadFrom(&String.Data);
}

// ) TString

/*
  Check that given number falls in decimal digits range [0, 9]
*/
TBool IsDigit(TUint_1 Value)
{
  return (Value <= 9);
}

/*
  Return ASCII value for digit

  For bad input returns "?" character.
*/
TUint_1 DigToAscii(TUint_1 Digit)
{
  if (!IsDigit(Digit))
    return '?';

  return ('0' + Digit); // <3 U C
}

/*
  TUint_4 to ASCII

  Zeroes padding.

  Arguments

    TMemorySegment Result

      We will write characters here. Segment should describe
      valid memory to which we can write.

    TUint_4 Value

      Value we're representing
*/
void me_String::Freetown::FormatUint_4(
  TMemorySegment Result,
  TUint_4 Value
)
{
  // Zero length? Job done!
  if (Result.Size == 0)
    return;

  // Initially fill Result with "0" characters
  for (TUint_1 Offset = 0; Offset < Result.Size; ++Offset)
    Result.Bytes[Offset] = DigToAscii(0);

  // Write digits from least to most significant
  TUint_1 Offset = Result.Size - 1;
  while (Value > 0)
  {
    TUint_1 LastDigit = Value % 10;

    Result.Bytes[Offset] = DigToAscii(LastDigit);

    Value = Value / 10;

    // No more space to write, break
    if (Offset == 0)
      break;

    --Offset;
  }
}

/*
  TSint_4 to ASCII

  Zeroes padding, "+"/"-" sign. Zero has sign "+".
*/
void me_String::Freetown::FormatSint_4(
  TMemorySegment Result,
  TSint_4 Value
)
{
  if (Result.Size == 0)
    return;

  TBool IsNegative = (Value < 0);

  TUint_4 Uint_4_Value;

  if (IsNegative)
    Uint_4_Value = -Value;
  else
    Uint_4_Value = Value;

  FormatUint_4(Result, Uint_4_Value);

  TUnit SignChar;
  if (IsNegative)
    SignChar = '-';
  else
    SignChar = '+';

  Result.Bytes[0] = SignChar;
}

/*
  2024-10 # # # #
  2024-12-19
*/
