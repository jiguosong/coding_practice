package others;

public class missingnumber {
	
	//	Given an unsorted integer array, find the first missing positive integer.
	public int firstMissingPositive(int[] A) {
		if(A == null || A.length ==0) return 0;
		
		int i = 0;
		while(i < A.length) {
			if(A[i] != i+1 && A[i] > 0 && A[i] <= A.length && A[i] != A[A[i]-1]) {
				int tmp = A[i];
				A[i] = A[A[i]-1];
				A[tmp-1] = tmp; 
			} else i++;
		}
		
		for(int j = 0; j < A.length; j++) {
			if(A[j] != j+1) return j+1;
		}
		
		return A.length+1;		
	}
	
	public int missingNumber(int[] nums) {
		if(nums == null || nums.length == 0) return 0;
		
		int left = 0;
		int right = nums.length;
		
		while(left < right) {
			int mid = left + (right-left)/2;			
			if(mid < nums[mid]) right = mid;
			else left = mid+1;			
		}
		
		return right;
	}

	public int missingNumber_xor(int[] nums) {
		if(nums == null || nums.length == 0) return 0;
		
		int res = 0;
	
		for(int i = 0; i < nums.length; i++) {
			res ^= nums[i]^(i+1);
		}
		
		return res;
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		missingnumber test = new missingnumber();
		int[] nums = {0,1,2,4,5};
		int ans = test.missingNumber(nums);
		System.out.println(ans);
		ans = test.missingNumber_xor(nums);
		System.out.println(ans);

		int[] nums2 = {3,4,-1,1};
		ans = test.firstMissingPositive(nums2);
		System.out.println(ans);

	}
}
