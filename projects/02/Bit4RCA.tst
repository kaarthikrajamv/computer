load Bit4RCA.hdl,
output-file Bit4RCA.out,
compare-to Bit4RCA.cmp,
output-list a%B1.4.1 b%B1.4.1 carryin%B3.1.3 sum%B1.4.1 carryout%B4.1.4;

set a %B0000,
set b %B0000,
set carryin %B0,
eval,
output;

set a %B0001,
set b %B1111,
set carryin %B0,
eval,
output;

set a %B0010,
set b %B1100,
set carryin %B0,
eval,
output;

set a %B0110,
set b %B0001,
set carryin %B1,
eval,
output;
