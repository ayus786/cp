int findmax(vector<int>& v,int start,int end){
        int m=INT_MIN;
        int idx=-1;
        for(int i=start; i<=end; i++){
            if(m<v[i]){
                m=v[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* construct(vector<int>& v,int start,int end){
        if(start>end) return NULL;
        if(start==end){
            return (new TreeNode(v[start]));
        }
        int idx=findmax(v,start,end);
        TreeNode* root=new TreeNode(v[idx]);
        root->left=construct(v,start,idx-1);
        root->right=construct(v,idx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& v) {
        TreeNode* root=construct(v,0,v.size()-1);
        return root;
    }
