package others;

import java.util.*;

public class sum2 {
	public static int[] findSum2(List<Integer> A, int sum){
		int[] res = new int[2];
		if (A == null || A.size() == 0) return res;
		
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		//Iterator<Integer> it = A.iterator();
		//while(it.hasNext()) {
		for (int i = 0; i < A.size(); i++) {
			map.put(A.get(i), i);
		}
		
		for (int i = 0; i < A.size(); i++) {
			int k = sum - A.get(i);
			if (map.containsKey(k) && (map.get(k) != i)) {
				res[0] = i;
				res[1] = map.get(k);
				break;
			}
		}
		return res;
	}	
	
	public static void main(String[] args){
		System.out.println("Java:sum2 test");
		
		List<Integer> input = new ArrayList<Integer>();
		input.add(10);
		input.add(2);
		input.add(3);
		input.add(4);
		input.add(5);
		input.add(6);
		
		int[] res = findSum2(input, 5);
		
		System.out.println(res[0]);
		System.out.println(res[1]);
		
		return;
	}
}


