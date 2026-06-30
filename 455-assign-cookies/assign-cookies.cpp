class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child = 0;
        int cookie = 0;
        int cnt = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(child < g.size() && cookie < s.size()){
            if(g[child] > s[cookie]){
                cookie++;
            }
            else{
                child++;
                cookie++;
                cnt++;
            }
        }
        return cnt;
    }
};