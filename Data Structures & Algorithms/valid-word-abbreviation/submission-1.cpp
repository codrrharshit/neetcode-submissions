class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n=word.size();
        int m=abbr.size();
        int i=0,j=0;
        while(j<m){
            if(isalpha(abbr[j])){
                if(word[i]!=abbr[j] || i>=n) return false;
                i++;
                j++;
            }
            else if (isdigit(abbr[j])){
                if(abbr[j]=='0') return false;
                // parse the whole digit 
                int num=0;
                while(j<n && isdigit(abbr[j])){
                    num=num*10+abbr[j]-'0';
                    j++;
                }
                // skip the i to that num 
                i+=num;
                if(i>n) return false;
            }
        }

        return i==n && j==m;
    }
};