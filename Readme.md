## What

(2024)

Encoding integers to decimal ASCII. AVR. Arduino.


## Reference output

```
[me_WriteInteger] Okay, we are here.
* Encode integers
  TUint_1 012
  TUint_2 00012
  TUint_4 0000000012
  TSint_1 -012
  TSint_2 -00012
  TSint_4 -0000000012
[me_WriteInteger] Done.
```

## Code

* [Interface][Interface]
* [Implementation][Implementation]
* [Example][Example]


## Install/remove

Easy way is to clone [GetLibs][GetLibs] repo and run it's code.
Lacking of local repo catalogue in Arduino IDE sucks.


## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]


[Interface]: src/me_WriteInteger.h
[Implementation]: src/me_WriteInteger.cpp
[Example]: examples/me_WriteInteger/me_WriteInteger.ino

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
