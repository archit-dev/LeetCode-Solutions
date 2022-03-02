// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long *arr,vector<long long>& temp,int start
,int mid,int end){
    long long inversionCount = 0; 
    int ptr1 = start;
    int ptr2 = mid;
    int ptr3 = start;
    while(ptr1<mid && ptr2<=end){
        if(arr[ptr1] <= arr[ptr2]){
            temp[ptr3++] = arr[ptr1++];
        }else{
            temp[ptr3++] = arr[ptr2++];
            inversionCount += mid - ptr1;
        }
    }
    while(ptr1<mid){
        temp[ptr3++] = arr[ptr1++];
    }
    while(ptr2<=end){
        temp[ptr3++] = arr[ptr2++];
    }
    for(int i=start;i<=end;i++){
        arr[i] = temp[i];
    }
    return inversionCount;
}

long long mergeSort(long long *arr,vector<long long>&temp,int start,int end){
    long long inversionCount = 0;
    if(start<end){
        int mid = start + (end-start)/2;
        inversionCount += mergeSort(arr,temp,start,mid);
        inversionCount += mergeSort(arr,temp,mid+1,end);
        inversionCount += merge(arr,temp,start,mid+1,end);
    }
    return inversionCount;
}
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
    vector<long long > temp(N);
    return mergeSort(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends