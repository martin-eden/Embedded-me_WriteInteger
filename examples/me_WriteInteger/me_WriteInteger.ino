// [me_WriteInteger] Test

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

#include <me_WriteInteger.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_Console.h>
#include <me_StreamsCollection.h>

void Test_U1(
  TUint_1 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TUint_1 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void Test_U2(
  TUint_2 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TUint_2 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void Test_U4(
  TUint_4 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TUint_4 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void Test_S1(
  TSint_1 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TSint_1 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void Test_S2(
  TSint_2 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TSint_2 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void Test_S4(
  TSint_4 Value,
  IOutputStream * OutputSream
)
{
  Console.Write("TSint_4 ");
  me_WriteInteger::Encode(Value, OutputSream);
  Console.EndLine();
}

void RunTests()
{
  me_StreamsCollection::TUartOutputStream OutputSream;

  OutputSream.Init();

  Test_U1(TUint_1_Max, &OutputSream);
  Test_U2(TUint_2_Max, &OutputSream);
  Test_U4(TUint_4_Max, &OutputSream);

  Test_S1(TSint_1_Min, &OutputSream);
  Test_S1(TSint_1_Max, &OutputSream);

  Test_S2(TSint_2_Min, &OutputSream);
  Test_S2(TSint_2_Max, &OutputSream);

  Test_S4(TSint_4_Min, &OutputSream);
  Test_S4(TSint_4_Max, &OutputSream);
}

void setup()
{
  Console.Init();

  Console.Print("( [me_WriteInteger] test");

  RunTests();

  Console.Print(") Done");
}

void loop()
{
}

/*
  2024 # # # # #
  2025-08-26
*/
