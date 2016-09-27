package others;

import java.util.Arrays;

public class candy {
	public int candycopy(int[] ratings) {  // copy from web to compare the result
		if (ratings == null || ratings.length == 0) {
			return 0;
		}
	 
		int[] candies = new int[ratings.length];
		candies[0] = 1;
	 
		//from let to right
		for (int i = 1; i < ratings.length; i++) {
			if (ratings[i] > ratings[i - 1]) {
				candies[i] = candies[i - 1] + 1;
			} else { 
				// if not ascending, assign 1
				candies[i] = 1;
			}
		}
	 
		int result = candies[ratings.length - 1];
	 
		//from right to left
		for (int i = ratings.length - 2; i >= 0; i--) {
			int cur = 1;
			if (ratings[i] > ratings[i + 1]) {
				cur = candies[i + 1] + 1;
			}
	 
			result += Math.max(cur, candies[i]);
			candies[i] = cur;
		}
	 
		return result;
	}
	
	public int candysolver(int[] ratings) {
		if (ratings == null || ratings.length == 0) return 0;
		int res = 0;
		
		int[] candy = new int[ratings.length];
		Arrays.fill(candy, 1);
		
		// left to right
		for (int i = 1; i < ratings.length ; i++) {
			if (ratings[i] > ratings[i-1]) candy[i] = candy[i-1] + 1;
		}
		
		// right to left
		for (int i = ratings.length - 2; i > 0 ; i--) {
			if (ratings[i] > ratings[i+1] && candy[i] < candy[i+1]) candy[i] = candy[i+1] + 1;
		}
		
		for (int i = 0; i < ratings.length ; i++) {
			res += candy[i];
		}
		
		return res;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		candy test = new candy();
		int[] ratings = {1,2,0,1,2,3,2};
		int ans = test.candysolver(ratings);
		int ans2 = test.candycopy(ratings);
		System.out.println(ans);
		
		if (ans != ans2) System.out.println("wrong!!!!");
		

	}

}
