/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if (pRoot1 != nullptr && pRoot2 != nullptr) 
        {
            if(pRoot1->val == pRoot2->val)
                result = doesTree1HaveTree2(pRoot1, pRoot2);
            if (!result) 
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result) 
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
       
    
    bool doesTree1HaveTree2(TreeNode* node1, TreeNode* node2) 
    {

        
        //此处为p2 == nullptr 是匹配完成的条件
        //最开始p2肯定不为nullptr,这是在主程序HasSubtree中判断过的。
        //递归中，如果p2为空了，则表示上一层的递归中的p2已经匹配完了
        if (node2 == nullptr)
            return true;
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if (node1 == nullptr)
            return false;
        //如果其中有一个点没有对应上，返回false
        if (node1->val != node2->val)  
            return false;
         
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return doesTree1HaveTree2(node1->left,node2->left) && doesTree1HaveTree2(node1->right,node2->right);
    }
};