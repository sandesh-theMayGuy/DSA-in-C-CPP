#include<iostream>
using namespace std;

void swap_alternate(int arr[]){
    int temp;
    for(int i=0; i<5; i=i+2){ 

        if(i==4){
            continue;
        } 
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp; 
    }
}

int main(){
    int arr[] = {1,2,3,4,5};

    swap_alternate(arr);

    for(int i=0; i<5; i++){
        printf("%d\n",arr[i]);
    }
}