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
    
    while(t--){                                     //The algo works like magic...
        ll n, max=2, i=2, sqt;
        scanf("%lld", &n);
        sqt = sqrt(n);
        
        while(i<=sqt){
            if(n%i!=0){
                i++;
            }
            else{
                n = n/i;
                if(i > max){
                    max = i;
                }
            }
        }
        
        if(n!=1){
            max = n;
        }
        
        printf("%lld\n", max);
    }
    
    return 0;
}
