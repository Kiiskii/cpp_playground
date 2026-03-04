#!/bin/bash

GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

run_test() {
	local description="$1"
	local input="$2"
	local expected="$3"

	result=$(./RPN "$input" 2>&1 | tr -d '\001\002' | sed $'s/\033\[[0-9;]*m//g')
	if [ "$result" = "$expected" ]; then
		echo -e "${GREEN}PASS${RESET}: $description"
	else
		echo -e "${RED}FAIL${RESET}: $description"
		echo "  Input:    \"$input\""
		echo "  Expected: \"$expected\""
		echo "  Got:      \"$result\""
	fi
}

echo "=== Subject tests ==="
run_test "8 9 * 9 - 9 - 9 - 4 - 1 + = 42" "8 9 * 9 - 9 - 9 - 4 - 1 +" "result: 42"
run_test "7 7 * 7 - = 42" "7 7 * 7 -" "result: 42"
run_test "1 2 * 2 / 2 * 2 4 - + = 0" "1 2 * 2 / 2 * 2 4 - +" "result: 0"
run_test "(1 + 1) brackets not allowed" "(1 + 1)" "invalid token: (1"

echo ""
echo "=== Valid expressions ==="
run_test "5 = 5 (single number)" "5" "result: 5"
run_test "3 4 + = 7" "3 4 +" "result: 7"
run_test "9 3 - = 6" "9 3 -" "result: 6"
run_test "3 4 * = 12" "3 4 *" "result: 12"
run_test "8 2 / = 4" "8 2 /" "result: 4"
run_test "1 9 - = -8 (negative result)" "1 9 -" "result: -8"
run_test "5 5 - = 0 (zero result)" "5 5 -" "result: 0"
run_test "2 3 + 4 * = 20" "2 3 + 4 *" "result: 20"
run_test "9 2 / 1 + = 5" "9 2 / 1 +" "result: 5"
run_test "5 3 - 2 * 1 + = 5" "5 3 - 2 * 1 +" "result: 5"
run_test "6 2 * 3 / = 4" "6 2 * 3 /" "result: 4"
run_test "9 1 - 2 - 3 - = 3" "9 1 - 2 - 3 -" "result: 3"
run_test "1 2 * 3 * 4 * 5 * = 120" "1 2 * 3 * 4 * 5 *" "result: 120"
run_test "8 4 / 2 / = 1" "8 4 / 2 /" "result: 1"
run_test "7 2 + 3 - 4 * 2 / = 12" "7 2 + 3 - 4 * 2 /" "result: 12"

echo ""
echo "=== Error cases ==="
run_test "empty string -> error" "" "invalid expression"
run_test "5 0 / -> division by zero" "5 0 /" "cannot divide by 0"
run_test "1 2 3 + -> too many operands" "1 2 3 +" "invalid expression"
run_test "1 + -> not enough operands" "1 +" "not enough operands"
run_test "10 5 + -> number >= 10 rejected" "10 5 +" "invalid token: 10"
run_test "+ -> operator with empty stack" "+" "not enough operands"
run_test "a b + -> letters rejected" "a b +" "invalid token: a"

echo ""
echo "=== Overflow/Underflow ==="
run_test "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * -> overflow" "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "integer overflow or underflow"
run_test "0 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * - -> underflow" "0 9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * -" "integer overflow or underflow"
