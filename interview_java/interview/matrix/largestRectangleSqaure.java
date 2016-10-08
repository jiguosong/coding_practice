package matrix;

import java.util.*;

public class largestRectangleSqaure {
	
	public int maximalSquare(char[][] matrix) {
		if (matrix == null) return 0;
		int row = matrix.length;
		int col = matrix[0].length;
		if (row == 0 && col == 0) return 0;

		int[][] area = new int[row][col];
				
		for (int i = 0; i < row; i++) area[i][0] = Character.getNumericValue(matrix[i][0]);
		for (int j = 0; j < col; j++) area[0][j] = Character.getNumericValue(matrix[0][j]);
		
		int ans= 0;
		int x = 0;
		int y = 0;
		
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (matrix[i][j] == '1') {
					area[i][j] = Math.min(area[i-1][j], Math.min(area[i][j-1], area[i-1][j-1]))+1;
					if (area[i][j] >= ans) {
						ans = area[i][j];
						x = i;
						y = j;
					}
				} else {
					area[i][j] = 0;
				}
			}
		}		
		
		System.out.println(x);
		System.out.println(y);		
		return ans;		
	}
	
	public int maximalRectangle(char[][] matrix) {
		if (matrix == null) return 0;
		int row = matrix.length;
		int col = matrix[0].length;
		if (row == 0 && col == 0) return 0;
		
		int ans = 0;		
		int[][] heights = new int[row][col];
		
		for (int j = 0; j < col; j++) {
			if (matrix[0][j] == '0') heights[0][j] = 0;
			else heights[0][j] = 1;
		}
		
		for (int i = 1; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '0') heights[i][j] = 0;
				else heights[i][j] = heights[i-1][j]+1;
			}
		}
		
		for (int i = 0; i < row; i++) {
			int tmp = largestRectangleArea(heights[i]);
			ans = Math.max(ans, tmp);
		}
		
		return ans;
		
	}
	
	
	/*Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
	find the area of largest rectangle in the histogram*/	
	public int largestRectangleArea(int[] height) {
		if (height == null || height.length == 0) return 0;
		
		Deque<Integer> stack = new ArrayDeque<Integer>();
		int i = 0;
		int area = 0;
		
		while(i < height.length) {
			if (stack.isEmpty() || height[i] >= height[stack.peek()]) {
				stack.push(i);
				i++;
			} else {
				int idx = stack.pop();
				int h = height[idx];
				int width;
				if (stack.isEmpty()) width = i;
				else width = i - 1 - stack.peek();
				area = Math.max(area, width*h);
			}
		}
		
		while(!stack.isEmpty()) {
			int idx = stack.pop();
			int h = height[idx];
			int width;
			if (stack.isEmpty()) width = i;
			else width = i - 1 - stack.peek();
			area = Math.max(area, width*h);
		}
		 
		return area;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Java:largestRectangleAreaHistogram");
		largestRectangleSqaure test = new largestRectangleSqaure();
		int res, row, col;
		
		int[] height = {2,1,5,6,2,3};
		res = test.largestRectangleArea(height);
		System.out.println(Arrays.toString(height));
		System.out.println(res);
		
		System.out.println("Java:largestRectangleArea");
		char[][] matrix  = {{'1','0','1','0','0'},
							{'1','0','1','1','1'},
							{'1','1','1','1','1'},
							{'1','0','0','1','0'}};

		
		row = matrix.length;
		col = matrix[0].length;		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
		System.out.println();

		res = test.maximalRectangle(matrix);
		System.out.println(res);
		
		System.out.println("Java:largestSquare");
		
		char[][] matrix2  = {{'0','1','1','0','1'},
							{'1','1','1','1','0'},
							{'1','1','1','1','0'},
							{'1','1','1','1','0'},
							{'1','1','1','0','1'},
							{'0','0','0','0','0'}};
		row = matrix2.length;
		col = matrix2[0].length;		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print(matrix2[i][j]);
			}
			System.out.println();
		}
		System.out.println();

		res = test.maximalSquare(matrix2);
		System.out.println(res);
	}

}
