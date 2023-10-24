#!/usr/bin/env bats


executable="./pi"

@test "verify ./pi exits" {
   run ls $executable
   [ "$status" -eq 0 ]
}


@test "verify ./pi exits correctly with no input" {
run $executable
[ "$status" -eq 1 ]

# also, verify initial error message
[ "${lines[0]}" = "Usage: pi.sh [num_samples]" ]
}

@test "verify ./pi.exe exits when num_samples < 0 " {
run $executable -5
[ "$status" -eq 1 ]

# verify error message when num_samples < 0
[ "${lines[0]}" = "numSamples must be > 0" ]
}

