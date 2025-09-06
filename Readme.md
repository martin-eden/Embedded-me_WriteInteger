## What

(2024)

Encoding integers to decimal ASCII. AVR. Arduino.


## Reference output

```
( [me_WriteInteger] test
TUint_1 255
TUint_2 65535
TUint_4 4294967295
TSint_1 -128
TSint_1 +127
TSint_2 -32768
TSint_2 +32767
TSint_4 -2147483648
TSint_4 +2147483647
) Done
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
[Implementation]: src/
[Example]: examples/me_WriteInteger/me_WriteInteger.ino

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
