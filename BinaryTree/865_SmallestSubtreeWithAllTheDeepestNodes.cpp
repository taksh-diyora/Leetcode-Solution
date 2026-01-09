class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;

        return max(1+depth(root->left), 1+depth(root->right));
    }
    void rts(TreeNode* root, int maxDepth, vector<TreeNode*>& roots, int currLen){
        if(!root) return;
        if(currLen == maxDepth-1){
            roots.push_back(root);
            return;
        }

        rts(root->left, maxDepth, roots, currLen+1);
        rts(root->right, maxDepth, roots, currLen+1);
    }
    TreeNode* commonAnc(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q){
            return root;
        }

        TreeNode* left = commonAnc(root->left, p, q);
        TreeNode* right = commonAnc(root->right, p, q);

        if(left && right){
            return root;
        }

        return left?left:right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = depth(root);

        vector<TreeNode*> roots;

        rts(root, maxDepth, roots, 0);

        int sz = roots.size();

        if(sz == 1) return roots[0];
        for(int i=0; i<sz-1; i++){
            roots[i+1] = commonAnc(root, roots[i], roots[i+1]);
        }

        return roots[sz-1];
    }
};