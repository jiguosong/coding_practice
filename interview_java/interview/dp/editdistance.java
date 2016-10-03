package dp;

public class editdistance {
	
	public int minDistance(String word1, String word2) {
		if(word1 == null || word1.length() == 0) return 0;
		if(word2 == null || word2.length() == 0) return 0;
		
		int res = 0;
		
		int m = word1.length();
		int n = word2.length();
		
		int[][] dp = new int[m+1][n+1];  // the extra one is due to ""
		for(int i = 0; i < m+1; i++) {
			dp[i][0] = i; // delete
		}
		for(int i = 0; i < n+1; i++) {
			dp[0][i] = i; // add
		}
		
		for(int i = 1; i < m+1; i++) {
			for(int j = 1; j < n+1; j++) {
				if(word1.charAt(i-1) == word2.charAt(j-1)) dp[i][j] = dp[i-1][j-1];
				else dp[i][j] = 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1])); 
			}
		}
		
		res = dp[m][n];
		
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		editdistance test = new editdistance();
		String words1 = "Carthorse";
		String words2 = "Orchestra";
		int ans = test.minDistance(words1, words2);
		System.out.println(ans);

	}

}
