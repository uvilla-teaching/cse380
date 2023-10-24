#!/usr/bin/env bats

executable="../src/rng-tool"

@test "verify rng-tool executable exists" {
      run ls $executable
      [ "$status" -eq 0 ]
}

@test "verify rng has 10 lines in stdout" {
    
    run $executable
    [ "$status" -eq 0 ]

    # verify we have 10 lines of output
    [ ${#lines[@]} -eq 10 ]
}

@test "verify rng samples" {
    rm -f .tmp_output
    $executable > .tmp_output

    # compare to reference output
    run diff .tmp_output ref_output
    [ "$status" -eq 0 ]
    
}
