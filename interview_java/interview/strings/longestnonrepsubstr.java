package strings;

import java.util.*;

public class longestnonrepsubstr {
	public int findLongNonRepStr(String s){
		if (s == null || s.length() == 0) return 0;
		int ret = 0;
		
		int[] map = new int[256];
		Arrays.fill(map, 0);
		
		int left = 0;
		for (int i = 0; i < s.length(); i++) {
			if (map[s.charAt(i)] == 0 || map[s.charAt(i)] < left)   // first time see or aready contains a rep str, need use updated start
				ret = Math.max(ret, i - left + 1);
			else
				left = map[s.charAt(i)];   // the start position of non-rep str
			
			map[s.charAt(i)] = i+1;
		}
		
		return ret;
	}

/*	
	public int findLongNonRepStr2(String s){
		if (s == null || s.length() == 0) return 0;
		int ret = 0;
		
		int[] map = new int[256];
		Arrays.fill(map, -1);
		
		int left = -1;
		for (int i = 0; i < s.length(); i++) {
			left = Math.max(left, map[s.charAt(i)]);
			map[s.charAt(i)] = i;
			ret = Math.max(ret, i - left);		
		}
		
		return ret;
	}
*/
	
	
	// use set and remove when encounter the same char
	public int findLongNonRepStr3(String s){
		if (s == null || s.length() == 0) return 0;
		int res = 0;
		int left = 0;
		int right = 0;

		Set<Character> set = new HashSet<Character>();
		
		while(right < s.length()) {
			if(!set.contains(s.charAt(right))) {
				set.add(s.charAt(right));
				right++;
				res = Math.max(res, set.size());
			} else {
				set.remove(s.charAt(left));
				left++;
			}
		}
		
		return res;
	}
	
	// same as above, just use map here
	public int findLongNonRepStr4(String s){
		if (s == null || s.length() == 0) return 0;
		int max = 0;
		
		Map<Character, Integer> map = new HashMap<Character, Integer>();
		int left = 0;
		
		for(int i = 0; i < s.length(); i++) {
			Character c = s.charAt(i);
			if(!map.containsKey(c)) {
				map.put(c, i);
				max = Math.max(max, map.size());	
			} else {
				while(map.containsKey(c)) {
					map.remove(s.charAt(left));
					left++;
				}
			}
		}
		
		return max;
	}		
	
	
	public static void main(String[] args) {
		System.out.println("Java:LongestNonrepSubstr");
		longestnonrepsubstr test = new longestnonrepsubstr();
		String s = new String("abcabcbb");
		int result = test.findLongNonRepStr4(s);
		System.out.println(s);
		System.out.println(result);
	}
}
