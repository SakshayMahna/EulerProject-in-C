#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define digits 4000
#define n 10001

int powers_of_2[n][digits];

void multiply_by_2(){
    int carry = 0, pro;
    powers_of_2[0][0] = 1;
    
    for(int i=1; i<n; i+=1){
        carry = 0;
        for(int j=0; j<digits; j+=1){
            pro = 2*powers_of_2[i-1][j] + carry;
            powers_of_2[i][j] = pro%10;
            carry = pro/10;
        }
    }

    return;
}

int main() {
    int T;
    scanf("%d", &T);
    memset(powers_of_2, 0, sizeof(powers_of_2));
    multiply_by_2();

    while(T--){
        int N, sum;
        scanf("%d", &N);

        sum = 0;
        for(int i=0; i<digits; i+=1){
            sum += powers_of_2[N][i];
        }

        printf("%d\n", sum);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
