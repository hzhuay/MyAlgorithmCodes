import java.math.BigInteger;
import java.util.Scanner;

class Main{
    public static void main(String args[]){
        BigInteger[] B = new BigInteger[85];
        B[0] = BigInteger.ONE;
        for(int i=1;i<=80;i++){
            B[i] = B[i-1].multiply(BigInteger.valueOf(2));
        }
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        BigInteger ans = BigInteger.ZERO;
        for(int kase=0;kase<N;kase++){
            BigInteger[][] dp = new BigInteger[1005][1005];
            for(int i=0;i<1005;i++) {
            	for(int j=0;j<1005;j++) {
            		dp[i][j] = BigInteger.ZERO;
            	}
            }
            int[] A = new int[1005];
            for(int i=1;i<=M;i++){
                A[i] = in.nextInt();
            }
            for(int i=1;i<=M;i++){
                for(int j=M;j>=i;j--){
                    dp[i][j] = dp[i][j].max( dp[i-1][j].add( B[i+M-j-1].multiply(BigInteger.valueOf(A[i-1]) ) ) );
                    dp[i][j] = dp[i][j].max( dp[i][j+1].add( B[i+M-j-1].multiply(BigInteger.valueOf(A[j+1]) ) ) );
                }
            }
            BigInteger tmp = BigInteger.ZERO;
            for(int i=1;i<=M;i++){
                tmp = tmp.max(dp[i][i].add(B[M].multiply(BigInteger.valueOf(A[i]))));
            }
            ans = ans.add(tmp);
        }
        in.close();
        System.out.println(ans);
    }
}