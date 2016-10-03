package dp;

public class distinctSubsequencesTotal {
	
	public int numDistincts(String S, String T) {
		if(S == null || T == null) return 0;
	
		int m = S.length();
		int n = T.length();
		
		// dp[i][j]  : the numer of occurrance of substring T(0,j) in substring S(0,i)
		int[][] dp = new int[m+1][n+1];
		for(int i = 0; i < n; i++) {
			dp[0][i] = 0;
		}
		for(int i = 0; i < m; i++) {
			dp[i][0] = 1;
		}
		
		
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(S.charAt(i-1) == T.charAt(j-1)) dp[i][j] += dp[i-1][j-1] + dp[i-1][j];
				else dp[i][j] += dp[i-1][j];
			}
		}
		
		return dp[m][n];
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		distinctSubsequencesTotal test = new distinctSubsequencesTotal();
		String S = "rabbbit"; String T = "rabbit";
		int ans = test.numDistincts(S, T);
		System.out.println(ans);

	}

}
