class Solution {
public:
    string processStr(string s) {
        int l=s.size();
        string result="",s1="";
        if(1<=l<=20)
        {
            for(int i=0;i<l;i++)
            {
                if(s[i]>=97 && s[i]<=122)
                {
                    result=result+s[i];
                }
                else if (s[i]=='*' && s!="" && result!="")
                {
                    result.pop_back();
                }
                else if(s[i]=='#')
                {
                    s1=s1+result;
                    result=result+s1;
                    s1="";
                }
                else if(s[i]=='%')
                {
                    reverse(result.begin(),result.end());
                }
                else
                {
                    result=result;
                }
            }
        }
        return result;        
    }
};