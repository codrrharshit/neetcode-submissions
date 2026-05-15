class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string str:strs){
            s+=to_string(str.length())+":"+str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>words;
        // we have to convert the first element in the encoded 
        int i = 0;
while (i < s.length()) {
    int j = i;
    while (s[j] != ':') j++;  // Find the separator

    int n = stoi(s.substr(i, j - i));  // Extract the full number
    string str = s.substr(j + 1, n);   // Extract the actual string
    words.push_back(str);

    i = j + 1 + n;  // Move to the next encoded string
}

        return words;
    }
};
