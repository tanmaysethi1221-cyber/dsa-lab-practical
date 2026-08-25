#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid ,int high){
    int k=0;
    int temp[100];
    int i= low;
    int j= mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
       temp[k]= arr[i];
      i++;
        }
    else {
            temp[k]= arr[j];
            j++;
      }
      k++;
    }
    while(i<=mid){
temp[k]=arr[i];
i++;
k++;
    }
    while(j<=high){
temp[k]=arr[j];
j++;
k++;
    }
    for(int x = low; x <= high; x++)
{
    arr[x] = temp[x - low];
}

}
void mergesort(int arr[],int low,int high){
    if(low<high){
        int mid = (low +high )/2;
        mergesort(arr,low,mid);
         mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
int arr[5]={12,3,234,2,1};
cout<<"before sorting"<<endl;
for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
}
mergesort(arr,0,4);
cout<<"after merge sort"<<endl;
for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
}
}
