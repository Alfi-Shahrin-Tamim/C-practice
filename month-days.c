#include <stdio.h>

int main(){
    int month, year;
    int months[12] = {31, 28,31, 30, 31, 30,31, 31, 30, 31,30,31};
    printf("Month Year: ");
    scanf("%d %d", &month, &year);
    if(month < 1 || month > 12) printf("Invalid Month");
    else {
        if(month == 2){
            if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) printf("29");
            else printf("28");
        }
        else printf("%d", months[month - 1]);
    }
    printf("\n");
}
