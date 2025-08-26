// Integer to decimal ASCII coder

/*
  Author: Martin Eden
  Last mod.: 2025-08-26
*/

/*
  All integer encoding functions represent number as fixed-length
  string with leading zeroes.

  All signed integer formatting functions represent number with
  leading sign. Sign of zero is "+".
*/

#include <me_BaseTypes.h>
#include <me_Streams.h>

namespace me_CodecDecInt
{
  // ( Integer encoders
  TBool Encode(TUint_1 Value, me_Streams::IOutputStream * OutputStream);
  TBool Encode(TUint_2 Value, me_Streams::IOutputStream * OutputStream);
  TBool Encode(TUint_4 Value, me_Streams::IOutputStream * OutputStream);

  TBool Encode(TSint_1 Value, me_Streams::IOutputStream * OutputStream);
  TBool Encode(TSint_2 Value, me_Streams::IOutputStream * OutputStream);
  TBool Encode(TSint_4 Value, me_Streams::IOutputStream * OutputStream);
  // )

  // Core functions
  namespace Freetown
  {
    // Encode TUint_4 to given workmem segment. Zero padding
    TBool Encode_U4(
      TUint_4 Value,
      TUint_1 OutputLength,
      me_Streams::IOutputStream * OutputStream
    );

    // Encode TSint_4 to workmem segment. Leading sign, zero padding
    TBool Encode_S4(
      TSint_4 Value,
      TUint_1 OutputLength,
      me_Streams::IOutputStream * OutputStream
    );
  }
}

/*
  2024 # # # # #
  2025-08-25
  2025-08-26
*/
