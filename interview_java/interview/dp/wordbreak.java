package dp;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
import dp.My_Dictionary;

public class wordbreak {
	
	public boolean wordBreak_bigdict(String s, Set<String> dict) {
		if(s == null || s.length() ==0) return false;
		if(dict == null || dict.size() == 0) return false;
		
		int n = s.length();
		boolean[] dp = new boolean[n+1];
		dp[0] = true;
		
		for(int i = 0; i < s.length(); i++) {
			if(!dp[i]) continue;
			for(int j = i+1; j <= s.length(); j++) {				
				String tmp = s.substring(i, j);
				if(dict.contains(tmp)) dp[j] = true;
			}
		}
		
		return dp[s.length()];	
	}
	
	public boolean wordBreak(String s, Set<String> dict) {
		if(s == null || s.length() ==0) return false;
		if(dict == null || dict.size() == 0) return false;
		
		int n = s.length();
		boolean[] dp = new boolean[n+1];
		dp[0] = true;
		
		for(int i = 0; i < s.length(); i++) {
			if(!dp[i]) continue;
			for(String e:dict) {
				int len = e.length();
				int end = i+len;				
				if(end > s.length()) continue;
				
				if(dp[end]) continue;				
				if(s.substring(i, end).equals(e)) dp[end] = true;
			}
		}
		
		return dp[s.length()];		
	}

	public boolean wordBreak_naive(String s, Set<String> dict) {
		if(s == null || s.length() ==0) return false;
		if(dict == null || dict.size() == 0) return false;
		
		return wordBreak_naive_helper(s, dict, 0);
	}
	
	private boolean wordBreak_naive_helper(String s, Set<String> dict, int level) {
		if(level == s.length()) return true;
		
		for(String e:dict) {
			int len = e.length();
			int end = level + len;
			
			if(end > s.length()) continue;
			
			if(s.substring(level, end).equals(e)) {
				if(wordBreak_naive_helper(s, dict, end)) return true;
			}
		}
		
		return false;			
	}

	/**
	 * @param args
	 */
	public static void main (String[] args) throws FileNotFoundException, IOException {
		wordbreak test = new wordbreak();
		My_Dictionary md = new My_Dictionary();
		Set<String> dict  = md.getDictSet();
		
		Set<String> dict2 = new HashSet<String>();
		dict2.add("leet");
		dict2.add("code");		
		
		String s = "leetcode";		   
		if(test.wordBreak_naive(s, dict2)) System.out.println("can be broken");
		else System.out.println("can not be broken");

		if(test.wordBreak(s, dict2)) System.out.println("can be broken");
		else System.out.println("can not be broken");

		if(test.wordBreak_bigdict(s, dict2)) System.out.println("can be broken");
		else System.out.println("can not be broken");
}

}
