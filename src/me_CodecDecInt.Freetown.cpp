// Core functions for integer-to-ascii codec

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_CodecDecInt.h>

#include <me_WorkMemory.h>
#include <me_SegmentProcessor.h>

using namespace me_CodecDecInt;

using
  me_MemorySegment::TMemorySegment;

/*
  Convert integer in [0, 9] to ASCII value

  It's internal function. We're not checking input range
  because calling code uses (should use) value in [0, 9]
  by design.
*/
TUint_1 Freetown::DigToAscii(TUint_1 Digit)
{
  return '0' + Digit;
}

/*
  Reverse segment data

  Only practical use of this function I've found in my life
  is to reverse parsed decimal number data.

  On higher levels reverse can be achieved by adding data to
  stack instead of queue.
*/
void Freetown::ReverseSegmentData(
  TMemorySegment Data
)
{
  using
    me_WorkMemory::GetByte,
    me_WorkMemory::SetByte;

  if (Data.Size == 0)
    return;

  TAddress LeftmostByteAddr = Data.Addr;
  TAddress RightmostByteAddr = Data.Addr + Data.Size - 1;

  TAddress LeftByteAddr = LeftmostByteAddr;
  TAddress RightByteAddr = RightmostByteAddr;
  TUint_1 LeftByte = 0;
  TUint_1 RightByte = 0;

  while (LeftByteAddr < RightByteAddr)
  {
    GetByte(&LeftByte, LeftByteAddr);
    GetByte(&RightByte, RightByteAddr);

    SetByte(RightByte, LeftByteAddr);
    SetByte(LeftByte, RightByteAddr);

    ++LeftByteAddr;
    --RightByteAddr;
  }
}

/*
  Encode TUint_4 to ASCII in work memory

  Core function.
*/
TBool me_CodecDecInt::Freetown::Encode_U4(
  TUint_4 Value,
  TUint_1 OutputLength,
  TOperation Op_PutByte
)
{
  using
    me_MemorySegment::Freetown::FromAddrSize,
    me_MemorySegment::TMemorySegment,
    me_MemorySegment::TSegmentIterator,
    Freetown::DigToAscii,
    me_WorkMemory::SetByte,
    Freetown::ReverseSegmentData,
    me_SegmentProcessor::CopyFrom;

  // "10" - 10 decimal digits are required to represent 2^32
  const TUint_1 BuffSize = 10;
  TUint_1 Buffer[BuffSize];
  TMemorySegment BuffSeg = FromAddrSize((TAddress) &Buffer, OutputLength);

  TSegmentIterator Rator;
  TAddress Addr;

  // Encoding in more number of digits than required is discouraged
  if (OutputLength > BuffSize)
    return false;

  if (!Rator.Init(BuffSeg))
    return false;

  // Write digits from least to most significant
  while (Rator.GetNext(&Addr))
  {
    SetByte(DigToAscii(Value % 10), Addr);
    Value = Value / 10;
  }

  /*
    It was nice and simple. But convention requires that number
    123 should be stored like (0 0 1 2 3), not (3 2 1 0 0) that
    we have now.
  */
  ReverseSegmentData(BuffSeg);

  // "Print" buffer (copy it)
  return
    CopyFrom(BuffSeg, BuffSeg, me_WorkMemory::Op_GetByte, Op_PutByte);
}

/*
  Encode TSint_4 to ASCII in work memory

  Leading sign (zero has "+" sign). Zero padding.

  Wrapper for Encode_U4().
*/
TBool me_CodecDecInt::Freetown::Encode_S4(
  TSint_4 Value,
  TUint_1 OutputLength,
  TOperation Op_PutByte
)
{
  if (OutputLength == 0)
    return false;

  TBool IsNegative = (Value < 0);
  TUint_1 SignChar = IsNegative ? '-' : '+';
  TAddress SignCharAddr = (TAddress) &SignChar;

  if (IsNegative)
    Value = -Value;

  Op_PutByte(SignCharAddr, SignCharAddr);

  return Encode_U4(Value, OutputLength - 1, Op_PutByte);
}

/*
  2024-10 # # # #
  2024-12-19
*/
