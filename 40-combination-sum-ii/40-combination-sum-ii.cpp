class Solution {
public:
  set<vector<int>>ans;
    void recur(vector<int>& candidates, int target,vector<int>&cur,int l){
         if(target==0 ){
            ans.insert(cur);
            return;
        }
        for(int i=l;i<candidates.size();i++){
            if(candidates[i]>target){
                continue;
            }
            if(i>l and candidates[i]==candidates[i-1]){
                continue;
            }
            
            cur.push_back(candidates[i]);
            recur(candidates,target-candidates[i],cur,i+1);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        recur(candidates,target,cur,0);
        vector<vector<int>>ans2;
        for(auto it:ans){
            ans2.push_back(it);
        }
        return ans2;
            
    }
};