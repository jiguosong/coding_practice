/*
 * Task1.h
 *
 *  Created on: Dec 5, 2016
 *      Author: songjiguo
 */

#ifndef TASK1_H_
#define TASK1_H_

#include <vector>
using std::vector;

class TreeNode
{
public:
    TreeNode(TreeNode* leftChild, TreeNode* rightChild)
    {
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }

    TreeNode* getLeftChild() const
    {
        return this->leftChild;
    }

    TreeNode* getRightChild() const
    {
        return this->rightChild;
    }

private:
    TreeNode* leftChild;
    TreeNode* rightChild;
};


class Task2 {
public:
	int calculateHeight(const TreeNode& root);
};

#endif /* TASK1_H_ */
