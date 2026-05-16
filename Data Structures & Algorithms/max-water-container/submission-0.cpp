class Solution {
public:
    int maxArea(vector<int>& h) {
        // algo relating to the pair of numbers 
        // two pointers 
        int n=h.size();
        int i=0;
        int j=n-1;
        int area=0;
        while(i<j){
            area=max(area,(j-i)*min(h[i],h[j]));

            // we have to move the pointer where the height is min 
            if(h[i]>=h[j]) j--;
            else i++;
        }
        return area;

    }
};
