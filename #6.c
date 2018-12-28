#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        long n; 
        scanf("%ld",&n);
        
        long squaredsum = n*(n+1)*(2*n + 1);
        squaredsum = squaredsum/6;
        
        long sumsquared = n*(n+1);
        sumsquared = sumsquared/2;
        sumsquared *= sumsquared;
        
        printf("%ld\n", sumsquared - squaredsum);
    }
    return 0;
}
