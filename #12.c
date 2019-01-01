//Defeating timeouts.....used a solution....counting primes by this method faster than summing...

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

long p[100001];

void SoE(){
    int k=0;
    bool isit[1000000];
    memset(isit, true, sizeof(isit));
    
    for(long i=2; i<1001; i++){
        if(isit[i]){
            p[k] = i;
            k++;
            for(int j=i*i;j<=100000; j+=i){
                isit[j] = false;
            }
        }    
    }
    
    for(long i=1001; i<=100000; i++){
        if(isit[i]){
            p[k] = i;
            k++;
        }
    }
    
    return;
}

int numDiv(long long n){
    int result=1, count, k=0;
    
    for(;p[k]*p[k]<=n; k++){                          //Check only one side...
        count = 0;
        while(n%p[k]==0){
            count ++;
            n = n/p[k];
        }
        result *= (count+1);
    }
    
    if(n>1){
        result *= 2;                            //Double to produce another
    }
    
    return result;
}

int main() {
    SoE();
    int T;
    scanf("%d", &T);
    
    while(T--){
        long long sum=1;
        int N, answer, i=2;
        scanf("%d", &N);
        
        answer = numDiv(sum);
        while(answer <= N){
            sum += i;
            i++;
            answer = numDiv(sum);
        }
        
        printf("%lld\n", sum);
    }

    return 0;
}
