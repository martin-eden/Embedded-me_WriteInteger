// Interface functions to emit integer as decimal ASCII

/*
  Author: Martin Eden
  Last mod.: 2025-08-26
*/

#include <me_CodecDecInt.h>

#include <me_BaseTypes.h>
#include <me_Streams.h>

using namespace me_CodecDecInt;

TBool me_CodecDecInt::Encode(
  TUint_1 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_U4((TUint_4) Value, 3, OutputStream);
}

TBool me_CodecDecInt::Encode(
  TUint_2 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_U4((TUint_4) Value, 5, OutputStream);
}

TBool me_CodecDecInt::Encode(
  TUint_4 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_U4((TUint_4) Value, 10, OutputStream);
}

TBool me_CodecDecInt::Encode(
  TSint_1 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_S4((TSint_4) Value, 4, OutputStream);
}

TBool me_CodecDecInt::Encode(
  TSint_2 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_S4((TSint_4) Value, 6, OutputStream);
}

TBool me_CodecDecInt::Encode(
  TSint_4 Value,
  me_Streams::IOutputStream * OutputStream
)
{
  return Freetown::Encode_S4((TSint_4) Value, 11, OutputStream);
}

/*
  2024 # # # # #
  2025-08-25
  2025-08-26
*/
