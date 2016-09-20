package matrix;

import java.util.Arrays;

public class longestincreasingPath {
	
	public int longestIncreasingPath(int[][] matrix) {
		if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
		int res = 0;
		
		int row = matrix.length;
		int col = matrix[0].length;
		
		int[][] path = new int[row][col];
		for (int[] k : path) Arrays.fill(k, 0);

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int len = longestIncreasingPath_helper(matrix, i, j, path);
				res = Math.max(res, len);
			}
		}
		
		return res;
	}
	
	private int longestIncreasingPath_helper(int[][] matrix, int x, int y, int[][] path) {
		if (path[x][y] != 0) return path[x][y];
		
		int[] dx = {-1, 1, 0, 0};
		int[] dy = {0, 0, -1, 1};
		
		int len, curr_max;
		curr_max = path[x][y];		
		
		for (int i = 0; i < dx.length; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < matrix.length && ny >= 0 && ny < matrix[0].length && matrix[nx][ny] > matrix[x][y]) {
				len = longestIncreasingPath_helper(matrix, nx, ny, path);
				curr_max = Math.max(curr_max, len);
			}
		}
		
		path[x][y] = curr_max + 1;
		return path[x][y];
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		longestincreasingPath test = new longestincreasingPath();
//		int[][] matrix = {{3,4,5},
//		  		  		   {3,2,6},
//		  		  		   {2,2,1}};
		
		int[][] matrix = {{9,10,100},
		  		   		  {6,6,8},
		  		          {2,1,1}};
		
		int row = matrix.length;
		int col = matrix[0].length;		
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		
		int ans = test.longestIncreasingPath(matrix);
		System.out.println(ans);
	}

}
