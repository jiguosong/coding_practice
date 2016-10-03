package dp;

public class longestCommonSubsequence {
	
	public static int getLongestCommonSubsequence(String a, String b){
		if(a == null || b == null) return 0;
		int m = a.length();
		int n = b.length();
		if(m == 0 || n == 0) return 0;
		
		int[][] dp = new int[m+1][n+1];

		for(int i = 0; i <= m; i++) {
			for(int j = 0; j <= n; j++) {
				if(i == 0 || j == 0) dp[i][j] = 0 ;
				else if(a.charAt(i-1) != b.charAt(j-1)) dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
				else dp[i][j] = dp[i-1][j-1]+1;
			}
		}
		
		return dp[m][n];		
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		longestCommonSubsequence test = new longestCommonSubsequence();
		String a = "ABCDGH";
		String b = "AEDFHR";
		int ans = test.getLongestCommonSubsequence(a, b);
		System.out.println(ans);
	}

}
