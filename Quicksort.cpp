#include <iostream>
using namespace std;
int partitionsort(int arr[],int low,int high){
    int pivot =arr[high];
    int i= low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p = partitionsort(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main(){
    int arr[5] = {12,53,18,32,43};
    cout<<"before sorting "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"after sorting"<< endl;
    quicksort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<endl;
    }
}
