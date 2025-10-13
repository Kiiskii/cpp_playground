#!/usr/bin/env bash
bin=./ScalarConverter

if [[ ! -x "$bin" ]]; then
    echo "❌ Error: Executable '$bin' not found or not executable." >&2
    echo "   Try building your program first, e.g. 'make' or 'g++ ... -o ScalarConverter'" >&2
    exit 1
fi

basic_tests=(
    # ints
    "0" "42" "-42" "+7"
    # floats (with f)
    "0.0f" "-0.0f" "42.0f" "3.1415f" "23.0002f"
    # doubles (no f)
    "0.0" "-0.0" "42.0" "3.1415" "23.0002"
    # single-char inputs (should be CHAR type)
    "a" "~" "Z"
    # + & - checks
    "+" "-" "++" "--"
)

edge_tests=(
    # integer boundaries
    "2147483647" "-2147483648" "2147483648" "-2147483649"
    # float integer-ish rounding/formatting checks
    "23.00000002f" "23.000002f" "23.0002f" "42.00000001f"
    # double → float formatting (you clamp float precision; should still be neat)
    "42.00000001"
    # printable vs non-printable char behavior when numeric
    "31" "32" "126" "127" "-1" "128"
    # pseudo literals (you’ll wire special handling soon)
    "nan" "nanf" "+inf" "-inf" "+inff" "-inff"
    # single non-printable chars as CHAR input
    $'\t'  $'\n'  $'\x7f'
    # odd signs / parsing rejects
    "--1" "++1" "+-1" "-+1" "." ".f" "f"
    # whitespace (your detector doesn’t trim → should be invalid)
    " 42" "42 " "  3.0f  "
    # too-large float literal (overflow to stof)
    "9999999999999999999999999999999999999999999999999f"
    # too-large double literal (overflow to stod)
    "9999999999999999999999999999999999999999999999999"
    # multiple dots
    "1.2.3" "12..3" "..1f" ".1f"
    # trailing junk
    "12a" "3.14ff" "10.f"  # note: "10.f" is often invalid in your checker logic
)

print_suite () {
    local title="$1"; shift
    local -n arr=$1
    echo
    echo "==================== $title ===================="
    local i=1
    for t in "${arr[@]}"; do
        printf '\n[%02d] ARG = %q\n' "$i" "$t"
        echo "--------------------------------"
        "$bin" "$t"
        ((i++))
    done
}

print_suite "BASIC TESTS" basic_tests
print_suite "EDGE-CASE TESTS" edge_tests
