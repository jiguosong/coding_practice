package matrix;

public class unqieupath {
	
	public int uniquePaths(int m, int n) {
		if (m < 0 && n < 0) return 0;
		if (m == 0 || n == 0) return 1;
		
		return uniquePaths_helper(m, n, 0, 0);
	}
	
	private int uniquePaths_helper(int row, int col, int x, int y) {
		if (x == row - 1 && y == col - 1) return 1;
		
		if (x < row - 1 && y < col - 1) {
			return uniquePaths_helper(row, col, x+1, y) +  
				    uniquePaths_helper(row, col, x, y+1);
		}
		
		if (x < row - 1) return uniquePaths_helper(row, col, x+1, y);
		if (y < col - 1) return uniquePaths_helper(row, col, x, y+1);
		
		return 0;
	}

	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;
		if (m < 0 && n < 0) return 0;
		
		return uniquePaths_helper2(obstacleGrid, m, n, 0, 0);
	}
	
	private int uniquePaths_helper2(int[][] matrix, int row, int col, int x, int y) {
		if (x == row - 1 && y == col - 1) return 1;		
		if (x < row - 1 && y < col - 1 && matrix[x][y] == 1) return 0;
		
		if (x < row - 1 && y < col - 1) {
			return uniquePaths_helper2(matrix, row, col, x+1, y) +  
				    uniquePaths_helper2(matrix, row, col, x, y+1);
		}
		
		if (x < row - 1) return uniquePaths_helper2(matrix, row, col, x+1, y);
		if (y < col - 1) return uniquePaths_helper2(matrix, row, col, x, y+1);
		
		return 0;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		unqieupath test = new unqieupath();
		int m = 3;
		int n = 3;
		int res = test.uniquePaths(3, 3);
		
		System.out.println(res);
		
		int[][] matrix = {{0,0,0},
						  {0,1,0},
						  {0,0,0}};
		
		res = test.uniquePathsWithObstacles(matrix);
		System.out.println(res);

	}

}
