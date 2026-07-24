#include <stdio.h>

struct Room{
      int room_number;
      double price;
      bool is_booked;      
};

void book_room(struct Room hotel[], int index){
     if (!hotel[index].is_booked){
        printf("Room %d booked successfully!\n", hotel[index].room_number);
        hotel[index].is_booked = true;
     } 
     else printf("Room %d is already booked!\n", hotel[index].room_number);    
}

int main(){
    struct Room hotel[3] = { {101, 500.45, false}, {102, 650.35, false}, {103, 550.20, true} };
    while(1){
        int num;
        printf("| --------Room List-------- |\n");
        printf("1. Room: 101, Price: 500.45$\n");
        printf("2. Room: 102, Price: 650.35$\n");
        printf("3. Room: 103, Price: 550.20$\n");
        printf("Which room do you want? ");
        scanf("%d", &num);
        if(num < 1 || num > 3){
            printf("Invalid room number.\n");
            continue;
        }
        else {
            int index = num - 1;
            book_room(hotel, index);
        }
        printf("Press 0 to exit: ");
        scanf("%d", &num);
        if (num == 0) break; 
    }
}
