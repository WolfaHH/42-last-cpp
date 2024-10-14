#!/bin/bash

run_test() {
    echo "Test: $1"
    output=$(./RPN "$1")
    echo "Output: $output"
    echo "-------------------"
}

run_test "3 4 +"
run_test "3 4 -"
run_test "3 4 *"
run_test "3 4 /"
run_test "3 4 + 2 *"
run_test "3 4 2 * +"
run_test "3 4 + 5 6 * +"
run_test "13 4 -"
run_test "10 6 9 3 + -11 * / * 17 + 5 +"
run_test "1 2 3 +"
run_test "1 +"
run_test "1 2 + -"
run_test "1 2 3 + + +"
run_test "5 0 /"
run_test "3 4 + 0 /"
run_test "  3     4   +   "
run_test "1 2   +   3     *"
run_test "1 2 + a"
run_test "1 2 3 $ +"
run_test "abc"
run_test "2147483647 1 +"
run_test "-2147483648 1 -"
./RPN
run_test ""