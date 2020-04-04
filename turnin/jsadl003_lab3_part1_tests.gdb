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
setPINB 0x00
continue 5
expectPORTC 0x00
checkResult

test "0x01 0x00"
setPINA 0x01
setPINB 0x00
continue 5
expectPORTC 0x01
checkResult

test "0x01 0x01"
setPINA 0x01
setPINB 0x01
continue 5
expectPORTC 0x02
checkResult

test "0x0F 0x0F"
setPINA 0x0F
setPINB 0x0F
continue 5
expectPORTC 0x08
checkResult

test "0xF0 0x0F"
setPINA 0xF0
setPINB 0x0F
continue 5
expectPORTC 0x08
checkResult

test "0xFF 0xFF"
setPINA 0xFF
setPINB 0xFF
continue 5
expectPORTC 0x10
checkResult

test "0x55 0xAA"
setPINA 0x55
setPINB 0xAA
continue 5
expectPORTC 0x08
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
