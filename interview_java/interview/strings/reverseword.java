package strings;

public class reverseword {
	
	private void reverse(char[] s, int l, int r) {
		while (l < r) {
			char tmp = s[l];
			s[l] = s[r];
			s[r] =tmp;
			l++;
			r--;
		}		
	}
	
	public void reverseWords(char[] s) {
		if (s == null || s.length == 0) return;
		
		System.out.println(new String(s));	
		int j = 0;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == ' ') {
				reverse(s, j, i-1);
				j = i+1;
			}			
		}
		reverse(s, j, s.length-1);
		reverse(s, 0, s.length-1);
		System.out.println(new String(s));
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String str = "this is a test";
		reverseword test = new reverseword();
		test.reverseWords(str.toCharArray());
	}

}
