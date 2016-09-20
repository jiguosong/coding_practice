package tree;


import java.util.*;

public class AllTraverseTree {
	
	public List<List<Integer>> levelOrder(TreeNode root) {
		 List<List<Integer>> res = new ArrayList<List<Integer>>();
		 List<Integer> tmp = new ArrayList<Integer>();

		 Deque<TreeNode> curr = new ArrayDeque<TreeNode>();
		 Deque<TreeNode> next = new ArrayDeque<TreeNode>();
		 if (root == null) return res;
		 
		 curr.add(root);		 
		 while(!curr.isEmpty()) {
			 TreeNode t = curr.remove();
			 if (t == null) continue;
			 tmp.add(t.val);
			 
			 // break into level
			 if (t.left != null) next.add(t.left);
			 if (t.right != null) next.add(t.right);
			 if (curr.isEmpty()) { // need to refill for next level
				 res.add(tmp);
				 tmp = new ArrayList<Integer>();   // need a new list
				 curr = next;
				 next = new ArrayDeque<TreeNode>();  // need a new queue
			 }		 
		 }
		 
		 return res;
    }
	
	public List<List<Integer>> verticalOrder(TreeNode root) {
		if (root == null) return null;
		 List<List<Integer>> res = new ArrayList<List<Integer>>();
		 Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
		 Deque<TreeNode> queue = new ArrayDeque<TreeNode>();
		 Deque<Integer> verticals = new ArrayDeque<Integer>();
		 
		 int min = Integer.MAX_VALUE;
		 int max = Integer.MIN_VALUE;
		 queue.offer(root);
		 verticals.offer(0);
		 while (!queue.isEmpty()) {
			 TreeNode p = queue.poll();
			 int vertical = verticals.poll();
			 
			 if (vertical < min) min = vertical;
			 if (vertical > max) max = vertical;
			 
			 if (map.containsKey(vertical)) {
				 map.get(vertical).add(p.val);
			 } else {
				 List<Integer> list = new ArrayList<Integer>();
				 list.add(p.val);
				 map.put(vertical, list);
			 }
			 
			 if (p.left != null) {
				 queue.offer(p.left);
				 verticals.offer(vertical-1);
			 }
			 
			 if (p.right != null) {
				 queue.offer(p.right);
				 verticals.offer(vertical+1);
			 }			 
		 }
		 
		 for (int i = min; i <= max; i++) {
			 List<Integer> tmp = map.get(i);
			 res.add(tmp);
		 }
		 		
		 return res;
	}

	public List<List<Integer>> zigzagOrder(TreeNode root) {
		 List<List<Integer>> res = new ArrayList<List<Integer>>();
		 List<Integer> tmp = new ArrayList<Integer>();
		 
		 int level = 0; // odd and even

		 Deque<TreeNode> curr = new ArrayDeque<TreeNode>();
		 Deque<TreeNode> next = new ArrayDeque<TreeNode>();
		 if (root == null) return res;
		 
		 curr.add(root);		 
		 while(!curr.isEmpty()) {
			 TreeNode t = curr.remove();
			 if (t == null) continue;
			 tmp.add(t.val);
			 
			 // break into level
			 if (t.left != null) next.add(t.left);
			 if (t.right != null) next.add(t.right);
			 if (curr.isEmpty()) { // need to refill for next level
				 level++;
				 res.add(tmp);
				 tmp = new ArrayList<Integer>();   // need a new list
				 
				 // reverse logic
				 if (level%2 == 0) {
					 Iterator<TreeNode> it = next.descendingIterator();
					 Deque<TreeNode> rev_next = new ArrayDeque<TreeNode>();
					 while(it.hasNext()) rev_next.add(it.next());
					 next = rev_next;
				 }
				 curr = next;
				 next = new ArrayDeque<TreeNode>();  // need a new queue
			 }		 
		 }
		 
		 return res;
   }
	
	public List<Integer> inOrder(TreeNode root) {
		if (root == null) return null;		
		List<Integer> res = new ArrayList<Integer>();
		Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
		
		TreeNode tmp = root;		
		while (tmp != null || !stack.isEmpty()) {
			if (tmp != null) {
				stack.push(tmp);
				tmp = tmp.left;
			} else {
				tmp = stack.pop();
				res.add(tmp.val);
				tmp = tmp.right;
			}
		}
		
		return res;
	}
	

	public List<Integer> inOrder2(TreeNode root) {
		if (root == null) return null;
		List<Integer> res = new ArrayList<Integer>();		
		inOrder2_helper(root, res);		
		return res;
	}
	
