//Using prev experience...

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    scanf("%d", &T);
    
    long long sum[1000001]={0};
    bool primes[1000001];
    memset(primes, true, sizeof(primes));
    
    long prev = 0;
    for(long i=2; i<=1000; i++){
            if(primes[i]){
                for(long j=(i*i); j<=1000000; j+=i){
                    primes[j] = false;
                }
                sum[i] += i + prev;
                prev = sum[i];
            }
        else{
            sum[i] = prev;
        }
    }
    
    for(long i=1001; i<=1000000; i++){
        if(primes[i]){
            sum[i] += i + prev; 
            prev = sum[i];
        }
        else{
            sum[i] = prev;
        }
    }
    
    while(T--){
        long N;
        scanf("%ld" ,&N);
        
        printf("%lld\n", sum[N]);
    }
    return 0;
}
