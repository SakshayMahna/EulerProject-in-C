#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define ll long long

ll sumofx(ll till, ll x){
    ll last;
    for(ll i=till-1; i>till-x-1; i--){
        if(i%x == 0){
            last = i;
            break;
        }
    }
    
    ll n = last/x;
    
    return (n*(x+last))/2;
}

int main(){
    int t; 
    scanf("%d",&t);
    
    while(t--){
        long long n, sum=0;
        scanf("%lld", &n);
        
        
        printf("%lld\n", sumofx(n, 3) + sumofx(n, 5) - sumofx(n, 15));
    }
    return 0;
}
