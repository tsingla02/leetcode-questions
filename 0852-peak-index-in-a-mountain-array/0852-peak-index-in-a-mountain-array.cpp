class Solution {
public:
    int solution(int start , int last , vector<int>& arr)
    {
        if(start>last)
            return -1;
        int mid = start + (last-start)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return mid;
        else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1])
            return solution(start , mid , arr);
        else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
            return solution(mid, last , arr);
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return solution (0,arr.size()-1,arr);
    }
};