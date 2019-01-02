//Full of debugs...

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int basicAdd(int number1[],int number2[],int first){             //Makes changes to first number and returns position of first digit
    int sum, unit=0, carry=0, k=0;
    first += 1;
    while(first--){
        sum = number1[k] + number2[k] + carry;
        unit = sum%10; carry = sum/10;
        number1[k] = unit;
        k++;
    }
    
    while(carry!=0){
        sum = number1[k] + carry;
        unit = sum%10; carry = sum/10;
        number1[k] = unit;
        k++;
    }
    
    return (k-1);
}

int main() {
    
    int N, num, first;
    scanf("%d", &N);
    
    int number1[60];
    memset(number1, 0, sizeof(number1));
    
    int number2[60];
    memset(number2, 0, sizeof(number2));
    
    num = getchar();
    for(int i=0; i<50; i++){
        num = getchar() - '0';
        number1[49-i] = num;
    }
    
    first = 49;
    
    for(int i=1; i<N; i++){
        num = getchar();
        
        for(int j=0; j<50; j++){
            num = getchar() - '0';
            number2[49-j] = num;
        }
        
        first = basicAdd(number1, number2, first);
    }
    
    for(int i=0; i<10; i++){
        printf("%d", number1[first]);
        first--;
    }
    
    return 0;
}
