## What

(2024-10, 2024-12..)

Encoding/decoding integers to decimal ASCII. AVR. Arduino.

## Reference output

```
[me_CodecDecInt] Okay, we are here.
  * Formatting integers
    00000000000000000123
    -0000000002147483648
    00000000002147483648
[me_CodecDecInt] Done.
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

[Example]: examples/me_CodecDecInt/me_CodecDecInt.ino
[Interface]: src/me_CodecDecInt.h
[Implementation]: src/me_CodecDecInt.cpp

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
