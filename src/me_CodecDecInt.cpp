// Free functions for [me_String]

/*
  Author: Martin Eden
  Last mod.: 2025-08-25
*/

#include <me_CodecDecInt.h>

using namespace me_CodecDecInt;

TBool me_CodecDecInt::Encode(
  TUint_1 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_U4((TUint_4) Value, 3, Op_PutByte);
}

TBool me_CodecDecInt::Encode(
  TUint_2 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_U4((TUint_4) Value, 5, Op_PutByte);
}

TBool me_CodecDecInt::Encode(
  TUint_4 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_U4((TUint_4) Value, 10, Op_PutByte);
}

TBool me_CodecDecInt::Encode(
  TSint_1 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_S4((TSint_4) Value, 4, Op_PutByte);
}

TBool me_CodecDecInt::Encode(
  TSint_2 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_S4((TSint_4) Value, 6, Op_PutByte);
}

TBool me_CodecDecInt::Encode(
  TSint_4 Value,
  TFixedOperation Op_PutByte
)
{
  return Freetown::Encode_S4((TSint_4) Value, 11, Op_PutByte);
}

/*
  2024 # # # # #
  2025-08-25
*/
