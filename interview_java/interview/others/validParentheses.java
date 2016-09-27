package others;

import java.util.*;

public class validParentheses {

	public boolean isValid(String s) {
		if (s == null || s.length() == 0) return false;
		
		Map<Character,Character> map = new HashMap<Character,Character>();
		map.put(')', '(');
		map.put('}', '{');
		map.put(']', '[');
		
/*		Set<Character> set = new HashSet<Character>();
		set.add('(');
		set.add('{');
		set.add('[');
*/		
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
		
		if (test.isValid(s)) System.out.println("Valid");
		else System.out.println("Not Valid");		
		if (test.isValid(s2)) System.out.println("Valid");
		else System.out.println("Not Valid");		

	}

}
