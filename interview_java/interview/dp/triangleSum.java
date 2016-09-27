package dp;

import java.util.*;


public class triangleSum {
	public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
		if (triangle == null || triangle.size() == 0) return 0;
		List<Integer> path = new ArrayList<Integer>(triangle.get(triangle.size()-1));
		
		for(int row = triangle.size() - 2; row >= 0; row--) {
			for (int col = 0; col < triangle.get(row+1).size()-1; col++) {
				int tmp = Math.min(path.get(col), path.get(col+1)) + triangle.get(row).get(col);
				path.set(col, tmp);
			}
		}
		
		return path.get(0);
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		triangleSum test = new triangleSum();
		
		ArrayList<ArrayList<Integer>> triangle = new ArrayList<ArrayList<Integer>>();	
		ArrayList<Integer> list1 = new ArrayList<Integer>();
		list1.add(2);
		ArrayList<Integer> list2 = new ArrayList<Integer>();
		list2.add(3);
		list2.add(4);
		ArrayList<Integer> list3 = new ArrayList<Integer>();
		list3.add(6);
		list3.add(5);
		list3.add(7);
		ArrayList<Integer> list4 = new ArrayList<Integer>();
		list4.add(4);
		list4.add(1);
		list4.add(8);
		list4.add(3);
		
		triangle.add(list1);
		triangle.add(list2);
		triangle.add(list3);
		triangle.add(list4);
		
		int ans = test.minimumTotal(triangle);
		System.out.println(ans);

	}

}
