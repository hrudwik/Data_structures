/*The idea here is to store all the nodes and their values in sorted order using inorder traversal.
    Then we maintain a right Sum array and replace node's value by sum of nodes greater than equal to that node easily.*/
    
//Time Complexity (n), Space Complexity O(n)

class Solution {
public:
    void helper(vector<TreeNode*>& nodes, vector<int>& sums, TreeNode* root){
        if(!root)
            return;
        helper(nodes,sums,root->left);
        nodes.push_back(root);
        sums.push_back(root->val);
        helper(nodes,sums,root->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> sums;
        helper(nodes, sums, root);
        int n = sums.size();
        for(int i=n-2;i>=0;i--){
            sums.at(i) += sums.at(i+1);
        }
        for(int i=0;i<n;i++){
            nodes.at(i)->val = sums.at(i);
        }
        return root;
    }
};
