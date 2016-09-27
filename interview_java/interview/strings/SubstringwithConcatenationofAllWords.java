package strings;

// not finished yet

import java.util.*;

public class SubstringwithConcatenationofAllWords {
	
	//For example, given: s="barfoothefoobarman" & words=["foo", "bar"], return [0,9].
	
	public List<Integer> findSubstring(String s, String[] words) {
		if(s == null || s.length() == 0 || words == null || words.length ==0) return null;
		List<Integer> res = new ArrayList<Integer>();
		
		int step = words[0].length();
		
		Map<String, Integer> wordfrequency_map = new HashMap<String, Integer>();
		for(String e : words) {
			if(wordfrequency_map.containsKey(e)) {
				int tmp_cnt = wordfrequency_map.get(e);
				wordfrequency_map.put(e, tmp_cnt+1);
			} else {
				wordfrequency_map.put(e, 1);
			}
		}
		
		for(int i = 0; i < s.length(); i++) {
			
			Map<String, Integer> current_map = new HashMap<String, Integer>();
			int start = i;
			int count = 0;
			for(int j = i; j < s.length()-step; j = j+step) {
				String curr_s = s.substring(j, j+step);
				if(wordfrequency_map.containsKey(curr_s)) {
					if(current_map.containsKey(curr_s)) {
						int tmp_cnt = current_map.get(curr_s);
						current_map.put(curr_s, tmp_cnt+1);
					} else {
						current_map.put(curr_s, 1);
					}
					
					count++;
					
					while(current_map.get(curr_s) > wordfrequency_map.get(curr_s)) {
						
					}
					
				} else {
					
				}
			}
		}
		
		return res  
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
