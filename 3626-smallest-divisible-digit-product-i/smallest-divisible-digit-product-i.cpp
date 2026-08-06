class Solution {
public:
    int smallestNumber(int n, int t) {
        int k=n,r=0,p=1;
        
        for(int i=n;i<=100;i++){
            k=i;
            while(k>0){
            r=k%10;
            p=p*r;
            k=k/10;
        }
        if(p%t==0){
            return i;
        }
        p=1;

        }
        return -1;
    }
};