//{ Driver Code Starts
// Heap Sort in C
#include <stdio.h>
  
// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
// } Driver Code Ends
//User function Template for C


void heapify(int index,int arr[],int n) {
        int largest = index;
        int left = 2*index + 1;
        int right = (2*index) + 2;

        if(left < n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != index){
            swap(arr[largest],arr[index]);
            heapify(largest,arr,n);
    }
    
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    for(int i = (n/2) - 1;i>=0;i--){
        heapify(i,arr,n);
    }
    
    int t = n-1;
    while(t>=0){
        swap(arr[0],arr[t]);
        t--;
        heapify(0,arr,t);
    }
    
}

//{ Driver Code Starts.
  
// Driver code
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr, n);
    printArray(arr, n);
    }
  }
// } Driver Code Ends
