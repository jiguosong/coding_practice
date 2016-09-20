package listarray;

class RandomListNode{
	int val;
	RandomListNode next;
	RandomListNode random;
	RandomListNode(int x) { val = x;}
}

public class copywithrandomptr {
	
	public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return null;
        RandomListNode newhead = null;
		
        RandomListNode p = head;        
        while(p != null) {
        	RandomListNode q = new RandomListNode(p.val);
        	q.next = p.next;
        	p.next = q;
        	p = q.next;
    	}
       
        p = head;
        while(p != null && p.next != null) {
        	p.next.random = p.random.next;
        	p = p.next.next;
        }
        
        p = head;
        RandomListNode q = head.next;
        newhead = head.next;
        
        while(p != null && p.next != null &&
        	  q != null && q.next != null) {
        	RandomListNode t1 = p.next.next;
        	RandomListNode t2 = q.next.next;
        	p.next = t1;
        	q.next = t2;
        	p = t1;
        	q = t2;        	
        }
        
        
//        while(p != null) {
//        	p.next = q.next;
//        	if (p.next != null) q.next = p.next.next;
//        	else q.next = null;
//        	p = p.next;
//        	q = q.next;
//        }
        
        return newhead;
    }
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Java: copy list w/ random ptr");
		int[] data = {1,2,3,4,5,6,7,8};
		RandomListNode head = new RandomListNode(1);
		RandomListNode p = head;		
		RandomListNode node2 = new RandomListNode(2);
		p.next = node2;
		p = p.next;
		RandomListNode node3 = new RandomListNode(3);
		p.next = node3;
		p = p.next;		
		RandomListNode node4 = new RandomListNode(4);
		p.next = node4;
		p = p.next;		
		RandomListNode node5 = new RandomListNode(5);
		p.next = node5;
		p = p.next;		
		RandomListNode node6 = new RandomListNode(6);
		p.next = node6;
				
		p = head;
		p.random = node4;
		p = p.next;
		p.random = node2;
		p = p.next;
		p.random = node6;
		p = p.next;
		p.random = node5;
		p = p.next;
		p.random = node3;
		p = p.next;
		p.random = head;
		p = p.next;
		
		RandomListNode ttt;		
        ttt = head;
        while(ttt != null) {
        	System.out.print(ttt.val);
        	ttt = ttt.next;
        }
        System.out.println();
        
        ttt = head;
        while(ttt != null && ttt.random != null) {
        	System.out.print(ttt.random.val);
        	ttt = ttt.next;
        }
        System.out.println();
        System.out.println();	
		
		copywithrandomptr test = new copywithrandomptr();
		RandomListNode res = test.copyRandomList(head);

        ttt = res;
        while(ttt != null) {
        	System.out.print(ttt.val);
        	ttt = ttt.next;
        }
        System.out.println();        
        ttt = res;
        while(ttt != null && ttt.random != null) {
        	System.out.print(ttt.random.val);
        	ttt = ttt.next;
        }
        System.out.println();

        
		
	}

}
