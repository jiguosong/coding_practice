package others;

import java.util.*;

public class slidingwindow {
	
	public int[] maxSlidingWindow(int[] nums, int k) {
		if(nums == null || nums.length == 0) return null;
		
		int[] res = new int[nums.length+1-k];
		
		Deque<Integer> deque = new LinkedList<Integer>();
		
		for(int i = 0; i< nums.length; i++) {
			if(!deque.isEmpty() && deque.peekFirst() == i-k) deque.poll();
			while(!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) deque.removeLast();
			
			deque.add(i);
			if(i+1-k >= 0) res[i+1-k] = nums[deque.peekFirst()];	
		}
		
		return res;		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		slidingwindow test = new slidingwindow();
		
		int[] nums = {1,3,-1,-3,5,3,6,7};
		int k = 3;		
		int[] ans = test.maxSlidingWindow(nums, k);
		System.out.println(Arrays.toString(ans));
	}

}
