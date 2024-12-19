// String and integers formatting

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_String.h>

using namespace me_String;

using
  me_MemorySegment::TMemorySegment;

/*
  Return our data span
*/
TMemorySegment TString::GetData()
{
  return Data.GetData();
}

// Copy from memory segment
TBool TString::CopyFrom(
  TMemorySegment Memseg
)
{
  return Data.LoadFrom(Memseg);
}

// Copy from ASCIIZ
TBool TString::CopyFrom(
  const TAsciiz Asciiz
)
{
  return Data.LoadFrom(Asciiz);
}

// Copy from our specie
TBool TString::CopyFrom(
  TString String
)
{
  return Data.LoadFrom(&String.Data);
}

/*
  2024-10 # # # #
  2024-12-19
*/
