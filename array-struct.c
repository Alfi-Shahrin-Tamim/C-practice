#include <stdio.h>

struct info{
    char name[100];
    int age;
    int height;
    bool kind;
};

int main(){
    struct info people[3] = { {"Nagro", 20, 6, true}, {"Tamim", 14, 5, false}, {"Sajid", 16, 5, true} };
    for(int i = 0; i < 3; i++){
        if(people[i].kind == true){
             printf("The person's name is %s.\n", people[i].name);
             printf("The person's age is %d.\n", people[i].age);
             printf("The person's height is %d.\n", people[i].height);
             printf("The person is good.\n");
        }
    }
}
