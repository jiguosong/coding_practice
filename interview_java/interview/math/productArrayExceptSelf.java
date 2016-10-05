package math;

import java.util.Arrays;

public class productArrayExceptSelf {
	// this is similar to the buy/sell stock
	public int[] productExceptSelf(int[] nums) {
		if(nums == null || nums.length ==0) return null;
		
		int n = nums.length;
		int[] res = new int[n];
		res[n-1] = 1;
		
		for(int i = n-2; i >= 0; i--) {
			res[i] = res[i+1]*nums[i+1];
		}
		
		int left = 1;
		for(int i = 0; i < n; i++) {
			res[i] = res[i]*left;
			left = left*nums[i];
		}	
		
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		productArrayExceptSelf test  = new productArrayExceptSelf();
		int[] nums = {1,2,3,4};
		int[] ans = test.productExceptSelf(nums);
		System.out.print(Arrays.toString(ans));
	}

}
