package others;

import java.util.*;

public class hindex {
	
	public int hIndex(int[] citations) {
		if(citations == null || citations.length ==0) return 0;
		
		Integer[] sorted_array = new Integer[citations.length];
		int j = 0;
		for (int value : citations) {
			sorted_array[j++] = Integer.valueOf(value);
		}
		
		Arrays.sort(sorted_array, Collections.reverseOrder());
		
		for (int value : sorted_array) {
			System.out.print(value + " ");
		}
		for(int i = 0; i < sorted_array.length; i++) {
			//if(i >= sorted_array[i]) return i;
		}
		
		System.out.println();
		Arrays.sort(citations);
		for (int value : citations) {
			System.out.print(value + " ");
		}
		
		for(int i = 0; i < citations.length; i++) {
			if(citations.length-i <= citations[i]) return citations.length-i;
		}
		
		
		return 0;
		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		hindex test = new hindex();
		
		int[] citations = {3,0,6,1,5};
		
		int ans = test.hIndex(citations);
		System.out.println();
		System.out.println(ans);

	}

}
