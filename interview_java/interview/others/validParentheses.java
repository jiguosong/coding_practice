package others;

import java.util.*;

public class validParentheses {
	
	// Given a string containing just the characters '(' and ')', find the length of the longest valid parenthesis
	public int longestValidParentheses(String s) {
		if (s == null || s.length() == 0) return 0;
		
		Deque<int[]> stack = new ArrayDeque<int[]>();
		
		int res  = Integer.MIN_VALUE;
		
		for(int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if(c == '(') {
				int[] tmp = {i, 0};           // 0 is for left "("
				stack.push(tmp);
			} else {
				if(stack.isEmpty() || stack.peek()[1] == 1) {
					int[] tmp = {i, 1};       // 1 is for right ")"
					stack.push(tmp);
				} else {
					stack.pop();
					int current_len = 0;
					if(stack.isEmpty()) current_len = i+1;
					else current_len = i - stack.peek()[0];
					res = Math.max(res, current_len);
				}
			}
		}
		
		return res;		
	}

 
	public boolean isValid(String s) {
		if (s == null || s.length() == 0) return false;
		
		Map<Character,Character> map = new HashMap<Character,Character>();
		map.put(')', '(');
		map.put('}', '{');
		map.put(']', '[');
		
		Deque<Character> stack = new ArrayDeque<Character>();
		
		char[] chars = s.toCharArray();
		for (int i = 0; i < chars.length; i++) {
			if (map.containsKey(chars[i])) {
				if(stack.isEmpty()) return false;
				char c = stack.pop();
				if (c != map.get(chars[i])) return false;
			} else if (map.containsValue(chars[i])) {
				stack.push(chars[i]);				
			}
		}
		
		return stack.isEmpty();
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		validParentheses test = new validParentheses();
		String s = "()[]{}";
		String s2 = "([)]";	
		String s3 = ")()())";
		
		if (test.isValid(s)) System.out.println("Valid");
		else System.out.println("Not Valid");		
		if (test.isValid(s2)) System.out.println("Valid");
		else System.out.println("Not Valid");
		
		int ans = test.longestValidParentheses(s3);
		System.out.println(ans);
	}

}
