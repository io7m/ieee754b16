#include <ieee754b16/convert.h>

#include <stdio.h>

int
main (void)
{
  printf("-- [-1.0, 1.0]\n");

  {
    double d = -1.0;
    while (d <= 1.0) {
      ieee754b16_half_t packed = ieee754b16_pack(d);
      double r = ieee754b16_unpack(packed);
      printf("%.08f → 0x%04x → %.08f\n", d, packed, r);
      d += 0.001;
    }
  }

  printf("-- [-32767, 32767]\n");

  {
    double d = -32767;
    while (d <= 32767) {
      ieee754b16_half_t packed = ieee754b16_pack(d);
      double r = ieee754b16_unpack(packed);
      printf("%.08f → 0x%04x → %.08f\n", d, packed, r);
      d += 1.0;
    }
  }

  return 0;
}

