package matrix;

public class numberofIsland {
	
	public int numIslands(char[][] grid) {
		if (grid == null) return 0;
		int m = grid.length;
		int n = grid[0].length;
		
		if (m ==0 && n == 0) return 0;
		
		int ans = 0;
		for (int i = 0; i< m; i++) {
			for (int j = 0; j< n; j++) {
				if (grid[i][j] == '1') {
					ans++;
					numIslands_helper(grid, i, j);
				}
			}
		}
		
		return ans;		
	}
	
	private void numIslands_helper(char[][] grid, int x, int y) {
		if (x < 0 || y < 0 || x >= grid.length || y >= grid[0].length) return;
		if (grid[x][y] == '0' || grid[x][y] == '2') return;
		
		grid[x][y] = '2';
		
		numIslands_helper(grid, x-1, y);
		numIslands_helper(grid, x+1, y);
		numIslands_helper(grid, x, y-1);
		numIslands_helper(grid, x, y+1);
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		numberofIsland test = new numberofIsland();
		
		char[][] matrix  = {{'1','1','0','1','0'},
							{'1','1','0','1','0'},
							{'1','1','0','0','1'},
							{'0','0','0','0','0'}};
		
		int row = matrix.length;
		int col = matrix[0].length;		
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		
		int res = test.numIslands(matrix);
		System.out.println(res);
	}

}
