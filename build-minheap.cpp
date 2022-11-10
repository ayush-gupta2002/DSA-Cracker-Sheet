#include <bits/stdc++.h> 

void heapify(int index,vector<int>& arr,int n){
        int smallest = index;
        int left = 2*index + 1;
        int right = (2*index) + 2;

        if(left < n && arr[smallest] > arr[left]){
            smallest = left;
        }
        if(right < n && arr[smallest] > arr[right]){
            smallest = right;
        }

        if(smallest != index){
            swap(arr[smallest],arr[index]);
            heapify(smallest,arr,n);
        }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2-1;i>=0;i--){
        heapify(i,arr,n);
    }
    return arr;
}

