package others;

import java.util.*;

public class kthlargestinarray {
	
	public int findKthLargest(int[] nums, int k) {
		if(nums == null || nums.length == 0 || k <= 0) return 0;
		
		Queue<Integer> pq = new PriorityQueue<Integer>();
		
		
		for(int e:nums) {
			pq.add(e);
			if(!pq.isEmpty() && pq.size() > k) pq.remove();  // throw (n-k) smallest item, eventaully we will have k largest in the heap
		}
		
		return pq.peek();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		kthlargestinarray test = new kthlargestinarray();
		int[] nums = {3,2,1,5,6,4};
		int k = 3;
		int ans = test.findKthLargest(nums, 1);
		System.out.println(ans);
	}

}
