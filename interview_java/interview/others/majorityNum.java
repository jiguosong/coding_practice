package others;

public class majorityNum {
	
	
	public int majorityElement(int[] num) {
		if(num == null || num.length == 0) return -1;
		
		int res = 0;
		int level = 0;
		for(int i = 0; i < num.length; i++) {
			if(level == 0) {
				res = num[i];
				level++;
			} else if(num[i] == res) level++;
			else level--;
		}	
		
		return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		majorityNum test = new majorityNum();
		int[] num = {1,2,3,4,2,1,1,2,2};
		int ans = test.majorityElement(num);
		System.out.println(ans);
		

	}

}
