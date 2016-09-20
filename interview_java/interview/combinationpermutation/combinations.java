package combinationpermutation;

import java.util.*;

public class combinations {
	public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> tmp = new ArrayList<Integer>();
        
        if (n <= 0 || n < k) return res;
        
        combine_helper(n, k , 1, tmp, res);
        
        return res;
    }
	
	public static void combine_helper(int n, int k, int level, List<Integer> tmp, List<List<Integer>> res) {
		if (tmp.size() == k) {
			res.add(new ArrayList<Integer>(tmp));
			return;			
		}
		
		for (int i = level; i <= n; i++) {
			tmp.add(i);
			combine_helper(n, k , i+1, tmp, res);
			tmp.remove(tmp.size()-1);
		}
		
		return;		
	}
	
	public static void main(String[] args){
		
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		System.out.println("Java:combination");
		
		combinations test = new combinations();
		
		int n = 4;
		int k =2;
		
		result = test.combine(n, k);
		
		for (List<Integer> E : result){
			System.out.println(E);
		}
				
		
	}
	
}
