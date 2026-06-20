class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int m=restrictions.size();
        for (int i=1;i<m;i++)
        {
            restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+(restrictions[i][0]-restrictions[i-1][0]));
        }
        for(int i=m-2;i>=0;i--)
        {
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+(restrictions[i+1][0]-restrictions[i][0]));
        }
        long long ans=0;
        for(int i=1;i<m;i++)
        {
            int x1=restrictions[i][0];
            int h1=restrictions[i][1];
            int x2=restrictions[i-1][0];
            int h2=restrictions[i-1][1];
            ans=max(ans,(long long)(h1+h2+(x1-x2))/2);
        }
        ans=max(ans,(long long)restrictions.back()[1]+(n-(restrictions.back()[0])));
        return int(ans);
    }
};