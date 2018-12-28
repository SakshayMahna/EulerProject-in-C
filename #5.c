#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    
    if(a > b){
        return gcd(b, a%b);
    }
    else{
        return gcd(a, b%a);
    }
}

int main(){
    int t; 
    scanf("%d",&t);
    while(t--){
        int n, lcm=1, i=1;
        scanf("%d", &n);
        
        while(i<=n){
            int gc = gcd(lcm, i);
            
            if(gc==1){
                lcm *= i;
            }
            else if(gc==i){
                lcm *= 1;
            }
            
            else{
                lcm *= (i/gc);
            }
            i++;
        }
        
        printf("%d\n", lcm);
    }
    return 0;
}
