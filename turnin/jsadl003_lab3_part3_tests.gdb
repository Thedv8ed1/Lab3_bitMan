# Test file for "Lab3_bitMan"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n



test "zero"
setPINA 0x00
continue 5
expectPORTC 0x40
checkResult

test "fuel level 1"
setPINA 0x01
continue 5
expectPORTC 0x60
checkResult

test "fuel level 2"
setPINA 0x02
continue 5
expectPORTC 0x60
checkResult

test "fuel level 3"
setPINA 0x03
continue 5
expectPORTC 0x70
checkResult

test "fuel level 4"
setPINA 0x04
continue 5
expectPORTC 0x70
checkResult

test "fuel level 5"
setPINA 0x05
continue 5
expectPORTC 0x38
checkResult

test "fuel level 6"
setPINA 0x06
continue 5
expectPORTC 0x38
checkResult

test "fuel level 7"
setPINA 0x07
continue 5
expectPORTC 0x3C
checkResult

test "fuel level 8"
setPINA 0x08
continue 5
expectPORTC 0x3C
checkResult

test "fuel level 9"
setPINA 0x09
continue 5
expectPORTC 0x3C
checkResult

test "fuel level 10"
setPINA 0x0A
continue 5
expectPORTC 0x3E
checkResult

test "fuel level 11"
setPINA 0x0B
continue 5
expectPORTC 0x3E
checkResult

test "fuel level 12"
setPINA 0x0C
continue 5
expectPORTC 0x3E
checkResult

test "fuel level 13"
setPINA 0x0D
continue 5
expectPORTC 0x3F
checkResult

test "fuel level 14"
setPINA 0x0E
continue 5
expectPORTC 0x3F
checkResult

test "fuel level 15"
setPINA 0x0F
continue 5
expectPORTC 0x3F
checkResult 

test "low fuel light and seatbelt light"
setPINA 0x32
continue 5
expectPORTC 0xE0
checkResult

test "no low fuel light and seatbelt light"
setPINA 0x3F
continue 5
expectPORTC 0xBF
checkResult



 #Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
