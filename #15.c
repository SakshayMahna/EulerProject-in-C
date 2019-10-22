#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a, b) (a<b)? a:b
#define MOD 1000000007

long long combo(int n, int r){
    long long product[501]={0};
    product[0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=min(i,r); j>0; j--){
            product[j] = (product[j-1]%MOD + product[j]%MOD)%MOD;
        }
    }
    return product[r];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    
    while(T--){
        int N, M;
        scanf("%d %d", &N, &M);
        
        printf("%lld\n", combo(N+M, M)%MOD);
        
    }
    return 0;
}
