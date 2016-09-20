package strings;

import java.util.*;

public class partitionpalindrome {
	
	private boolean isPalindrome(String s){
		int l = 0;
		int r = s.length() - 1;
		
		while(l < r) {
			if (s.charAt(l) != s.charAt(r)) return false;			
			l++;
			r--;
		}
		
		return true;
	}
	

	private void doPartitionpalindrome_helper(String s, int level, 
												  List<String> tmp, List<List<String>> res){
		if (level == s.length()) {
			res.add(new ArrayList<String>(tmp));
			return;
		}
		
		for (int i = level; i < s.length(); i++) {
			String tmp_str = s.substring(level, i+1);
			if (isPalindrome(tmp_str)) {
				tmp.add(tmp_str);
				doPartitionpalindrome_helper(s, i+1, tmp, res);
				tmp.remove(tmp.size()-1);
			}
		}	
		
		return;
	}
	
	public List<List<String>> doPartitionpalindrome(String s) {
		List<List<String>> res = new ArrayList<List<String>>();
		List<String> tmp = new ArrayList<String>();
		
		if (s == null || s.length() == 0) return res;
		
		doPartitionpalindrome_helper(s, 0, tmp, res);
		
		return res;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Java:partitionpalindrome");
		partitionpalindrome test = new partitionpalindrome();
		List<List<String>> res = new ArrayList<List<String>>();
		
		res = test.doPartitionpalindrome("aab");
		
		Iterator<List<String>> its = res.iterator();
		
		while(its.hasNext()) {
			List<String> tmp = its.next();
			Iterator<String> it = tmp.iterator();
			System.out.print("[ ");
			while(it.hasNext()) {
				System.out.print(it.next() + ", ");
			}
			System.out.println(" ]");
		}
		
	}

}
