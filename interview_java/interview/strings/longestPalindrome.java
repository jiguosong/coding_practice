package strings;

import java.util.*;

public class longestPalindrome {
	public String findlongestPalindrome(String s) {
		String[] ret = new String[1];
		int[] len = new int[1];
		len[0] = 1;
		
		if (s == null || s.length() == 0) return null;
		
		if (s.length() == 1) {
			ret[0] = s;
			return ret[0];
		}
		if (s.charAt(0) == s.charAt(1)) {
			len[0] = 2;
			ret[0] = s.substring(0, 1);
		}
		
		for (int i = 1; i < s.length(); i++) {
			check(s, i-1, i+1, ret, len);
			if (i < s.length()-2 && s.charAt(i) == s.charAt(i+1)) {
				check(s, i-1, i+2, ret, len);
			}
		}		
		return ret[0];
	}
	
	private void check(String s, int j, int k, String[] ret, int[] len){
		while(j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
			j--;
			k++;
		}
		
		int tmp_len = k - j + 1 - 2;
		if (tmp_len > len[0]) {
			len[0] = tmp_len;
			ret[0] = s.substring(j+1, k);
		}
		
		return;
	}
	
	
	public static void main(String[] args) {
		
		longestPalindrome test = new longestPalindrome();
		String s = new String("bananas");
		String res = test.findlongestPalindrome(s);
		
		System.out.print(res);
		
		return;
	}
	
}
