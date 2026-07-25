#include <stdio.h>

typedef struct{
    bool is_booked;
    char name[50];
} seat;

int main(){
    seat cinema[3][3];
    int i,j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) cinema[i][j].is_booked = false;
    }
    while(1){
        printf("Which row do you want to choose? ");
        scanf("%d", &i);
        if(i < 0 || i > 2){
            printf("Rows are only available from 0-2.\n");
            continue;
        }
        printf("Which column do you want to choose? ");
        scanf("%d", &j);
        if(j < 0 || j > 2){
            printf("Columns are only available from 0-2.\n");
            continue;
        }        
        if(cinema[i][j].is_booked == false){
            printf("Write down your name: ");
            scanf("%s", cinema[i][j].name);
            printf("The seat has been booked by [%s]\n", cinema[i][j].name);
            cinema[i][j].is_booked = true;
        }
        else printf("Sorry, that seat is already taken by [%s].\n", cinema[i][j].name);
        printf("Press 0 if you want to exit: ");
        scanf("%d", &i);
        if(i == 0) break;
    }  
}
