package others;

public class containMostWater {
	
	public int maxArea(int[] height) {
		if(height == null || height.length < 2) return 0;
		
		int left = 0;
		int right = height.length-1;
		int max = 0;
		
		while(left < right) {
			int w = right-left;
			int h = Math.min(height[left], height[right]);
			max = Math.max(max, w*h);
			if (height[left] < height[right]) left++;
			else right--;
		}
		
		return max;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		containMostWater test = new containMostWater();
		int[] height = {1,3,2,4,5,6,10,2};
		int ans = test.maxArea(height);
		System.out.println(ans);
	}

}
