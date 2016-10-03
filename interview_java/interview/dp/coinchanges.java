package dp;

import java.util.Arrays;

public class coinchanges {	
	public int coinChange(int[] coins, int amount) {
		if(coins == null || coins.length == 0 || amount <=0) return -1;
		
		int res = 0;
		int[] min_coins_forvalue = new int[amount+1];
		min_coins_forvalue[0] = 0;
		
		for(int i = 1; i <= amount; i++) {
			min_coins_forvalue[i] = amount+1;  // just make it more than amount, say Integer.MAX
			for(int j = 0; j < coins.length; j++) {
				if(i >= coins[j]) {
					min_coins_forvalue[i] = Math.min(min_coins_forvalue[i], min_coins_forvalue[i-coins[j]] + 1);
				}
			}
		}
		
		if(min_coins_forvalue[amount] > amount) res = -1;   // see above comment
		else res = min_coins_forvalue[amount];
		
		return res;
	}
	


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		coinchanges test = new coinchanges();
		int[] coins = {1,2,5};
		int amount = 11;
		
		int ans = test.coinChange(coins, amount);
		System.out.println(ans);

	}

}
