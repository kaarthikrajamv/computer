load CSAMulSigned.hdl,
output-file CSAMulSigned.out,
compare-to CSAMulSigned.cmp,
output-list x%B1.8.1 y%B1.8.1 z%B1.16.1 overflow%B4.1.4;

set x %B00001011,
set y %B00000101,
eval,
output;

set x %B00000011,
set y %B00001101,
eval,
output;

set x %B00001001,
set y %B00000111,
eval,
output;

set x %B00001111,
set y %B11111111,
eval,
output;

set x %B00001001,
set y %B11110111,
eval,
output;

set x %B00001010,
set y %B00001111,
eval,
output;