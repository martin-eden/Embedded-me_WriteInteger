// Interface functions to emit integer as decimal ASCII

/*
  Author: Martin Eden
  Last mod.: 2025-09-06
*/

#include <me_WriteInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_WriteInteger;

TBool me_WriteInteger::Write_U1(
  TUint_1 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_U4((TUint_4) Value, 3, OutputStream);
}

TBool me_WriteInteger::Write_U2(
  TUint_2 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_U4((TUint_4) Value, 5, OutputStream);
}

TBool me_WriteInteger::Write_U4(
  TUint_4 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_U4((TUint_4) Value, 10, OutputStream);
}

TBool me_WriteInteger::Write_S1(
  TSint_1 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_S4((TSint_4) Value, 4, OutputStream);
}

TBool me_WriteInteger::Write_S2(
  TSint_2 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_S4((TSint_4) Value, 6, OutputStream);
}

TBool me_WriteInteger::Write_S4(
  TSint_4 Value,
  IOutputStream * OutputStream
)
{
  return Freetown::Write_S4((TSint_4) Value, 11, OutputStream);
}

/*
  2024 # # # # #
  2025 # #
*/
