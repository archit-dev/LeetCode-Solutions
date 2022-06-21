
class Solution {
public:
    bool symmetricHelper(TreeNode* node1 , TreeNode * node2){
        if(!node1 && !node2) return true;
        if(!node1 || !node2) return false;
        if(node1->val != node2->val) return false;
        return symmetricHelper(node1->left,node2->right) && 
            symmetricHelper(node1->right,node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return symmetricHelper(root,root);
    }
};