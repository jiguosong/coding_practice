package matrix;

import java.util.*;

public class bestmeeting {	
	public int minTotalDistance(int[][] grid) {
		if (grid == null) return 0;
		int row = grid.length;
		int col = grid[0].length;
		
		if (row == 0 || col == 0) return 0;
		
		List<Integer> x_pos = new ArrayList<Integer>();
		List<Integer> y_pos = new ArrayList<Integer>();
		
		for (int i = 0; i < row; i++) { 
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1) {
					x_pos.add(i);
					y_pos.add(j);
				}
			}
		}
		
		Collections.sort(x_pos);
		Collections.sort(y_pos);
		
		int ans = 0;
		
		int start = 0;
		int end = x_pos.size() - 1;
		
		while (start < end) {
			ans += x_pos.get(end)-x_pos.get(start) + y_pos.get(end)-y_pos.get(start);
			start++;
			end--;
		}
		
		System.out.println("x_pos median " + x_pos.get(x_pos.size()/2));
		System.out.println("y_pos median " + y_pos.get(y_pos.size()/2));
		
		return ans;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		bestmeeting test=  new bestmeeting();
		
		int[][] matrix = {{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};

		int row = matrix.length;
		int col = matrix[0].length;		
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		
		
		int ans = test.minTotalDistance(matrix);		
		System.out.println(ans);
		
	}

}
