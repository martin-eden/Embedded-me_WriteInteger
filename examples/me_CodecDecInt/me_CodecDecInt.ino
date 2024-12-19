// [me_CodecDecInt] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-12-19
*/

#include <me_CodecDecInt.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_Uart.h>
#include <me_UartSpeeds.h>
#include <me_MemorySegment.h>

void setup()
{
  me_Uart::Init(me_UartSpeeds::Bps_115k);

  Console.Print("[me_CodecDecInt] Okay, we are here.");
  RunTest();
  Console.Print("[me_CodecDecInt] Done.");
}

void loop()
{
}

// --

void RunTest()
{
  using
    me_CodecDecInt::Encode;

  Console.Print("* Encoding integers");

  Console.Indent();

  {
    TUint_1 Value = 12;

    Console.Write("TUint_1 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }
  {
    TUint_2 Value = 12;

    Console.Write("TUint_2 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }
  {
    TUint_4 Value = 12;

    Console.Write("TUint_4 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }

  {
    TSint_1 Value = -12;

    Console.Write("TSint_1 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }
  {
    TSint_2 Value = -12;

    Console.Write("TSint_2 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }
  {
    TSint_4 Value = -12;

    Console.Write("TSint_4 ");
    Encode(Value, me_Uart::Op_PutByte);
    Console.EndLine();
  }

  Console.Unindent();
}

/*
  2024-10 # # # #
  2024-12-19
*/
