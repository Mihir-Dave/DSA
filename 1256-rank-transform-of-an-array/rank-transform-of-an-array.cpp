class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortarr = arr;
        sort(sortarr.begin(),sortarr.end());

        unordered_map<int,int> rank;

        int r = 1; 
        for(int it : sortarr){
            if(rank.find(it) == rank.end()){
                rank[it] = r;
                r++;
            }
        }

        for(int i=0 ; i< arr.size() ; i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
    
};