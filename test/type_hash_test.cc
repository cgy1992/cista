#include "doctest.h"

#include "cista.h"

TEST_CASE("hash test") {
  struct test {
    int i;
    int* j;
  } a;

  int b;
  CHECK(cista::type_hash(a) != cista::type_hash(b));
}

TEST_CASE("hash test") {
  struct s1 {
    int i;
    struct {
      int j;
    } k;
  } a;
  struct s2 {
    struct {
      int i;
    } j;
    int k;
  } b;
  CHECK(cista::type_hash(a) != cista::type_hash(b));
  CHECK(9969041101756795253ULL == cista::type_hash(a));
  CHECK(9736592708735393397ULL == cista::type_hash(b));
}