class Solution {
public:
    int gcdOfOddEvenSums(int n) {
       int even_sum=n*(n+1);
       int odd_sum=n*n;
       int m=max(even_sum,odd_sum);
       
       int hcf=0;
       for(int i=1;i<=m;i++){
        if(even_sum%i==0 && odd_sum%i==0){
            hcf=i;
        }
       } 
       return hcf;
    }
};