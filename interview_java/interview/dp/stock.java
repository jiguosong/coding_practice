package dp;

//Best Time to Buy and Sell Stock 

public class stock {
	
	// only permitted to complete at most one transaction 
	public int maxProfit_one(int[] prices) {
		if(prices == null || prices.length == 0) return 0;
		
		int max_profit_sofar = 0;
		int min_price = prices[0];
		
		for(int i = 1; i < prices.length; i++) {
			max_profit_sofar = Math.max(max_profit_sofar, prices[i] - min_price);
			min_price = Math.min(min_price, prices[i]);  // this has to be updated after updating max_profit_sofar
		}
		
		return max_profit_sofar;
	}

	// complete as many transactions as you like (i.e, buy one and sell one share of the stock multiple times). 
	// you must sell the stock before you buy again
	public int maxProfit_many(int[] prices) {
		if(prices == null || prices.length == 0) return 0;
		
		int max_profit_sofar = 0;
		
		for(int i = 1; i < prices.length; i++) {
			max_profit_sofar += (prices[i] > prices[i-1]) ? prices[i] - prices[i-1] : 0;
		}
		
		return max_profit_sofar;
	}
	
	// complete at most two transactions
	public int maxProfit_two(int[] prices) {
		if(prices == null || prices.length == 0) return 0;
		
		int n = prices.length;
		int[] max_profit_from_left = new int[n]; 
		int[] max_profit_from_right = new int[n];
		int res = 0;
		
		// from left (one transaction before i)
		max_profit_from_left[0] = 0;
		int min = prices[0];
		for(int i = 1; i < n; i++) {
			min = Math.min(min, prices[i]);
			max_profit_from_left[i] = Math.max(max_profit_from_left[i-1], prices[i]-min);
		}
		
		// from right (one transaction after i)
		max_profit_from_left[n-1] = 0;
		int max = prices[n-1];
		for(int i = n-2; i >= 0; i--) {
			max = Math.max(max, prices[i]);
			max_profit_from_right[i] = Math.max(max_profit_from_right[i+1], max-prices[i]);
		}
		
		
		for(int i = 0; i < n; i++) {
			res  = Math.max(res, max_profit_from_left[i] + max_profit_from_right[i]);
		}
		
		return res;
	}
	
	
	// complete at most k transactions
	public int maxProfit(int k, int[] prices) {
		if(prices == null || prices.length == 0) return 0;
		int n = prices.length;
		
		int[][] global_profit = new int[n][k+1];
		int[][] local_profit = new int[n][k+1];
		
		for(int i = 1; i < n; i++) {
			int diff = prices[i] - prices[i-1];
			for(int j = 1; j <= k; j++) {
				local_profit[i][j] = Math.max(global_profit[i-1][j-1] + Math.max(diff, 0), local_profit[i-1][j] + diff);
				global_profit[i][j] = Math.max(global_profit[i-1][j], local_profit[i][j]);
			}
		}
		
		return global_profit[n-1][k];
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		stock test = new stock();
		int[] prices = {1,-2,3,-1,6};
		int ans = test.maxProfit_one(prices);
		System.out.println(ans);
		
		ans = test.maxProfit_many(prices);
		System.out.println(ans);

		int[] prices2 = {1,3,2,9};
		ans = test.maxProfit_two(prices2);
		System.out.println(ans);

		ans = test.maxProfit(2, prices2);
		System.out.println(ans);
	}

}
