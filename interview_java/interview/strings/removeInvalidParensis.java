package strings;

import java.util.*;

public class removeInvalidParensis {
	
	 int max = 0;
	
	 public List<String> removeInvalidParentheses(String s) {
		 if(s == null || s.length() == 0) return null;
		 
		 List<String> res = new ArrayList<String>();
		 
		 removeInvalidParentheses_helper(s, "", 0, 0, res);
		 
		 return res;
	 }
	
	 private void removeInvalidParentheses_helper(String left_str, String result_str, 
			 										  int stack, int maxleft, List<String>res) {
		 if(left_str.length() == 0 && stack == 0 && result_str.length() != 0) {
			 if(maxleft > max) max = maxleft;
			 if(max == maxleft && !res.contains(result_str)) res.add(result_str);
		 }
		 
		 if(left_str.length() == 0) return;
		 		 
		 if(left_str.charAt(0) == '(') {
			 removeInvalidParentheses_helper(left_str.substring(1), result_str + "(", stack+1, maxleft+1, res);
			 removeInvalidParentheses_helper(left_str.substring(1), result_str, stack, maxleft, res);
		 } else if (left_str.charAt(0) == ')') {
			 if(stack > 0) removeInvalidParentheses_helper(left_str.substring(1), result_str + ")", stack-1, maxleft, res);
			 removeInvalidParentheses_helper(left_str.substring(1), result_str, stack, maxleft, res);
		 } else {
			 removeInvalidParentheses_helper(left_str.substring(1), result_str+String.valueOf(left_str.charAt(0)), stack, maxleft, res);
		 }
		 
		 return;
	 }
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		removeInvalidParensis test = new removeInvalidParensis();
		String s = "()())()";
		List<String> ans = test.removeInvalidParentheses(s);
		System.out.println(ans);
	
		}
	
	}
