class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         int n=arr.size();
        int left=0;
        int right=n-1;
        while((right-left+1)>k){
            if(abs(arr[left]-x)<abs(arr[right]-x)){
                right--;
            }
            else if(abs(arr[left]-x)>abs(arr[right]-x)){
                left++;
            }
            else{
                right--;
            }
        }
        vector<int>result;
        for(int i=left;i<=right;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};