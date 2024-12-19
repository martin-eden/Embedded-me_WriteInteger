// Free functions for [me_String]

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

/*
  All integer formatting functions represent number as fixed-length
  string with leading zeroes.

  All signed integer formatting functions represent number with
  leading sign. Sign of zero is considered "+".
*/

#include <me_CodecDecInt.h>

#include <me_WorkMemory.h>
#include <me_SegmentProcessor.h>

using namespace me_CodecDecInt;

using
  me_MemorySegment::TMemorySegment;

// ( Deprecated

void me_CodecDecInt::FormatUint_4(
  TMemorySegment Result,
  TUint_4 Value
)
{
  // Zero length? Job done!
  if (Result.Size == 0)
    return;

  // Initially fill Result with "0" characters
  for (TUint_1 Offset = 0; Offset < Result.Size; ++Offset)
    Result.Bytes[Offset] = Freetown::DigToAscii(0);

  // Write digits from least to most significant
  TUint_1 Offset = Result.Size - 1;
  while (Value > 0)
  {
    TUint_1 LastDigit = Value % 10;

    Result.Bytes[Offset] = Freetown::DigToAscii(LastDigit);

    Value = Value / 10;

    // No more space to write, break
    if (Offset == 0)
      break;

    --Offset;
  }
}

void me_CodecDecInt::FormatSint_4(
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

// ) Deprecated

TBool me_CodecDecInt::Encode(TUint_1 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_U4((TUint_4) Value, 3, Op_PutByte);
}

TBool me_CodecDecInt::Encode(TUint_2 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_U4((TUint_4) Value, 5, Op_PutByte);
}

TBool me_CodecDecInt::Encode(TUint_4 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_U4((TUint_4) Value, 10, Op_PutByte);
}

TBool me_CodecDecInt::Encode(TSint_1 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_S4((TSint_4) Value, 4, Op_PutByte);
}

TBool me_CodecDecInt::Encode(TSint_2 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_S4((TSint_4) Value, 6, Op_PutByte);
}

TBool me_CodecDecInt::Encode(TSint_4 Value, TOperation Op_PutByte)
{
  return Freetown::Encode_S4((TSint_4) Value, 11, Op_PutByte);
}

/*
  2024-10 # # # #
  2024-12-19
*/
