import java.util.Scanner;
 
public class TightWords {
    static double[][] dp = new double[100][11];
    static int n;
    static int k;
 
    static double go(int i, int j) {
        if (i == n)
            return 1;
        else if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] = (((j + 1) <= k) ? go(i + 1, j + 1) : 0)
                    + ((j - 1 >= 0) ? go(i + 1, j - 1) : 0) + go(i + 1, j);
    }
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            k = in.nextInt();
            n = in.nextInt();
            double res2 = Math.pow((k + 1), n);
            for (int i = 0; i < dp.length; i++)
                for (int j = 0; j < dp[0].length; j++)
                    dp[i][j] = -1;
            double res1 = 0;
            for (int i = 0; i <= k; i++)
                res1 += go(1, i);
            System.out.printf("%.5f\n", (res1 * 100.000 / res2));
        }
    }
}
