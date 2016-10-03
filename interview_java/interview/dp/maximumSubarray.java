package dp;

public class maximumSubarray {
	
	public int maxProduct(int[] nums) {
		if(nums == null || nums.length == 0) return 0;

		int[] maxprod = new int[nums.length];
		int[] minprod = new int[nums.length];
		maxprod[0] = nums[0];
		minprod[0] = nums[0];
		
		int max = Integer.MIN_VALUE;
		
		for(int i = 1; i < nums.length; i++) {
			if(nums[i] > 0) {
				maxprod[i] = Math.max(nums[i], maxprod[i-1]*nums[i]);
				minprod[i] = Math.max(nums[i], minprod[i-1]*nums[i]);
			} else {
				maxprod[i] = Math.max(nums[i], minprod[i-1]*nums[i]);
				minprod[i] = Math.max(nums[i], maxprod[i-1]*nums[i]);
			}
			
			max = Math.max(max, maxprod[i]);
		}
		
		return max;	
	}
	
	public int maxSubArraySum(int[] A) {
		if(A == null || A.length == 0) return 0;
		
		int[] sum = new int[A.length];
		sum[0] = A[0];
		
		int max = Integer.MIN_VALUE;
		
		for(int i = 1; i < A.length; i++) {
			sum[i] = Math.max(A[i], sum[i-1]+A[i]);
			max = Math.max(sum[i], max);
		}
		
		return max;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		maximumSubarray test = new maximumSubarray();
		int[] A = {1,2,3,4, -1,10,-7};
		int ans = test.maxSubArraySum(A);		
		System.out.println(ans);
		
		int[] B = {2,3,-2,4};
		ans = test.maxProduct(B);		
		System.out.println(ans);

	}

}
