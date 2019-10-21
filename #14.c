#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max(a, b) (a>b)? a:b
#define maxN 6000001
#define maxT 10002

unsigned long long inputs[maxT], collatz_length[maxN], max_cl[maxN];  

unsigned long long collatz(long long n){
    if(n <= 1) return 0;
    if(n<maxN && collatz_length[n]) return collatz_length[n];

    if(n>=maxN){
        if(n%2 == 0) return 1 + collatz(n/2);
        else return 2 + collatz((3*n + 1)/2);
    }

    if(n%2 == 0) collatz_length[n] = 1 + collatz(n/2);
    else collatz_length[n] = 2 + collatz((3*n + 1)/2);

    return collatz_length[n];
}

int main() {
    int T;
    scanf("%d", &T);

    unsigned long long greatest_input = 0;
    for(int i=0; i<T; i+=1){
        scanf("%lld", inputs+i);
        greatest_input = max(greatest_input, inputs[i]);
    }

    memset(collatz_length, 0, sizeof(collatz_length));
    memset(max_cl, 0, sizeof(max_cl));

    for(unsigned long long i=1; i<=greatest_input; i+=1){
        if(i!=1 && !collatz_length[i]) collatz_length[i] = collatz(i);

        if(collatz_length[i] >= collatz_length[max_cl[i-1]])
            max_cl[i] = i;
        else
            max_cl[i] = max_cl[i-1];
    }

    for(int i=0; i<T; i+=1){
        printf("%lld\n", max_cl[inputs[i]]);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
