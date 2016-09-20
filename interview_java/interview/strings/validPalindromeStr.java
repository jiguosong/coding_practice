package strings;

public class validPalindromeStr {
	public boolean isValidPalindromeStr(String s){
		if (s == null) return false;
		if (s.length() == 0) return true;
		
		s = s.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
		System.out.println(s);
		
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length()-1-i)) return false;
		}
		
		return true;		
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		validPalindromeStr test = new validPalindromeStr();
		if (test.isValidPalindromeStr("Red rum, sir, is murder")) System.out.println("yes");
		else System.out.println("no");

	}

}
