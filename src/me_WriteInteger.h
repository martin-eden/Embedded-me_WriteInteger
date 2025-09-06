// Integer to decimal ASCII coder

/*
  Author: Martin Eden
  Last mod.: 2025-09-06
*/

/*
  All integer encoding functions represent integer as fixed-length
  string with leading zeroes.

  All signed integer formatting functions represent integer with
  leading sign. Sign of zero is "+".
*/

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_WriteInteger
{
  // (  Write integer as decimal ASCII to output stream
  TBool Write_U1(TUint_1 Value, IOutputStream * OutputStream);
  TBool Write_U2(TUint_2 Value, IOutputStream * OutputStream);
  TBool Write_U4(TUint_4 Value, IOutputStream * OutputStream);

  TBool Write_S1(TSint_1 Value, IOutputStream * OutputStream);
  TBool Write_S2(TSint_2 Value, IOutputStream * OutputStream);
  TBool Write_S4(TSint_4 Value, IOutputStream * OutputStream);
  // )

  // [Core]
  namespace Freetown
  {
    TBool Write_U4(
      TUint_4 Value,
      TUint_1 OutputLength,
      IOutputStream * OutputStream
    );

    TBool Write_S4(
      TSint_4 Value,
      TUint_1 OutputLength,
      IOutputStream * OutputStream
    );
  }
}

/*
  2024 # # # # #
  2025 # # #
  2025-09-06
*/
