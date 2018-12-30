#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define max(a,b) (a>b)? a:b                     //Using Macros and Ternary operator

int main(){
    int grid[20][20];
    for(int grid_i = 0; grid_i < 20; grid_i++){
    	for(int grid_j = 0; grid_j < 20; grid_j++){
    		scanf("%d",&grid[grid_i][grid_j]);
    	}
    }
    
    long long product_h=1, product_v=1, product_d1=1, product_d2=1, product;
    for(int grid_i = 0; grid_i < 17; grid_i++){
        for(int grid_j = 0; grid_j < 20; grid_j++){
            if(grid[grid_i][grid_j] && grid[grid_i+1][grid_j] && grid[grid_i+2][grid_j] && grid[grid_i+3][grid_j]){
                product = grid[grid_i][grid_j]*grid[grid_i+1][grid_j]*grid[grid_i+2][grid_j]*grid[grid_i+3][grid_j];
                if(product > product_h)
                    product_h = product;
            }
        }
    }
           
    for(int grid_i = 0; grid_i < 20; grid_i++){
        for(int grid_j = 0; grid_j < 17; grid_j++){
            if(grid[grid_i][grid_j] && grid[grid_i][grid_j+1] && grid[grid_i][grid_j+2] && grid[grid_i][grid_j+3]){
                product = grid[grid_i][grid_j]*grid[grid_i][grid_j+1]*grid[grid_i][grid_j+2]*grid[grid_i][grid_j+3];
                if(product > product_v)
                    product_v = product;
            }
        }
    }
    
    for(int grid_i = 0; grid_i < 17; grid_i++){
        for(int grid_j = 0; grid_j < 17; grid_j++){
            
            if(grid[grid_i][grid_j] && grid[grid_i+1][grid_j+1] && grid[grid_i+2][grid_j+2] && grid[grid_i+3][grid_j+3]){
                product = grid[grid_i][grid_j]*grid[grid_i+1][grid_j+1]*grid[grid_i+2][grid_j+2]*grid[grid_i+3][grid_j+3];
                if(product > product_d1)
                    product_d1 = product;
            }
        }
    }
    
    for(int grid_i = 0; grid_i<17; grid_i++){
        for(int grid_j = 19; grid_j>=3; grid_j--){
            if(grid[grid_i][grid_j] && grid[grid_i+1][grid_j-1] && grid[grid_i+2][grid_j-2] && grid[grid_i+3][grid_j-3]){
                product = grid[grid_i][grid_j]*grid[grid_i+1][grid_j-1]*grid[grid_i+2][grid_j-2]*grid[grid_i+3][grid_j-3];
                if(product > product_d2)
                    product_d2 = product;
            }
        }
    }

    long long v1 = max(product_h, product_v);
    long long v2 = max(product_d1, product_d2);
    
    if(v1 > v2)
        printf("%lld\n", v1);
    else
        printf("%lld\n", v2);
    
    return 0;
}
