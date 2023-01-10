// This is a Merge Sort Algorithm

// 1. Start
// 2. Declaring the array,left,right,mid 
// 3. Performing the merge function
// if(left>=right){
//    return;
// }
// mid=(left+right)/2;
// the range [left,right] and the range [mid+1,right] are the subarrays in which the mergesort function will be performed recursively.
// mergesort (array,left,mid);
// mergesort (array, mid+1,right);
// then merge them
// merge (array, left , mid, right);
// 4. Stop.

// CODE 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void merge(int array[],int left, int mid, int right){
    // Finding the left and right subarray size
    int left_size=mid-left+1;
    int right_size=right-mid;

    // Declaring the left and right subarrays of previously declared size
    int left_array[left_size];
    int right_array[right_size];

    // Filling the left subarray (with elements of the original array)
    for(int i=0;i<left_size;i++){
        left_array[i]=array[left+i];
    }

    // Filling the right subarray (with elements of the original array)
    for(int j=0;j<right_size;j++){
        right_array[j]=array[mid+1+j];
    }

    int i=0; int j=0; int k=left;
    // Merging the two subarrays into the original array
    while(i<left_size && j<right_size){
        if(left_array[i]<right_array[j]){
            array[k]=left_array[i];
            i++;
        }
        else{
            array[k]=right_array[j];
            j++;
        }
        k++;
    }

    //include the extra elements in the left array
    while(i<left_size){
        array[k]=left_array[i];
        i++;k++;
    }

    //include the extra elements in the right array
    while(j<right_size){
        array[k]=right_array[j];
        j++;k++;
    }
}

void mergesort(int array[],int left, int right){
    if(left<=right){
        return;
    }
    else{
        int mid= (left+right)/2;
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}

int main(){
    cout<<"ENTER THE SIZE OF THE ARRAY: "<<endl;
    int n;cin>>n;
    cout<<"ENTER THE ARRAY ELEMENTS: "<<endl;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int left=0; int right=n-1;
    mergesort(array,left,right);
    cout<<"THE SORTED ARRAY IS: "<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}