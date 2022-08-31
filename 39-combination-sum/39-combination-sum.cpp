class Solution {
public:
    vector<vector<int>> ans;
    void recur(vector<int>& candidates, int target,vector<int>&cur,int i){
        if(target==0 ){
            ans.push_back(cur);
            return;
        }
        if(target<0){
            return;
        }
        // cout<< i<<endl;
        if(i>=candidates.size())return;
        cur.push_back(candidates[i]);
        recur(candidates,target-candidates[i],cur,i);
        //recur(candidates,target,cur,i+1);
        cur.pop_back();
        recur(candidates,target,cur,i+1);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>cur;
        recur(candidates,target,cur,0);
        return ans;
    }
};