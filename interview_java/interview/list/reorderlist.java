package list;

public class reorderlist {
	
	private ListNode reverse_list(ListNode head){
		if (head == null) return null;
		
		ListNode prev, curr;
		prev = null;
		curr = head;
		while(curr != null) {
			ListNode tmp = curr.next;
			curr.next = prev;
			prev = curr;
			curr = tmp;
		}
		
		return prev;
	}
	
	public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        
        ListNode fast, slow, prev_slow;
        fast = head;
        slow = head;
        prev_slow = null;
        
        while (fast != null && fast.next != null) {
        	fast = fast.next.next;
        	prev_slow = slow;
        	slow = slow.next;
        }
        if (prev_slow != null) prev_slow.next = null;
        // slow now should be the middle (odd or even)
        
        ListNode second_head = reverse_list(slow);  
                
        ListNode first_head = head;
        while(first_head != null && second_head != null) {
        	ListNode tmp1 = first_head.next;
        	ListNode tmp2 = second_head.next;        	
        	first_head.next = second_head; 
        	if (tmp1 == null) break;
        	second_head.next = tmp1;
        	first_head = tmp1;
        	second_head = tmp2;        	
        }        
    }

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int[] data = {1,2,3,4,5,6,7,8};
		MyList ll = new MyList(data);
		ll.PrintListAll();	
		
		System.out.println("\n\nJava: reorder list");
		reorderlist test = new reorderlist();
		test.reorderList(ll.getHead());
		ll.PrintListAll();
	}

}
