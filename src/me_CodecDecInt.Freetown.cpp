// Core functions for integer-to-ascii coder

/*
  Author: Martin Eden
  Last mod.: 2025-08-30
*/

#include <me_CodecDecInt.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_WorkMemory.h>
#include <me_StreamTools.h>
#include <me_StreamsCollection.h>

using namespace me_CodecDecInt;

/*
  Convert integer in [0, 9] to ASCII value

  It's internal function. We're not checking input range
  because calling code uses (should use) value in [0, 9]
  by design.
*/
TUint_1 DigToAscii(
  TUint_1 Digit
)
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
void ReverseSegmentData(
  TAddressSegment Data
)
{
  using
    me_WorkMemory::GetByteFrom,
    me_WorkMemory::SetByteAt;

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
    GetByteFrom(&LeftByte, LeftByteAddr);
    GetByteFrom(&RightByte, RightByteAddr);

    SetByteAt(LeftByteAddr, RightByte);
    SetByteAt(RightByteAddr, LeftByte);

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
  IOutputStream * OutputStream
)
{
  // Ten decimal digits are required to represent 2^32
  const TUint_1 BuffSize = 10;
  TUint_1 Buffer[BuffSize];
  TAddressSegment BuffSeg =
    { .Addr = (TAddress) &Buffer, .Size = OutputLength };

  TAddressIterator Rator;
  TAddress Addr;

  me_StreamsCollection::TWorkmemInputStream BufferStream;

  // Encoding in more number of digits than required is discouraged
  if (OutputLength > BuffSize)
    return false;

  if (!Rator.Init(BuffSeg))
    return false;

  // Write digits from least to most significant
  while (Rator.GetNextAddr(&Addr))
  {
    me_WorkMemory::SetByteAt(Addr, DigToAscii(Value % 10));
    Value = Value / 10;
  }

  /*
    It was nice and simple. But convention requires that number
    123 should be stored like (0 0 1 2 3), not (3 2 1 0 0) that
    we have now.
  */
  ReverseSegmentData(BuffSeg);

  if (!BufferStream.Init(BuffSeg))
    return false;

  // "Print" buffer (copy it)
  return me_StreamTools::CopyStreamTo(&BufferStream, OutputStream);
}

/*
  Encode TSint_4 to ASCII in work memory

  Leading sign (zero has "+" sign). Zero padding.

  Wrapper for Encode_U4().
*/
TBool me_CodecDecInt::Freetown::Encode_S4(
  TSint_4 Value,
  TUint_1 OutputLength,
  IOutputStream * OutputStream
)
{
  if (OutputLength == 0)
    return false;

  TBool IsNegative = (Value < 0);
  TUint_1 SignChar = IsNegative ? '-' : '+';

  if (IsNegative)
    Value = -Value;

  OutputStream->Write(SignChar);

  return Encode_U4(Value, OutputLength - 1, OutputStream);
}

/*
  2024-10 # # # #
  2024-12-19
*/