	private void inOrder2_helper(TreeNode root, List<Integer> res) {
		if (root == null) return;
		inOrder2_helper(root.left, res);
		res.add(root.val);
		inOrder2_helper(root.right,res);	
	}
	
	public List<Integer> preOrder(TreeNode root) {
		if (root == null) return null;
		List<Integer> res = new ArrayList<Integer>();
		Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
		
		stack.push(root);
		while (!stack.isEmpty()) {
			TreeNode tmp = stack.pop();
			res.add(tmp.val);
			
			if (tmp.right != null) {
				stack.push(tmp.right);
			}
			
			if (tmp.left != null) {
				stack.push(tmp.left);
			}
		}
		return res;		
	}

	
	public List<Integer> preOrder2(TreeNode root) {
		if (root == null) return null;
		List<Integer> res = new ArrayList<Integer>();		
		preOrder2_helper(root, res);		
		return res;
	}
	
	private void preOrder2_helper(TreeNode root, List<Integer> res) {
		if (root == null) return;
		res.add(root.val);
		preOrder2_helper(root.left, res);
		preOrder2_helper(root.right,res);	
	}

	
	public List<Integer> postOrder(TreeNode root) {
		if (root == null) return null;
		List<Integer> res = new ArrayList<Integer>();
		Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
		
		stack.push(root);
		
		TreeNode curr = null;
		TreeNode prev = null;
		while (!stack.isEmpty()) {
			curr = stack.peek();
			if (prev == null || prev.left == curr || prev.right == curr) {
				if (curr.left != null) {
					stack.push(curr.left);
				}
				else if (curr.right != null) {
					stack.push(curr.right);
				}
				else {
					TreeNode tmp = stack.pop();
					res.add(tmp.val);
				}
			} else if (curr.left == prev) {
				if (curr.right != null) stack.push(curr.right);
				else {
					TreeNode tmp = stack.pop();
					res.add(tmp.val);
				}
			} else if (curr.right == prev) {
				TreeNode tmp = stack.pop();
				res.add(tmp.val);
			}
			
			prev = curr;		
		}
		return res;		
	}
	
	public List<Integer> postOrder2(TreeNode root) {
		if (root == null) return null;
		List<Integer> res = new ArrayList<Integer>();		
		postOrder2_helper(root, res);		
		return res;
	}
	
	private void postOrder2_helper(TreeNode root, List<Integer> res) {
		if (root == null) return;
		postOrder2_helper(root.left, res);
		postOrder2_helper(root.right,res);
		res.add(root.val);	
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		root.right.left = new TreeNode(6);
		root.right.right = new TreeNode(7);		
		
		AllTraverseTree test = new AllTraverseTree();
		
		System.out.println("level order traverse");
		List<List<Integer>> res = test.levelOrder(root);		
		Iterator<List<Integer>> it = res.iterator();
		while(it.hasNext()) {
			List<Integer> tmp = it.next();
			System.out.print(tmp);
		}

		System.out.println("\nvertical order traverse");
		List<List<Integer>> ver_res = test.verticalOrder(root);		
		Iterator<List<Integer>> ver_it = ver_res.iterator();
		while(ver_it.hasNext()) {
			List<Integer> tmp = ver_it.next();
			System.out.print(tmp);
		}

		System.out.println("\nzigzag order traverse");
		List<List<Integer>> res2 = test.zigzagOrder(root);		
		Iterator<List<Integer>> it2 = res2.iterator();
		while(it2.hasNext()) {
			List<Integer> tmp = it2.next();
			System.out.print(tmp);
		}

		
		System.out.println("\ninroder traverse");
		List<Integer> res3 = test.inOrder(root);	
		//List<Integer> res3 = test.inOrder2(root);
		Iterator<Integer> it3 = res3.iterator();;
		while(it3.hasNext()) {
			int tmp = it3.next();
			System.out.print(tmp);
		}
		
		System.out.println("\npreroder traverse");
		List<Integer> res4 = test.preOrder(root);	
		//List<Integer> res4 = test.preOrder2(root);
		Iterator<Integer> it4 = res4.iterator();;
		while(it4.hasNext()) {
			int tmp = it4.next();
			System.out.print(tmp);
		}

		System.out.println("\npostoder traverse");
		List<Integer> res5 = test.postOrder(root);	
		//List<Integer> res5 = test.postOrder2(root);
		Iterator<Integer> it5 = res5.iterator();;
		while(it5.hasNext()) {
			int tmp = it5.next();
			System.out.print(tmp);
		}

	}

}
