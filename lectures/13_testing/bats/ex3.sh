#!/usr/bin/env bats

@test "addition using bc" {
  skip "known failure"
  result="$(echo 2+2 | bc)"
  [ "$result" -eq 42 ]
}

@test "division using bc" {
  result="$(echo 64 / 8 | bc)"
  [ "$result" -eq 8 ]
}
