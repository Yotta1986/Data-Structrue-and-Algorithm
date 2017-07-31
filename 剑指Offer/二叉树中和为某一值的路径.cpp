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
    vector<int> array;
    vector<vector<int> > arrayAll;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        if(!root)
            return arrayAll;
        array.push_back(root->val);
        expectNumber -= root->val;
        if(expectNumber == 0 && root->left == nullptr && root->right == nullptr)
            arrayAll.push_back(array);
        else
        {
            FindPath(root->left, expectNumber);
            FindPath(root->right, expectNumber);
        }
        array.pop_back();
        return arrayAll;
    }
};