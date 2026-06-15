class Solution {
public:
    bool checkIfPangram(string sentence) {
        string s="";int c=0,l=0,m=0;
        vector<int>f(26,0);
        for(char ch='a';ch<='z';ch++)
        {   
            for(int i=0;i<sentence.size();i++)
            {
                if(sentence[i]==ch)
                {    
                    c++;
                }
            }
            f[l]=c;
            l++;
            c=0;
        }
        for(int j=0;j<26;j++)
        {
            
            if(f[j]==0)
            return false;
        }
        return true;
    }
    
};