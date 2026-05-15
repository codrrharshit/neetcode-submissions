class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() || s.empty()) return "";
        unordered_map<char,int>need;
        for(char ch : t){
            need[ch]++;
        }
        unordered_map<char,int>have;
        int reqUniql=need.size();
        int formed=0;
        int minlength=INT_MAX;
        int bestl=0;
        int left=0;

        for(int right=0;right<s.size();right++){
            char ch=s[right];
            have[ch]++;
            if(need.count(ch) && need[ch]==have[ch]){
                formed++;
            }
            while(left<=right && formed==reqUniql){
                if(right-left+1<minlength){
                    minlength=right-left+1;
                    bestl=left;
                }
                // now we have to shrink the window 
                char c=s[left];
                have[c]--;
                if(need.count(c) && have[c]<need[c] ){
                    formed--;
                }

                left++;
            }
        }

        if(minlength==INT_MAX) return "";
        return s.substr(bestl,minlength);
    }
};
