package strings;

import java.util.*;

// it helps to understand the problem from my DP model

public class minimumWindowSubstr {
	
	public String minWindow(String s, String t) {
		if(s == null || t == null || s.length() == 0 || t.length() == 0) return null;
		String res = null;
		
		Map<Character, Integer> source_map = new HashMap<Character, Integer>();
		Map<Character, Integer> target_map = new HashMap<Character, Integer>();
		
		for(Character e : t.toCharArray()){
			if(!target_map.containsKey(e)) target_map.put(e, 1);
			else target_map.put(e, target_map.get(e)+1);
		}
		
		int minWindow = 0;
		int count = 0;
		int left = 0;
		for(int i = 0; i < s.length(); i++) {
			Character c = s.charAt(i);
			
			if(target_map.containsKey(c)) {
				if(!source_map.containsKey(c)) {
					source_map.put(c, 1);
					count++;
				} else {
					if(source_map.get(c) < target_map.get(c)) count++;
					source_map.put(c, source_map.get(c)+1);
				}				
			}
			
			if(count == t.length()) {
				Character left_char = s.charAt(left);
				while(!source_map.containsKey(left_char) || source_map.get(left_char) > target_map.get(left_char)) {  // for example, S can be all the same char
					if(source_map.containsKey(left_char) && source_map.get(left_char) > target_map.get(left_char)) {
						source_map.put(left_char, source_map.get(left_char) - 1);
					}
					left++;
					left_char = s.charAt(left);
				}
				
				minWindow = i - left + 1;
				res = s.substring(left,  left+minWindow);				
			}			
		}
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		minimumWindowSubstr test = new minimumWindowSubstr();
		String s = "ADOBECODEBANC";
		String t = "ABC";
		String ans = test.minWindow(s, t);
		System.out.println(ans);
	}

}
