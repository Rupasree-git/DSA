class Solution {
public:
    int reverse(int x) {
        int r=0,s=0,n=x;
        while(n!=0){
            r=n%10;
            if(s>INT_MAX/10 || s==INT_MAX/10 && r>7){
                return 0;
            }
            else if(s<INT_MIN/10 || s==INT_MIN/10 && r<-8){
                return 0;
            }
            s=s*10+r;
            n=n/10;
        }
        return s;
    }
};