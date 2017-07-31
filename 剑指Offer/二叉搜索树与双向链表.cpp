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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return pRootOfTree;
        pRootOfTree = ConvertNode(pRootOfTree);
        while(pRootOfTree->left)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
    
    TreeNode* ConvertNode(TreeNode* root)
    {
        if(!root)
            return nullptr;
        
        if(root->left)
        {
            TreeNode* leftSubTree = ConvertNode(root->left);
            TreeNode* RightestNode = leftSubTree;
            while(RightestNode->right)
                RightestNode = RightestNode->right;
            RightestNode->right = root;
            root->left = RightestNode;
        }
        
        if(root->right)
        {
            TreeNode* rightSubTree = ConvertNode(root->right);
            TreeNode* LeftestNode = rightSubTree;
            while(LeftestNode->left)
                LeftestNode = LeftestNode->left;
            LeftestNode->left = root;
            root->right = LeftestNode;
        }
        
        return root;
    }
};