load csamul16.hdl,
output-file csamul16.out,
compare-to csamul16.cmp,
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
set y %B00000001,
eval,
output;

set x %B00001001,
set y %B00001001,
eval,
output;

set x %B00000110,
set y %B00000011,
eval,
output;

set x %B00001110,
set y %B00001010,
eval,
output;

set x %B00001111,
set y %B00010010,
eval,
output;
