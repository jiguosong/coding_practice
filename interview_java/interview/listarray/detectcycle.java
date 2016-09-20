package listarray;

public class detectcycle {
	public boolean hasCycle(ListNode head) {
		if (head == null) return false;
		
		ListNode fast = head;
		ListNode slow = head;
		
		while(fast != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
			if (fast == slow) return true;
		}
		
		return false;
	}
	
	public ListNode findFirstCycleNode(ListNode head) {
		if (head == null) return null;
		
		ListNode fast = head;
		ListNode slow = head;
		
		while(fast != null && fast.next != null) {
			fast = fast.next.next;
			slow = slow.next;
			if (fast == slow) break;
		}
		
		if (fast != null && fast.next != null) {
			slow = head;
			while(true) {
				slow = slow.next;
				fast = fast.next;
				if (fast == slow) break;
			}
			return fast;
		} else {
			return null;
		}		
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		detectcycle test = new detectcycle();
		int[] data = {1,2,3,4,5,6,7,8,9};
		MyList ll = new MyList(data);
		ll.PrintListAll();
		ListNode head = ll.getHead();
		head.next.next.next.next.next.next = head.next.next;	
		System.out.println();
		if (true == test.hasCycle(head)) System.out.println("Yes");	
		else System.out.println("No");

		ListNode ans = test.findFirstCycleNode(head);
		if (ans != null) System.out.println("fisrt cycled node is " + ans.val);
		else System.out.println("No found");
		
	}

}
