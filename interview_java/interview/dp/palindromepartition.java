package dp;

import java.util.*;

public class palindromepartition {
	public List<String> palindromePartitioning(String s) {
		if (s == null || s.length() == 0) return null;
	
		List<String> res = new ArrayList<String>();
		if(s.length() == 1) {
			res.add(s);
			return res;
		}

		int m = s.length();		
		boolean[][] dp = new boolean[m][m];
		dp[0][0] = true;
		
		// l is length, i is index of left boundary, j is index of right boundary
		for (int len = 1; len <= m; len++) {
			for (int i = 0; i <= m - len; i++) {
				int j = i + len - 1;
				dp[i][j] = (s.charAt(i) == s.charAt(j) && (j-i<2 || dp[i+1][j-1]));
				if (dp[i][j]) res.add(s.substring(i, j + 1));
			}
		}
		
		return res;
	}
	
	
	public List<List<String>> doPartitionpalindrome(String s) {
		List<List<String>> res = new ArrayList<List<String>>();
		List<String> tmp = new ArrayList<String>();
		
		if (s == null || s.length() == 0) return res;
		
		doPartitionpalindrome_helper(s, 0, tmp, res);
		
		return res;
	}
	
	
	private boolean isPalindrome(String s){
		int l = 0;
		int r = s.length() - 1;
		
		while(l < r) {
			if (s.charAt(l) != s.charAt(r)) return false;			
			l++;
			r--;
		}
		
		return true;
	}
	

	private void doPartitionpalindrome_helper(String s, int level, 
												  List<String> tmp, List<List<String>> res){
		if (level == s.length()) {
			res.add(new ArrayList<String>(tmp));
			return;
		}
		
		for (int i = level; i < s.length(); i++) {
			String tmp_str = s.substring(level, i+1);
			if (isPalindrome(tmp_str)) {
				tmp.add(tmp_str);
				doPartitionpalindrome_helper(s, i+1, tmp, res);
				tmp.remove(tmp.size()-1);
			}
		}	
		
		return;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Java:partitionpalindrome");
		palindromepartition test = new palindromepartition();
		List<List<String>> res = new ArrayList<List<String>>();
		
		/*res = test.doPartitionpalindrome("aab");
		Iterator<List<String>> its = res.iterator();		
		while(its.hasNext()) {
			List<String> tmp = its.next();
			Iterator<String> it = tmp.iterator();
			while(it.hasNext()) {
				System.out.print(it.next() + " ");
			}
			System.out.println();
		}*/
		
		List<String> ans = test.palindromePartitioning("aab");
		for(int i = 0; i< ans.size(); i++) System.out.println(ans.get(i));
		
	}

}
