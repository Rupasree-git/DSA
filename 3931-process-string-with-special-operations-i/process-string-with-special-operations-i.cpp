class Solution {
public:
    string processStr(string s) {
        int i=0;
        string s1;
        while(s[i]!='\0'){
            if(s[i]>='a'&& s[i]<='z'){
                s1=s1+s[i];
            }
            else if(s[i]=='*'){
                if(!s1.empty())
                s1.pop_back();
            
            }
            else if(s[i]=='#'){
                s1.append(s1);
            }
            else if(s[i]=='%'){
                int start=0,end=s1.size()-1;
                while(start<=end){
                    swap(s1[start],s1[end]);
                    start++;
                    end--;
                }
                
            }
            i++;

        }
        return s1;
    }
};