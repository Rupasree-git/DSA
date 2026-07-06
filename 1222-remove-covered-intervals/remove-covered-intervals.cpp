class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else
        return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int ans=0,max=-1;
        for(auto &it:intervals){
            if(it[1]>max){
                max=it[1];
                ans++;
            }
        }
return ans;
    }
};