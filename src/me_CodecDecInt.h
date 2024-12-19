// Integer <-> ASCII coder/decoder

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

/*
  All integer encoding functions represent number as fixed-length
  string with leading zeroes.

  All signed integer formatting functions represent number with
  leading sign. Sign of zero is considered "+".
*/

#include <me_BaseTypes.h>
#include <me_MemorySegment.h>

namespace me_CodecDecInt
{
  // ( Deprecated. To be eliminated

  // Format TUint_4 in given length with zero padding
  void FormatUint_4(
    me_MemorySegment::TMemorySegment Result,
    TUint_4 Value
  );

  // Format TSint_4 in given length with zero padding and sign
  void FormatSint_4(
    me_MemorySegment::TMemorySegment Result,
    TSint_4 Value
  );

  // ) Deprecated

  // Encode integer
  TBool Encode(TUint_1 Value, TOperation Op_PutByte);
  TBool Encode(TUint_2 Value, TOperation Op_PutByte);
  TBool Encode(TUint_4 Value, TOperation Op_PutByte);
  TBool Encode(TSint_1 Value, TOperation Op_PutByte);
  TBool Encode(TSint_2 Value, TOperation Op_PutByte);
  TBool Encode(TSint_4 Value, TOperation Op_PutByte);

  namespace Freetown
  {
    // Convert decimal digit to ASCII. No checks
    TUint_1 DigToAscii(
      TUint_1 Digit
    );

    // Reverse data in workmem segment
    void ReverseSegmentData(
      me_MemorySegment::TMemorySegment Data
    );

    // Encode TUint_4 to given workmem segment. Zero padding
    TBool Encode_U4(
      TUint_4 Value,
      TUint_1 OutputLength,
      TOperation Op_PutByte
    );

    // Encode TSint_4 to workmem segment. Leading sign, zero padding
    TBool Encode_S4(
      TSint_4 Value,
      TUint_1 OutputLength,
      TOperation Op_PutByte
    );
  }
}

/*
  2024-10 # # # #
  2024-12-19
*/
