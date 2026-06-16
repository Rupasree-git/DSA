class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=s.size(),a=0;string str="";
        int i=l-1;
        while(i>0)
        {
            if(s[i]==' ')
            s.pop_back();
            else
            break;
            i--;
        }
        s=s+" ";
        int c=0;
        l=s.size();
        for (int i=0;i<l;i++)
        {
            if(s[i]!=' ')
                str=str+s[i];
            else 
            {
                
                c=str.size();
                str="";
                
            }
        }
        //cout<<wrd[a];
        return c;
    }
};