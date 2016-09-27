package strings;

import java.util.*;

public class longestAtMostKDistinct {
	public int lengthOfLongestSubstringKDistinct(String s, int k) {
		if (s == null || s.length() == 0) return 0;
		if (s.length() < k) return s.length();
		
		int max = 0;
		int start = 0;
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		
		for(int i = 0; i < s.length(); i++) {
			Character c = s.charAt(i);
			if (map.containsKey(c)) {
				int count = map.get(c);
				map.put(c, count+1);
			} else {
				map.put(c, 1);
			}
			
			if (map.size() > k) {
				max = Math.max(max, i - start);
				while(map.size() > k) {
					Character tmp_c = s.charAt(start);
					int tmp_n = map.get(tmp_c);
					if(tmp_n > 1) map.put(tmp_c, tmp_n-1);
					else map.remove(tmp_c);
					start++;
				}
			}
		}
		
		max = Math.max(max, s.length() - start);
		
		return max;	
	}

	public int lengthOfLongestSubstringTwoDistinct(String s) {
		if (s == null || s.length() == 0) return 0;
		if (s.length() < 3) return s.length();
		
		int max = 0;
		int start = 0;
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		
		for(int i = 0; i < s.length(); i++) {
			Character c = s.charAt(i);
			if (map.containsKey(c)) {
				int count = map.get(c);
				map.put(c, count+1);
			} else {
				map.put(c, 1);
			}
			
			if (map.size() > 2) {
				max = Math.max(max, i - start);
				while(map.size() > 2) {
					Character tmp_c = s.charAt(start);
					int tmp_n = map.get(tmp_c);
					if(tmp_n > 1) map.put(tmp_c, tmp_n-1);
					else map.remove(tmp_c);
					start++;
				}
			}
		}
		
		max = Math.max(max, s.length() - start);
		
		return max;	
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		longestAtMostKDistinct test = new longestAtMostKDistinct();
		String s = "abcadcacacaca";
		int ans = test.lengthOfLongestSubstringKDistinct(s,3);
		System.out.println(ans);

	}

}
