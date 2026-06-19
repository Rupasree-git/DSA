class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int c=0,max=0;
        for(int i=0;i<gain.size();i++){
            c=c+gain[i];
            if(c>max){
                max=c;
            }
        }
        return max;
    }
};