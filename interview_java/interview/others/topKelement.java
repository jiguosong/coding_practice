package others;

import java.util.*;

class Numwrapper{
	int num;
	int cnt;
	
	Numwrapper(int num, int cnt){
		this.num = num;
		this.cnt = cnt;
	}
}

public class topKelement {
	
	public List<Integer> topKFrequent(int[] nums, int k) {
		  if(nums == null || nums.length == 0) return null;
		  List<Integer> res  = new ArrayList<Integer>();
		  
		  Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		  for(int i:nums) {
			  if(map.containsKey(i)) map.put(i, map.get(i)+1);
			  else map.put(i, 1);
		  }
		  
		  //CntCompare cmp = new CntCompare();		  
		  PriorityQueue<Numwrapper> priorityqueue = new PriorityQueue<Numwrapper>(k+10, new Comparator<Numwrapper>() {
					  public int compare(Numwrapper a, Numwrapper b) {
						  return a.cnt - b.cnt;
					  }
				  });
		  
		  for(Map.Entry<Integer, Integer> e: map.entrySet()) {
			  Numwrapper tmp = new Numwrapper(e.getKey(), e.getValue());
			  priorityqueue.offer(tmp);
			  if(priorityqueue.size() > k) priorityqueue.poll();
		  }
		  
		  while(!priorityqueue.isEmpty()) {
			  res.add(priorityqueue.poll().num);
		  }
		  
		  Collections.reverse(res);
		  
		  return res;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		topKelement test = new topKelement();
		int[] nums = {1,1,1,2,2,3,3,3,3,4,5,6,6,6,6,6,6,6,6};
		int k = 2;
		List<Integer> ans = test.topKFrequent(nums, k);
		
		System.out.println(ans);

	}

}
