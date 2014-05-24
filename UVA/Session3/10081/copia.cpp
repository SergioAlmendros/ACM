#include <cstdio>
 
int main() {
  int n, k;
  while (scanf("%d%d", &k, &n) == 2) {
    double dp[10][101] = {}, div = 1 + k;
    for (int i = 0; i <= k; i++) {
      dp[i][1] = 1 / div;
    }
    for (int i = 2; i <= n; i++) {
      for (int last = 0; last <= k; last++) {
        for (int diff = -1; diff <= 1; diff++) {
          int digit = last + diff;
          if (0 <= digit && digit <= k) {
            dp[last][i] += dp[digit][i - 1] / div;
          }
        }
      }
    }
    double ans = 0;
    for (int i = 0; i <= k; i++) {
      ans += dp[i][n];
    }
    printf("%.5lf\n", 100 * ans);
  }
  return 0;
}
