package strings;

public class lengthofLastword {
	
	public int lengthOfLastWord(String s) { 
		if (s == null || s.length() == 0) return 0;
		
		int res = 0;
		boolean flag = false;
		
		for(int i = s.length()-1; i>=0; i--) {
			char c = s.charAt(i);
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				res++;
				flag = true;
			} else if(flag) {
				break;
			}
		}
		
		return res;		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		lengthofLastword test = new lengthofLastword();
		String s = "Hello World";
		int ans = test.lengthOfLastWord(s);
		System.out.println(ans);
		

	}

}
