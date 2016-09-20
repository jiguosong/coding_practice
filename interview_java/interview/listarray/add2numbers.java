package listarray;

public class add2numbers {

	 public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		 if (l1 == null && l2 == null) return null;
		 if (l1 == null && l2 != null) return l2;
		 if (l1 != null && l2 == null) return l1;
		 
		 int carry = 0;
		 int sum = 0;
		 ListNode head = new ListNode(0);
		 ListNode p1 = l1;
		 ListNode p2 = l2;
		 ListNode k = head;
		 while (p1 != null && p2 != null) {
			 sum = p1.val+ p2.val + carry;
			 carry = sum/10;
			 k.next = new ListNode(sum%10);	
			 p1 = p1.next;
			 p2 = p2.next;
			 k = k.next; 
		 }
		 
		 while(p1 != null) {
			 sum = p1.val + carry;
			 carry = sum/10;
			 k.next = new ListNode(sum%10);
			 p1 = p1.next;
			 k = k.next;
		 }
		 
		 while(p2 != null) {
			 sum = p2.val + carry;
			 carry = sum/10;
			 k.next = new ListNode(sum%10);
			 p2 = p2.next;
			 k = k.next;
		 }
		 
		 if (carry != 0) {
			 k.next = new ListNode(carry);
		 }
		 		 
		 return head.next;
	 }
	 
	 
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		add2numbers test = new add2numbers();
		
		ListNode l1 = new ListNode(1);
		l1.next = new ListNode(2);
		l1.next.next = new ListNode(3);
		
		ListNode l2 = new ListNode(7);
		l2.next = new ListNode(8);
		l2.next.next = new ListNode(9);
		l2.next.next.next = new ListNode(9);

		ListNode ans = test.addTwoNumbers(l1, l2);
		
		while (ans != null) {
			System.out.println(ans.val);
			ans = ans.next;
		}
		
		

	}

}
