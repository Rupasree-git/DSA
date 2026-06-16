class Solution {
public:
    string processStr(string s) {
        int l=s.size();
        string result="";
        if(1<=l && l<=20)
        {
            for(int i=0;i<l;i++)
            {
                if(s[i]>=97 && s[i]<=122)
                {
                    result=result+s[i];
                }
                else if (s[i]=='*' && result!="")
                {
                    result.pop_back();
                }
                else if(s[i]=='#')
                {                    
                    result=result+result;                    
                }
                else if(s[i]=='%')
                {
                    reverse(result.begin(),result.end());
                }
            }
        }
        return result;        
    }
};