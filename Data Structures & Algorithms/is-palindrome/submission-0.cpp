class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(),s.end(),[](char ch){
            return !isalnum(ch);
        }),s.end());
        cout<<s<<endl;
        int n= s.length();
        bool flag= true;
        for(int i=0;i<n/2;i++){
            if(tolower(s[i])!=tolower(s[n-i-1])){
                flag=false;
                break;
            }
        }

        return flag;
    }
};
