//#HINTS saved on this one!!

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main(){

    int T;
    scanf("%d", &T);
    
    while(T--){
        int N, a, b, c, answer=1, product;
        bool isit = false;
        scanf("%d", &N);
        
        for(b=1; b<=N/3; b++){
            a = ((N*N) - 2*b*N);
            a /= 2*(N-b);
            
            c = N-a-b;
            
            product = a*b*c;
            if(c*c == a*a + b*b){
                isit = true;
                if(product > answer)
                    answer = product;
            }
        }
        
        if(isit)
            printf("%d\n", answer);
        else
            printf("-1\n");
    }

    return 0;
}
