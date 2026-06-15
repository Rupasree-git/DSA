class Solution {
public:
    string sortSentence(string s) {
        s=s+" ";
        string str="";
        int l=s.size();
        vector<string>wrd(10,"");
        
        for(int i=0;i<l;i++)
        {
            if(s[i]!=' ')
            {
                str=str+s[i];
            }
            else
            {
                char ch=str[str.size()-1];
                str.pop_back();
                wrd[ch-'0']=str;     
                str="";           
            }

        }
        s="";
        for(int i=0;i<wrd.size();i++)
        {
            if(wrd[i]!="")
            s=s+wrd[i]+" ";
        }
        s.pop_back();
        return s;
    }
};