class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<char>needed(26,0),window(26,0);
        for(char ch:s1){
            needed[ch-'a']++;
        }
        int left=0;
        for(int right=0;right<s2.size();right++){
            // if the window size is greater than the s1 then we have to delete the elements 
            window[s2[right]-'a']++;
            if((right-left+1)>s1.size()){
                window[s2[left]-'a']--;
                left++;
            }

            if((right-left+1)==s1.size()){
                if(window==needed) return true;
            }
        }
        return false;
    }
};
