// String and integers formatting

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_BaseTypes.h>
#include <me_MemorySegment.h>

namespace me_CodecDecInt
{
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
}

/*
  2024-10 # # # #
  2024-12-19
*/
