package matrix;

public class painthouse {

	public int minCost(int[][] costs) {
		if (costs == null) return 0;
		
		int row = costs.length;
		int col = costs[0].length;
		if (row == 0 || col == 0) return 0;
		
		for (int i = 1; i < row; i++) {
			costs[i][0] += Math.min(costs[i-1][1], costs[i-1][2]);
			costs[i][1] += Math.min(costs[i-1][0], costs[i-1][2]);
			costs[i][2] += Math.min(costs[i-1][1], costs[i-1][0]);
		}
		
		return Math.min(Math.min(costs[row-1][0], costs[row-1][1]), 
						 costs[row-1][2]);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		painthouse test = new painthouse();
		int[][] costs = {{2, 3, 4}, 
						 {20, 1, 3},
						 {19, 9, 1},
						 {7, 18, 4},
						 {91, 3, 2}};
		int ans = test.minCost(costs);
		System.out.println(ans);
		

	}

}
