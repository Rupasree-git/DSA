class Solution {
public:

    long long sumAndMultiply(int n) {
        long long k=n;
        string num=to_string(k);
        string s="";
        for(int i=0;i<num.size();i++){
            if(num[i]!='0'){
                s=s+num[i];
            }
        }
        if(n==0){
            return 0;
        }
        k=stoi(s);
        long long n1=k;
        long long  sum=0,r=0;
        while(k>0){
            r=k%10;
            sum=sum+r;
            k=k/10;
        }
        return n1*sum;
        
    }
};