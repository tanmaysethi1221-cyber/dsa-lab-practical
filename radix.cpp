#include <iostream>
using namespace std;
int  getmax(int arr[],int n){
    int max =0;
    for(int i=0 ; i<n;i++){
    if(  arr[i] >max){
        max = arr[i];
    }
    }
    return max;
}
void radixsort(int arr[],int n ){
    int max_element = getmax(arr,n);
    // now for radix sort we have to find the digit and end till end digit of max element 
    for(int pos =1; max_element / pos >0; pos*=10){
        // make bucket in which we store the elements acc to digit 
        int bucket[10][10];
        // count is for to calculate the no of elements in a bucket 
        int count[10];
        for(int i=0;i<10;i++)
        count[i]=0;
    for(int i= 0;i<n;i++){
        int digit = (arr[i]/pos) % 10;
        bucket[digit][count[digit]]= arr[i];
        count[digit]++;
    }
    int k=0;
    for (int i=0;i<10;i++){
        for(int j=0; j< count[i];j++){
            arr[k]= bucket[i][j];
            k++;
        }
    }
    }
}
int main(){
  int arr[5]= {12,54,32,1,23};
  cout<<"before sorting "<<endl;
for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
}
cout<<"after srting with radix sort "<<endl;
radixsort(arr,5);
for(int i=0;i<5;i++){
    cout<<arr[i]<<endl;
}
return 0;
}
