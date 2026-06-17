class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for (int i=0;i<s.size();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
               len++;
            }
            else  if(s[i]=='*')
            {
                if(len>0)
                len--;
            }
            else if (s[i]=='#')
                len=len*2;
            
        }
        if(k>=len)
            return '.';
        for(int i=s.size()-1;i>=0;i--)
        {
            char c=s[i];
            if(c>='a' && c<='z')
            {
                if(k==len-1)
                {
                    return c;
                }
                else
                    len--;
            }
            else if(c=='#')
            {
                len=len/2;
                if(k>=len)

                    k-=len;
            }
            else if(c=='*')
            {
                len++;
                
            }
            else if(c=='%')
            {
                k=len-1-k;
            }
                  
             
        }
        return '.';
    }
};