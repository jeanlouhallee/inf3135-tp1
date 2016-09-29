#!/usr/bin/env bats

@test "Nombre d'arguments invalide" {
  run ./tp1 X 1,2,1
  [ "$output" = "Nombre d'arguments invalides: il en faut 3" ]
}

@test "Premier code invalide" {
  run ./tp1 XA E 1,2,1
  [ "$output" = "Code XA invalide: il doit etre un caractere unique" ]
}

@test "Deuxieme code invalide" {
  run ./tp1 X eau 1,2,1
  [ "$output" = "Code eau invalide: il doit etre un caractere unique" ]
}

@test "Code non distincts" {
  run ./tp1 X X 1,2,1
  [ "$output" = "Les codes doivent etre distincts" ]
}

@test "La hauteur n'est pas un nombre" {
  run ./tp1 X E 1,2,1a,-1,4,2a
  [ "$output" = "Hauteur invalide: la hauteur doit etre un nombre entre 0 et 15" ]
}

@test "La hauteur est trop grande" {
  run ./tp1 X E 100,1,2
  [ "$output" = "Hauteur invalide: la hauteur doit etre un nombre entre 0 et 15" ]
}

@test "La largeur est trop grande" {
  run ./tp1 X E 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
  [ "$output" = "Largeur invalide: le nombre de hauteurs doit etre entre 1 et 20" ]
}

@test "Montagne 1,3,2" {
  run ./tp1 X E 1,3,2
  [ "${lines[0]}" = "-X-" ]
  [ "${lines[1]}" = "-XX" ]
  [ "${lines[2]}" = "XXX" ]
}

@test "Montagne 2,1,2" {
  run ./tp1 X E 2,1,2
  [ "${lines[0]}" = "XEX" ]
  [ "${lines[1]}" = "XXX" ]
}

@test "Montagne 2,1,3,0,4,2,4" {
  run ./tp1 X E 2,1,3,0,4,2,4
  [ "${lines[0]}" = "----XEX" ]
  [ "${lines[1]}" = "--XEXEX" ]
  [ "${lines[2]}" = "XEXEXXX" ]
  [ "${lines[3]}" = "XXXEXXX" ]
}

@test "Montagne 2,4,1,2,3,2,1,1,3,2" {
  run ./tp1 X E 2,4,1,2,3,2,1,1,3,2
  [ "${lines[0]}" = "-X--------" ]
  [ "${lines[1]}" = "-XEEXEEEX-" ]
  [ "${lines[2]}" = "XXEXXXEEXX" ]
  [ "${lines[3]}" = "XXXXXXXXXX" ]
}

@test "Montagne 2,3,4,4,3,2,3,2,2,5,1,2" {
  run ./tp1 X E 2,3,4,4,3,2,3,2,2,5,1,2
  [ "${lines[0]}" = "---------X--" ]
  [ "${lines[1]}" = "--XXEEEEEX--" ]
  [ "${lines[2]}" = "-XXXXEXEEX--" ]
  [ "${lines[3]}" = "XXXXXXXXXXEX" ]
  [ "${lines[4]}" = "XXXXXXXXXXXX" ]
}

