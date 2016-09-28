package others;

public class flipGame {
	
	public boolean canWin(String s) {
		if(s == null || s.length() == 0) return false;
		
		return canWin_helper(s.toCharArray());		
	}
	
	private boolean canWin_helper(char[] s) {
		for(int i = 1; i < s.length; i++) {
			if(s[i] == '+' && s[i-1] == '+') {
				
				s[i] = '-';
				s[i-1] = '-';
				
				boolean res = canWin_helper(s);
				
				s[i] = '+';
				s[i-1] = '+';
				
				if(res == false) return true;				
			}
		}
		return false;		
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		flipGame test = new flipGame();
		String s = "++++";
		if(test.canWin(s)) System.out.println("Win");
		else System.out.println("Loose");

	}

}
