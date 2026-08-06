class Solution {
public:
    int smallestNumber(int n, int t) {
        int p=0;int a=0,r=0;
        for(int i=n;;i++)
        {
            p=1;
            a=i;
            while(a>0)
            {
                r=a%10;
                p=p*r;
                a=a/10;
            }
            if(p%t==0)
            return i;
        }
    }
};