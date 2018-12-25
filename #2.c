#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define ll long long

int main(){
    int t; 
    scanf("%d",&t);
    
    while(t--){
        ll n;
        scanf("%lld", &n);
        
        ll current=8, last=5, prev=3, sum=2;
        
        while(current < n){
            if(!(current&1)){               //AND operator with 1 checks if a given number is even or odd
                sum += current;
            }
            prev = last;
            last = current;
            current = last + prev;
        }
        
        printf("%lld\n", sum);
    }
    
    return 0;
}
