class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int cnt = 0;
        vector<int> new_ele;
        new_ele.push_back(intervals[0][1]);
        for(int i = 1; i < intervals.size() ; i++){
            if(new_ele[0] <= intervals[i][0]){
                new_ele[0] = intervals[i][1];
                //cnt++;
            }
            else{
                cnt++;
                continue;
            }
        }
        return cnt;
    }
};