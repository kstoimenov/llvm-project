// RUN: %clangxx -O0 %s -o %t && %run %t
// XFAIL: *
// UNSUPPORTED: lsan, ubsan
// FIXME: HWASAN should work when we have intercepptors.
// UNSUPPORTED: hwasan

#include <cstring>
#include <cstdio>

int main(int argc, char** argv) {
  int *x = new int(7);
  delete x;
  // Trigger use after free error.
  return memcmp(x, &argc, sizeof(int)) == 0 ? 1 : 0;
}