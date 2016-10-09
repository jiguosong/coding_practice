package strings;

public class palindrome {
	
	////////////////////////////////////////
	/// if is a valid palindrome 
	////////////////////////////////////////
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
	
	////////////////////////////////////////
	/// shortest palindrome 
	////////////////////////////////////////
	
	public String shortestPalindrome_1(String s) {
		if(s == null || s.length() == 0) return null;
		
		int left = 0;
		int right = s.length()-1;
		
		while(right >= 0) {
			if(s.charAt(left) == s.charAt(right)) left++;
			right--;
		}
		
		if(left == s.length()) return s;
		
		String suffix = s.substring(left);
		StringBuilder sb = new StringBuilder(suffix);
		String prefix = sb.reverse().toString();
		String mid = shortestPalindrome_1(s.substring(0, left));
		
		return prefix+mid+suffix;		
	}
	
	
	public String shortestPalindrome_2(String s) {
		if(s == null || s.length() == 0) return null;
		
		int n = s.length();
		int mid = n/2;
		
		String res = null;
		for(int i = mid; i >= 1; i--) {
			if(s.charAt(i) == s.charAt(i-1)) {
				res = shortestPalindrome_helper(s, i-1, i);
				if(res != null) return res;
			} else {
				res = shortestPalindrome_helper(s, i-1, i-1);
				if(res != null) return res;
			} 
		}
		
		return res;
	}
	
	private String shortestPalindrome_helper(String s, int l, int r) {
		int i = 1;
		
		while(i <= l) {
			if(s.charAt(l-i) != s.charAt(r+i)) break;
			i++;
		}
		
		if(i <= l) return null;
		
		StringBuilder sb = new StringBuilder(s.substring(r+i));
		sb.reverse();
		return sb.append(s).toString();
	}
	
	////////////////////////////////////////
	/// longest palindrome 
	////////////////////////////////////////
	public String longestPalindrome_dp(String s) {
		if (s == null || s.length() == 0) return null;
		
		int n = s.length();
		
		boolean[][] isPali = new boolean[n][n];
		isPali[0][0] = true;
		
		int left = 0; 
		int right = 0;
		int len = 0;
		for(int j = 1; j < n; j++) {
			isPali[j][j] = true;
			for(int i = 0; i < j; i++) {
				isPali[i][j] = (s.charAt(i) == s.charAt(j)) && (j-i < 2 || isPali[i+1][j-1]) ;
				if (isPali[i][j] && len < j-i+1) {
					len = j-i+1;
					left = i;
					right = j;
				}
			}
		}
		
		return s.substring(left, right+1);
	}	
	
	public String longestPalindrome_2(String s) {
		if (s == null || s.length() == 0) return null;
		if(s.length() == 1) return s;
		
		int n = s.length();
		String max = s.substring(0,1);
		
		for(int i = 0; i < n; i++) {
			String tmp1 = longestPalindrome_helper(s, i, i);
			if(tmp1.length() > max.length()) max = tmp1;
			String tmp2 = longestPalindrome_helper(s, i, i+1);
			if(tmp2.length() > max.length()) max = tmp2;
		}

		return max;
	}
	
	private String longestPalindrome_helper(String s, int l, int r) {
		while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
			l--;
			r++;
		}
		
		return s.substring(l+1,r);		
	}
	
	/*public String findlongestPalindrome(String s) {
		String[] ret = new String[1];
		int[] len = new int[1];
		len[0] = 1;
		
		if (s == null || s.length() == 0) return null;
		
		if (s.length() == 1) {
			ret[0] = s;
			return ret[0];
		}
		if (s.charAt(0) == s.charAt(1)) {
			len[0] = 2;
			ret[0] = s.substring(0, 1);
		}
		
		for (int i = 1; i < s.length(); i++) {
			check(s, i-1, i+1, ret, len);
			if (i < s.length()-2 && s.charAt(i) == s.charAt(i+1)) {
				check(s, i-1, i+2, ret, len);
			}
		}		
		return ret[0];
	}
	
	private void check(String s, int j, int k, String[] ret, int[] len){
		while(j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
			j--;
			k++;
		}
		
		int tmp_len = k - j + 1 - 2;
		if (tmp_len > len[0]) {
			len[0] = tmp_len;
			ret[0] = s.substring(j+1, k);
		}
		
		return;
	}*/
	
	
	public static void main(String[] args) {
		palindrome test = new palindrome();
		
		if (test.isValidPalindromeStr("9Red rum, sir, is murder9")) System.out.println("yes it is a palindrome");
		else System.out.println("no it is not a palindrome");
		System.out.println();
		
		System.out.println("Longest Palindrome");
		String s = new String("bananas");
		String res = test.longestPalindrome_dp(s);
		System.out.println(res);

		res = test.longestPalindrome_2(s);
		System.out.println(res);
		//String res = test.findlongestPalindrome(s);
		//System.out.print(res);
			
		System.out.println();
		System.out.println("Shortest Palindrome");
		String s_shortest = "abcd";
		String ans = test.shortestPalindrome_1(s_shortest);
		System.out.println(ans);
		
		ans = test.shortestPalindrome_2(s_shortest);
		System.out.println(ans);
		
		

		return;
	}
	
}
