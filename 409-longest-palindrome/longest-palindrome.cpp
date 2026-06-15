class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>lc(26,0);int a=0,b=0,c=0;
        vector<int>uc(26,0);
        int l=s.size();
        for (int i=0;i<l;i++)
        {
            if(s[i]>=97 && s[i]<=122)
            {
                
                lc[s[i]-'a']++;
                
            }
            else if(s[i]>=65 && s[i]<=90)
            {
                uc[s[i]-'A']++;
            }
        }
        int f=0,o=0;
        for(int i=0;i<26;i++)
        {
            if(lc[i]%2==0)
            {
                f=f+lc[i];
            }
            else
            {
                f=f+lc[i]-1;
                o=1;
            }
            if(uc[i]%2==0)
            f=f+uc[i];
            else
            {
            f=f+uc[i]-1;
            o=1;
            }
        }
        return f+o;
    }
};