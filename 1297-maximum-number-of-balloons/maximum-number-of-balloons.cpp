class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(5,0);
        for(int i=0;i<text.size();i++)
        {
            if(text[i]>=97 && text[i]<=122)
            {
            if(text[i]=='b')
                freq[0]++;
            else if(text[i]=='a')
                freq[1]++;
            else if(text[i]=='l')
                freq[2]++;
            else if(text[i]=='o')
                freq[3]++;
            else if(text[i]=='n')
                freq[4]++;
            }
            else 
            return 0;
        }
        freq[2]=freq[2]/2;
        freq[3]=freq[3]/2;
        return min({freq[0],freq[1],freq[2],freq[3],freq[4]});
        
    }
};