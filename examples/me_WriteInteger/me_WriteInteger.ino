// [me_WriteInteger] Test

/*
  Author: Martin Eden
  Last mod.: 2025-09-05
*/

#include <me_WriteInteger.h>

#include <me_BaseTypes.h>
#include <me_Console.h>

void Test_U1(
  TUint_1 Value
)
{
  Console.Write("TUint_1 ");
  me_WriteInteger::Write_U1(Value, Console.GetOutputStream());
  Console.EndLine();
}

void Test_U2(
  TUint_2 Value
)
{
  Console.Write("TUint_2 ");
  me_WriteInteger::Write_U2(Value, Console.GetOutputStream());
  Console.EndLine();
}

void Test_U4(
  TUint_4 Value
)
{
  Console.Write("TUint_4 ");
  me_WriteInteger::Write_U4(Value, Console.GetOutputStream());
  Console.EndLine();
}

void Test_S1(
  TSint_1 Value
)
{
  Console.Write("TSint_1 ");
  me_WriteInteger::Write_S1(Value, Console.GetOutputStream());
  Console.EndLine();
}

void Test_S2(
  TSint_2 Value
)
{
  Console.Write("TSint_2 ");
  me_WriteInteger::Write_S2(Value, Console.GetOutputStream());
  Console.EndLine();
}

void Test_S4(
  TSint_4 Value
)
{
  Console.Write("TSint_4 ");
  me_WriteInteger::Write_S4(Value, Console.GetOutputStream());
  Console.EndLine();
}

void RunTests()
{
  Test_U1(TUint_1_Max);
  Test_U2(TUint_2_Max);
  Test_U4(TUint_4_Max);

  Test_S1(TSint_1_Min);
  Test_S1(TSint_1_Max);

  Test_S2(TSint_2_Min);
  Test_S2(TSint_2_Max);

  Test_S4(TSint_4_Min);
  Test_S4(TSint_4_Max);
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
