/**************************************************************************************************************************************
This problem was asked by Google.
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not 
locked.Design a binary tree node class with the following methods:
=>is_locked, which returns whether the node is locked
=>lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise,
it should lock it and return true.
=>unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a 
single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of 
the tree.
***************************************************************************************************************************************/

1.Time complexity = is_lock - O(1)
                  lock - O(m+h)
                  unlock - O(m+h)
class BinaryTreeLock{
	struct BinaryTreeNode{
		bool locked;
		BinaryTreeNode parent;
		BinaryTreeNode left;
		BinaryTreeNode right;
	}
	
	bool isLocked(BinaryTreeNode node){
		return node.locked;
	}
	
	bool lock(BinaryTreeNode node){
		if(!checklockCondition(node))
			return false;
		node.locked = true;
		return true;
	}
	
	bool unlock(BinaryTreeNode node){
		if(!checklockCondition(node))
			return false;
		node.locked = false;
		return true;
	}
	
	bool checklockCondition(BinaryNodeTree node){
		if(!checklockConditionChild(node.left) || !checklockConditionChild(node.right))
			return false;
		BInaryTreeNode parentNode = node.parent;
		while(parentNode!=NULL){
			if(parentNode.locked)
				return false;
			parentNOde = parentNode.parent
		}
	}
	
	bool checklockConditionChild(BinaryNodeTree node){
		if(node==NULL)
			return true;
		if(node.locked)
			return false;
		if(!checklockConditionChild(node.left) || !checklockConditionChild(node.right))
			return false;
	}
}


2.Time complexity = is_lock - O(1)
                  lock - O(h)
                  unlock - O(h)

public class BinaryTreeWithLock {
	struct BinaryTreeNode {
		int val;
		boolean locked = false;
		BinaryTreeNode parent;
		BinaryTreeNode leftChild;
		BinaryTreeNode rightChild;
		int lockedDescendantCount = 0;
    }
    
    bool is_locked(BinaryTreeNode node){
    	return node.locked;
    }
    
    bool lock(BinaryTreeNode node){
    	if(!lockunlock(node))
    		return false;
    	node.locked = true;
    	BinaryTreeNode parentNode = node.parent;
    	while(parentNode!=NULL){
    		parentNode.lockedDescendantCount += 1;
    		parentNode = parentNode.parent;
    	}
    	return true;
    }

	 bool unlock(BinaryTreeNode node){
    	if(!lockunlock(node))
    		return false;
    	node.locked = false;
    	BinaryTreeNode parentNode = node.parent;
    	while(parentNode!=NULL){
    		parentNode.lockedDescendantCount -= 1;
    		parentNode = parentNode.parent;
    	}
    	return true;
    }
    
    bool lockunlock(node){
    	if(node.lockedDescendantCount>0)
    		return false;
    	
    	BinaryTreeNode parentNode = node.parent;
    	while(parentNode!=NULL){
    		if(parentNode.locked)
    			return false;
    		prentNode = parentNode.parent;
    	}
    }
