package combinationpermutation;

import java.util.*;

public class permutation {
	public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> res = new ArrayList<List<Integer>>();
		List<Integer> tmp = new ArrayList<Integer>();
		boolean[] visited = new boolean[nums.length];
		
		if (nums == null || nums.length == 0) return res;
		
		permute_helper(nums, 0, visited, tmp ,res);
		
		return res;
	}
	
	private void permute_helper(int[] nums, int level, boolean[] visited,
								List<Integer> tmp, List<List<Integer>> res)
	{
		if (tmp.size() == nums.length) {
			res.add(new ArrayList<Integer>(tmp));
			return;
		}
		
		for (int i = 0; i < nums.length; i++) {
			if (visited[i] == true) continue;			
			visited[i] = true;
			
			tmp.add(nums[i]);
			permute_helper(nums, i+1, visited, tmp, res);
			
			visited[i] = false;
			tmp.remove(tmp.size()-1);
		}		
		return;
	}
	
	public static void main(String[] args) {
		permutation test = new permutation();
		int[] nums = new int[] {1,2,3};
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		result = test.permute(nums);
		System.out.println(result);
	}	
}
