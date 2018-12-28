#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void genPrimes(int arr[]){
    int k=1;
    bool isPrime[1000001];
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2; i<1001; i++){
        if(isPrime[i]){
            arr[k] = i;k++;
            for(int j=i*i; j<1000001; j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int i=1001; i<1000001; i++){
        if(isPrime[i]){
            arr[k] = i;k++;
        }
    }
}

int main(){
    int primes[1000001];
    genPrimes(primes);
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        
        printf("%d\n", primes[n]);
    }
    
    return 0;
}
