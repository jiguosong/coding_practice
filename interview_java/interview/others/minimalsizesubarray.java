package others;

public class minimalsizesubarray {
	public int minSubArrayLen(int s, int[] nums) {
		if (nums == null || nums.length == 0) return 0;
		
		int sum = 0;
		int tail = 0;
		int head = 0;
		
		int min_len = Integer.MAX_VALUE;
		
		while(head < nums.length) {
			if (sum < s) {
				sum += nums[head];
				head++;
			} else {
				min_len = Math.min(min_len, head - tail);				
				if (min_len == 1) return 1;
				sum -= nums[tail];
				tail++;				
			}
		}
		
		while(sum >= s) {
			min_len = Math.min(min_len, head - tail);	
			if (min_len == 1) return 1;
			sum -= nums[tail];
			tail++;
		}
		
		if (min_len == Integer.MAX_VALUE) return 0;
		else return min_len;
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		minimalsizesubarray test = new minimalsizesubarray();
		int s = 7;
		int[] nums = {2,3,1,2,4,3};
		int ans = test.minSubArrayLen(s, nums);
		System.out.println(ans);
	}

}
