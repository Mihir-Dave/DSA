class Solution {
public:
    vector<string> ans;
    void solve(string &curr, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }
        curr.push_back('1');
        solve(curr,n);
        curr.pop_back();
        if(curr.empty() || curr.back() != '0'){
            curr.push_back('0');
            solve(curr,n);
            curr.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string curr = "";
        solve(curr,n);
        return ans;
    }
};