package strings;

import java.util.*;

public class palindromepairs {
	
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
	
	private void add_one_result(String str, int i, Map<String, Integer> map, List<List<Integer>> res){
		String reverse_str = new StringBuilder(str).reverse().toString();
		if(map.containsKey(reverse_str) && map.get(reverse_str) != i) {
			List<Integer> tmp = new ArrayList<Integer>();
			tmp.add(i);
			tmp.add(map.get(reverse_str));
			res.add(tmp);
		}
	}
	
	public List<List<Integer>> palindromePairs(String[] words) {
		if(words == null || words.length == 0) return null;
		
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		Map<String, Integer> map = new HashMap<String, Integer>();
			
		for(int i = 0; i < words.length; i++) map.put(words[i],i);
		
		for(int i = 0; i < words.length; i++) {
			String str = words[i];
			
			//case 0:
			if(isPalindrome(str) && map.containsKey("")) {
				if(map.containsKey("") && map.get("") != i) {
					List<Integer> tmp = new ArrayList<Integer>();
					tmp.add(i);
					tmp.add(map.get(""));
					res.add(tmp);
					
					tmp = new ArrayList<Integer>();
					tmp.add(map.get(""));
					tmp.add(i);
					res.add(tmp);
				}				
			}
			
			//case 1 : ab  ba
			add_one_result(str, i, map, res);

			// case 2: abc ba
			for(int k = 1; k < str.length(); k++) {
				String left = str.substring(0,k);
				String right = str.substring(k);				
				if(isPalindrome(left)) add_one_result(right, i, map, res);
				if(isPalindrome(right)) add_one_result(left, i, map, res);			
			}
			
		}
				
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		palindromepairs	test = new palindromepairs();
		String[] words = {"bat", "tab", "cat", "abcdcba", ""};
		List<List<Integer>> ans = test.palindromePairs(words);
		Iterator<List<Integer>> it = ans.iterator();
		while(it.hasNext()) {
			List<Integer> e = it.next();
			System.out.println(e);
		}
		System.out.println();
		String[] words2 = {"abcd", "dcba", "lls", "s", "sssll"};
		ans = test.palindromePairs(words2);
		it = ans.iterator();
		while(it.hasNext()) {
			List<Integer> e = it.next();
			System.out.println(e);
		}
		
		
		
	}

}
