#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void func_h(int num){
    int c = 0;
    for(int i=1;i<101;i++){
        if(i%num==0){
            printf("%d ", i);
            c+=1;
        }
    }
    if(!c) printf("No such numbers\n");
}

void func_p(int num){
    int c = 0;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) c++;
    }
    if (c==0) printf("Input number is prime\n");
    else printf("Input number is not prime\n");
}

void func_s(int num){
    int num1 = num, len = 0;
    while(num1){
        len++;
        num1/=10;
    }
    int array_of_numbers[len], i = len;
    while(num){
        array_of_numbers[len-1] = num%10;
        len--;
        num/=10;
    }
    for (int k=0;k<i;k++) printf("%d ", array_of_numbers[k]);
}

void func_e(int num){
    if(num>10) printf("Input number must be <= 10");
    else
    {
        for(int i=1;i<=10;i++){
            printf("For %d: ", i);
            unsigned long rez = 1;
            for(int k=1;k<=num;k++){
                rez*=i;
                printf("%lu ", rez);
            }
            printf("\n");
        }
    }
}

void func_a(int num){
    int result = 0;
    for(int i=1;i<=num;i++){
        if(INT_MAX-i<result)
        {
            printf("Overflow error!\n");
            result=0;
            break;
        }
        else result+=i;
    }
    if(result) printf("%d ", result);
}

void func_f(int num){
    unsigned long long result = 1;
    for(int i=2;i<=num;i++){
        if(ULLONG_MAX/i<result)
        {
            printf("Overflow error f!\n");
            result=0;
            break;
        }
        else result*=i;
    }
    if(result) printf("%llu ", result);
}

int main(int argc, char* argv[]){
    //--------------------------------------- Проверка количества аргументов
    if(argc==1||argc>3)
    {
        printf("Input error: must be 2 arguments!\n");
        return 0;
    }
    //--------------------------------------- Перевод в число с проверкой
    unsigned long len = strlen(argv[1]);
    int num = 0, i = 0;
    while(len)
    {
        if(isdigit(argv[1][len-1]))
        {
            int power = 1;
            for (int k=0;k<i;k++){
                power*=10;
            }
            int sum = (argv[1][len-1]-48)*power;
            if(INT_MAX-num>sum) num+=sum;
            else
            {
                printf("Overflow error!\n");
                return 0;
            }
            i+=1;
        }
        else
        {
            printf("Input error: %s is not a number!\n", argv[1]);
            return 0;
        }
        len--;
    }
    //--------------------------------------- Проверки флага
    if(strlen(argv[2])!=2 || argv[2][0]!='-' && argv[2][0]!='/')
    {
        printf("Input error: wrong flag!\n");
        return 0;
    }
    //--------------------------------------- Определение введенного флага и проверка на существование
    if(argv[2][1]=='h') func_h(num);
    else if(argv[2][1]=='p') func_p(num);
    else if(argv[2][1]=='s') func_s(num);
    else if(argv[2][1]=='e') func_e(num);
    else if(argv[2][1]=='a') func_a(num);
    else if(argv[2][1]=='f') func_f(num);
    else
    {
        printf("Input error: wrong flag!\n");
        return 0;
    }
    //---------------------------------------
    return 0;
}
