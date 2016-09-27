package strings;

import java.util.*;

public class longestnonrepsubstr {
	public int findLongNonRepStr(String s){
		if (s == null || s.length() == 0) return 0;
		int ret = 0;
		
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
	
	
	public int findLongNonRepStr2(String s){
		if (s == null || s.length() == 0) return 0;
		int res = 0;
		int left = 0;
		int right = 0;

		Set<Character> set = new HashSet<Character>();
		
		for(int i = 0; i < s.length(); i++) {
			if(!set.contains(s.charAt(i))) {
				 set.add(s.charAt(i));
				 right++;
			} else {
				res = Math.max(res, set.size());
				set.remove(s.charAt(i));
				left++;
			}
		}
		
		return res;
	}
	
	public int findLongNonRepStr3(String s){
		if (s == null || s.length() == 0) return 0;
		int ret = 0;
		
		int[] map = new int[255];
		Arrays.fill(map, -1);
		
		int left = -1;
		for (int i = 0; i < s.length(); i++) {
			left = Math.max(left, map[s.charAt(i)]);
			map[s.charAt(i)] = i;
			ret = Math.max(ret, i - left);		
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		System.out.println("Java:LongestNonrepSubstr");
		longestnonrepsubstr test = new longestnonrepsubstr();
		String s = new String("abcabcbb");
		int result = test.findLongNonRepStr(s);
		System.out.println(s);
		System.out.println(result);
	}
}
