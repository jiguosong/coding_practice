package strings;

import java.util.Arrays;

public class longestnonrepsubstr {
	public int findLongNonRepStr(String s){
		int ret = 0;
		if (s == null || s.length() == 0) return ret;
		
		int[] map = new int[255];
		Arrays.fill(map, 0);
		
		int left = 0;
		for (int i = 0; i < s.length(); i++) {
			if (map[s.charAt(i)] == 0 || map[s.charAt(i)] < left) 
				ret = Math.max(ret, i - left + 1);
			else
				left = map[s.charAt(i)];
			
			map[s.charAt(i)] = i+1;
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		System.out.println("Java:LongestNonrepSubstr");
		longestnonrepsubstr test = new longestnonrepsubstr();
		String s = new String("abbca");
		int result = test.findLongNonRepStr(s);
		System.out.println(s);
		System.out.println(result);
	}
}
