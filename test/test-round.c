#include <stdio.h>
#include <math.h>

extern double precise_round(double x, int digits);

int main()
{
  printf("%f\n", precise_round(5.015, 2)); // 5.02
  printf("%f\n", precise_round(5.0149999999999987921, 2)); // 5.01
  printf("%.18f\n", precise_round(9.995, 2)); // 10.0
  printf("%.18f\n", precise_round(50.0, -2)); // 100.0
  printf("%.18f\n", precise_round(NAN, -2)); // NAN
  printf("%.18f\n", precise_round(INFINITY, -2)); // NAN
  printf("%.18f\n", precise_round(0.4999999999999999445, 0)); // 0.0
  printf("%.18f\n", precise_round(9007199254740992.0, 0));
  printf("%.18f\n", precise_round(48689348815413084160.0, -4));
  printf("--\n");

  double d = 9007199254740992;
  while (d < 18014398509481984.0) {
    if (round(d) != precise_round(d, 0)) {
      printf("%.1f %.1f\n", d, precise_round(d, 0));
    }
    d += 2.0;
  }
}
