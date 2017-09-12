// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/02/Add16.tst

load Mul4Sign.hdl,
output-file Mul4Sign.out,
compare-to Mul4Sign.cmp,
output-list x%B1.4.1 y%B1.4.1 out%B1.8.1 overflow%B4.1.4;

set x %B1011,
set y %B0101,
eval,
output;

set x %B0011,
set y %B1101,
eval,
output;

set x %B1001,
set y %B0111,
eval,
output;

set x %B1111,
set y %B0001,
eval,
output;

set x %B1001,
set y %B1001,
eval,
output;

set x %B0110,
set y %B0011,
eval,
output;

set x %B1110,
set y %B1010,
eval,
output;