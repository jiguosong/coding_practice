package others;

import java.util.*;

public class twosum {
	
	public List<List<Integer>> threeSum(int[] nums) {
		if (nums == null || nums.length == 0) return null;		
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		
		List<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < nums.length; i++) {
			list.add(nums[i]);
		}
		
		Collections.sort(list);
		
		for (int i = 0; i < list.size()-1; i++) {
			int target = nums[i];
			int[] res = findSum2(list.subList(i+1, list.size()), -target);
			if (res[0] != -1) {
				List<Integer> tmp = new ArrayList<Integer>();
				tmp.add(i);
				tmp.add(res[0]);
				tmp.add(res[1]);
				result.add(tmp);
			}
		}
		
		return result;		
	}
	
	
	public int[] findSum1(List<Integer> A, int sum){
		if (A == null || A.size() == 0) return null;		
		int[] res = new int[2];		
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		for (int i = 0; i < A.size(); i++) {
			if (map.containsKey(A.get(i))) {
				int index = map.get(A.get(i));
				res[0] = index;
				res[1] = i;
				break;
			} else {
				map.put(sum - A.get(i), i);
			}
			
		}
		return res;
	}
	
	// sorted list of integer
	public int[] findSum2(List<Integer> A, int sum){
		if (A == null || A.size() == 0) return null;		
		int[] res = {-1, -1};		
		
		int left = 0;
		int right = A.size()-1;
		
		while(left < right) {
			int tmp = A.get(left) + A.get(right);
			if (tmp == sum) {
				res[0] = left;
				res[1] = right;
				break;
			} else if (tmp < sum) {
				left++;
			} else {
				right--;
			}
		}
		
		return res;
		
	}
	
	public static void main(String[] args){
		twosum test = new twosum();
		
		Integer[] array = {10, 2, 3, 4, 5, 6};
		List<Integer> input = Arrays.asList(array);			
		int[] res = test.findSum1(input, 5);
		//System.out.println(array[res[0]]);
		//System.out.println(array[res[1]]);

		Integer[] array2 = {1, 2, 3, 4, 5, 6};
		List<Integer> input2 = Arrays.asList(array2);			
		int[] res2 = test.findSum2(input2, 6);
		System.out.println(array2[res2[0]]);
		System.out.println(array2[res2[1]]);
		
		int[] array3 = {-1, 0, 1, 2, -1, -4};
		List<List<Integer>> ans = test.threeSum(array3);
		
		Iterator<List<Integer>> it = ans.iterator();
		while(it.hasNext()) {
			System.out.println(it.next());
		}
		
		return;
	}
}


