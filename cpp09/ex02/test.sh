#!/bin/bash

PROG="./PmergeMe"
PASS=0
FAIL=0

green() { printf "\033[0;32m%s\033[0m\n" "$1"; }
red() { printf "\033[0;31m%s\033[0m\n" "$1"; }

# Test that expects success and correct sorting
test_valid() {
	local verbose="$1"
	local desc="$2"
	shift 2
	local output
	output=$($PROG "$@" 2>&1)
	if [ $? -ne 0 ]; then
		red "FAIL: $desc (non-zero exit)"
		echo "  Output: $output"
		((FAIL++))
		return
	fi
	local after
	after=$(echo "$output" | grep "After:" | sed 's/After: //')
	local sorted
	sorted=$(echo "$after" | tr ' ' '\n' | grep -v '^$' | sort -n | tr '\n' ' ' | sed 's/ $//')
	local actual
	actual=$(echo "$after" | sed 's/ $//')
	if [ "$actual" != "$sorted" ]; then
		red "FAIL: $desc (not sorted)"
		echo "  Got: $actual"
		((FAIL++))
		return
	fi
	local input_sorted
	input_sorted=$(printf '%s\n' "$@" | sort -n | tr '\n' ' ' | sed 's/ $//')
	if [ "$actual" != "$input_sorted" ]; then
		red "FAIL: $desc (elements don't match input)"
		echo "  Input sorted:  $input_sorted"
		echo "  Output sorted: $actual"
		((FAIL++))
		return
	fi
	green "PASS: $desc"
	if [ "$verbose" = "1" ]; then
		echo "$output" | sed 's/^/  /'
	else
		echo "$output" | grep "Time" | sed 's/^/  /'
	fi
	((PASS++))
}

# Test that expects failure (non-zero exit)
test_error() {
	local desc="$1"
	shift
	local output
	output=$($PROG "$@" 2>&1)
	if [ $? -eq 0 ]; then
		red "FAIL: $desc (expected error, got success)"
		echo "  Output: $output"
		((FAIL++))
		return
	fi
	green "PASS: $desc"
	echo "  Input:  $PROG $*"
	echo "  Output: $output"
	((PASS++))
}

echo "=== Valid inputs ==="
test_valid 1 "single element" 42
test_valid 1 "two elements" 5 3
test_valid 1 "small input" 5 3 1 4 2
test_valid 1 "reverse sorted" 9 8 7 6 5 4 3 2 1
test_valid 1 "already sorted" 1 2 3 4 5 6 7 8 9
test_valid 1 "duplicates" 5 3 5 1 3 2 1 4 5
test_valid 1 "all same" 7 7 7 7 7
test_valid 1 "two duplicates" 80 80

echo ""
echo "=== Larger inputs ==="
test_valid 0 "20 random elements" $(jot -r 20 1 100 | tr '\n' ' ')
test_valid 0 "100 random elements" $(jot -r 100 1 1000 | tr '\n' ' ')
test_valid 0 "500 random elements" $(jot -r 500 1 10000 | tr '\n' ' ')
test_valid 0 "3000 random elements" $(jot -r 3000 1 100000 | tr '\n' ' ')

echo ""
echo "=== Error cases ==="
test_error "no arguments"
test_error "negative number" 3 -1 2
test_error "non-numeric input" 3 abc 2
test_error "mixed invalid" 1 2 3a
test_error "overflow" 99999999999999999999

echo ""
echo "=== Results ==="
green "Passed: $PASS"
if [ $FAIL -gt 0 ]; then
	red "Failed: $FAIL"
else
	echo "Failed: $FAIL"
fi
