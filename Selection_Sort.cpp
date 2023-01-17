// This is a selection sort algorithm

//1. initialise the minimum value(min_idx) to 0
// 2. traverse the array to find the minimum element in the array
//3. while traversing if any element smaller than min_idx is found then swap both the values
//4. Then, increment min_idx to point to the next element
//5. Repeat until the array is sorted.

// Time complexity is O(n^2)
// the algorithm is unstable but it can be made stable by placing the minimum element in its place instead of swapping
#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){           // we have to do n-2 passes
            int iMin=i;             // ith position: elements from i till n-1 are candidates
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[iMin]){
                    iMin=j;            // update the index of minimum element
                }
            }
            int temp=arr[i];
        arr[i]=arr[iMin];
        arr[iMin]=temp;
    }
    
}
int main(){
    cout<<"Enter the size of the array: "<<endl;
    int n;cin>>n;
    cout<<"Enter the elements of the array: "<<endl;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The sorted array is: "<<endl;
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}