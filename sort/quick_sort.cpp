//
// Created by shanshan on 2022/5/9.
//
#include <cstdlib>
#include <iostream>
using namespace std;

void myswap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int low,int high,int a[]){
    if(low==high) return low;
    int i=rand()%(high-low+1)+low;
    myswap(a,low,i);
    int key=low;
    while(key<high){
        while(low<high&&a[key]>=a[low]){
            low++;
        }
        while(low<high&&a[key]<a[high]){
            high--;
        }
        if(low>=high) break;
        myswap(a,low,high);
    }
    myswap(a,high,key);
    return high;
}
void quickSort(int a[],int low,int high){
    int p=partition(low,high,a);
    quickSort(a,low,p);
    quickSort(a,p+1,high);
}
