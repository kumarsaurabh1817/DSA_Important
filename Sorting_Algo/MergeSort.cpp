#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void Merge(vector<int> &arr,int start,int mid,int end){
        int leftlength=mid-start+1;
        int rightlength=end-mid;
        int *left=new int[leftlength];
        int *right=new int[rightlength];
        int leftindex=0;
        int rightindex=0;
        int originalindex=start;
        while(leftindex < leftlength){
            left[leftindex]=arr[originalindex];
            leftindex++;
            originalindex++;
        }
        originalindex=mid+1;
        while(rightindex < rightlength){
            right[rightindex]=arr[originalindex];
            rightindex++;
            originalindex++;
        }
        int MainIndex=start;
        // reset both the indexes at zero back again to enter into the while loop
        leftindex=0;
        rightindex=0;
        while(leftindex < leftlength && rightindex < rightlength){
            if(left[leftindex] < right[rightindex]){
                arr[MainIndex]=left[leftindex];
                MainIndex++;
                leftindex++;
            }
            else{
                arr[MainIndex]=right[rightindex];
                MainIndex++;
                rightindex++;
            }
        }
        while(leftindex < leftlength){
            arr[MainIndex]=left[leftindex];
            MainIndex++;
            leftindex++;
        }
        while(rightindex < rightlength){
            arr[MainIndex]=right[rightindex];
            MainIndex++;
            rightindex++;
        }
        delete [] left;
        delete [] right;
    }
    void MergeSort(vector<int> &arr,int start,int end){
        if(start >= end){
            return;
        }
        int mid=start+(end-start)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
};
void Print(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={30,10,20,50,33,66};
    Print(arr);
    Solution obj;
    obj.MergeSort(arr,0,arr.size()-1);
    Print(arr);

   
  return 0;
}