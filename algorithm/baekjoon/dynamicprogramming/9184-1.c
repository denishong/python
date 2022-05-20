#include <stdio.h>
int dp[21][21][21] = { 0 };

int w(int a, int b, int c) {
  int ret;
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return dp[20][20][20] = w(20, 20, 20);
  ret = dp[a][b][c];
  //cout << dp[a][b][c] << a << b << c;
  //printf("%d %d %d %d \n", a, b, c, dp[a][b][c]);
  if (ret != 0) return ret;
  if (a < b && b < c) return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
  int a, b, c;
  while (1) {
    scanf("%d %d %d", &a, &b, &c);
    if (a == -1 && b == -1 && c == -1) break;
      printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
  }
}
