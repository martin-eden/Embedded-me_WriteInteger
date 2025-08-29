// [me_CodecDecInt] test/demo

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_CodecDecInt.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_StreamsCollection.h>

void RunTest()
{
  /*
    Here we're testing integer encoder with output stream
    set to UART. (So we're just printing numbers.)
  */

  using
    me_CodecDecInt::Encode;

  me_StreamsCollection::TUartOutputStream UartOutput;

  Console.Print("* Encode integers");

  Console.Indent();

  {
    TUint_1 Value = 12;

    Console.Write("TUint_1 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }
  {
    TUint_2 Value = 12;

    Console.Write("TUint_2 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }
  {
    TUint_4 Value = 12;

    Console.Write("TUint_4 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }

  {
    TSint_1 Value = -12;

    Console.Write("TSint_1 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }
  {
    TSint_2 Value = -12;

    Console.Write("TSint_2 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }
  {
    TSint_4 Value = -12;

    Console.Write("TSint_4 ");
    Encode(Value, &UartOutput);
    Console.EndLine();
  }

  Console.Unindent();
}

void setup()
{
  Console.Init();

  Console.Print("[me_CodecDecInt] Okay, we are here.");
  RunTest();
  Console.Print("[me_CodecDecInt] Done.");
}

void loop()
{
}

/*
  2024 # # # # #
  2025-08-26
*/
