#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(long* a, long* b){
    long s = *a;
    *a = *b;
    *b = s;
}

int partition(long arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(long arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}


bool isPalindrome(long n){                           
    long backward = 0, n1=n;
    while(n1!=0){
        backward = backward*10 + n1%10;
        n1 = n1/10;
    }

    if(n == backward){
        return true;
    }
    else{
        return false;
    }
}

int input_int(){                                          //#faster-input
    int i=0;char p;
    while((p = getchar())<48);
    i = (p - '0');
    while((p = getchar())>=48){
        i = i*10 + (p - '0');
    }
    return i;
}


void listPalindrome(long list[]){
    int k=0;
    for(long i=100; i<=999; i++){
        for(long j=i; j<=999; j++){
            if(isPalindrome(i*j) && (i*j)/100000 != 0){
                list[k] = i*j;
                k++;
            }
        }
    }
    
    quicksort(list, 0, 488);
}

int main(){
    long theList[489];
    listPalindrome(theList);
    int t; 
    t = input_int();
    

    while(t--){
        int n, answer=1;
        n = input_int();
        
        for(int i=0; i<489; i++){
            if(theList[i] >= n){
                answer = theList[i-1];
                break;
            } 
        }
        
        printf("%d\n", answer);
    }
    
    return 0;
}
