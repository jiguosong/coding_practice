package math;

public class ispalindromenumber {
	public boolean ispalinum(int num){
		int k = 0;
		int p = num;
		
		while(p != 0) {
			k = k*10 + p%10;
			p = p/10;
		}
		
		return (k == num);
	}
	
	public static void main(String[] args) {
		System.out.println("Java:ispalindromenumber");
		ispalindromenumber test = new ispalindromenumber();
		int num = 123;
		if (test.ispalinum(num)) System.out.println("yes");
		else System.out.println("no");
	}

}
