package strings;

import java.util.*;

public class shortestPalindrome {
	
	public String shortestPalindrome_1(String s) {
		if(s == null || s.length() == 0) return null;
		
		int left = 0;
		int right = s.length()-1;
		
		while(right >= 0) {
			if(s.charAt(left) == s.charAt(right)) left++;
			right--;
		}
		
		if(left == s.length()) return s;
		
		String suffix = s.substring(left);
		StringBuilder sb = new StringBuilder(suffix);
		String prefix = sb.reverse().toString();
		String mid = shortestPalindrome_1(s.substring(0, left));
		
		return prefix+mid+suffix;		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		shortestPalindrome test = new shortestPalindrome();
		String s = "abcd";
		String ans = test.shortestPalindrome_1(s);
		System.out.println(ans);

	}

}
