class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
            return false;
        }
        return true;
    }
    void palin(string s,vector<string> curr,int index){
        if(index==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=index;j<s.size();j++){
            if(isPalindrome(s,index,j)){
                curr.push_back(s.substr(index,j-index+1));
                palin(s,curr,j+1);
                curr.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        palin(s,curr,0);
        return ans;
    }
};