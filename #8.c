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
        int n,k,answer=0,product=1; 
        scanf("%d %d",&n,&k);
        char* num = (char *)malloc(512000 * sizeof(char));              //Method to input a string
        scanf("%s",num);
        
        for(int i=0; i<n-k; i++){
            for(int j=i; j<i+k; j++){
                product *= (num[j] - '0');
            }
            
            if(product > answer){
                answer = product;
            }
            product = 1;
        }
        
        printf("%d\n", answer);
    }
    return 0;
}
