class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=0;
        while(!s.empty() && s.back()==' ')
        s.pop_back();
        s=s+" ";
        string temp="";
        int c=0;
        while(s[i]!='\0'){
            if(s[i]!=' '){
                temp=temp+s[i];
            }
            else{
                c=temp.size();
                temp="";
            }
            i++;
        }
        return c;
    }
};