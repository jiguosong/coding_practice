package listarray;

import java.util.*;

public class add2number {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	if (l1 == null && l2 == null) return null;
    	if (l1 == null && l2 != null) return l2;
    	if (l2 == null && l1 != null) return l1;
    	
        int sum, digit, carry;
        ListNode p1, p2, curr;
        ListNode head = new ListNode(0);
        curr = head;
        p1 = l1; p2 = l2;
        digit = 0;
        carry = 0;
        
        while(p1 != null && p2 != null) {
        	sum = p1.val+p2.val + carry;
        	digit = sum%10;
        	carry = sum/10;
        	ListNode tmp = new ListNode(digit);
        	curr.next = tmp;
        	p1 = p1.next;
        	p2 = p2.next;
        	curr = curr.next;
        }        
        
        if (p1 != null) curr.next = p1;
        else if (p2 != null) curr.next = p2;
                
    	return head.next;
    }
    
    public static void main(String[] args){
    	
    	System.out.println("Java:add2sum");
    	
    	add2number test = new add2number();
    	
    	ListNode l1 = new ListNode(2);
    	l1.next = new ListNode(4);
    	l1.next.next = new ListNode(3);
    	
    	ListNode l2 = new ListNode(5);
    	l2.next = new ListNode(6);
    	l2.next.next = new ListNode(4);
    	
    	ListNode result = test.addTwoNumbers(l1, l2);
    	
    	while (result != null) {
    		System.out.println(result.val);
    		result = result.next;
    	}
    	
    }
    
}