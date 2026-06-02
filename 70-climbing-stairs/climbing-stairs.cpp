class Solution {
public:
    int climbStairs(int n) {
        
        int prev1=1;
        int prev2=1;
        int curr=0;
        for(int i=2;i<=n;i++)
        {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        if(n==0)
        return 1;
        else if(n==1)
        return 1;
        else
        return curr;
    }
};