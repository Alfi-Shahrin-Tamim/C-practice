#include <stdio.h>

typedef struct{
    int account_number;
    int pin;
    double balance;
    char name[50];
} Account;

void check_balance(Account acc[], int index_number){
    double current = acc[index_number].balance;
    printf("Your balance is %0.3f\n", current);   
}

void deposit(Account acc[], int index_number){
    double money;
    printf("Deposit amount: ");
    scanf("%lf", &money);
    acc[index_number].balance = acc[index_number].balance + money;
    printf("%0.3f$ have been deposited to your account.\n", money);
}

void withdraw(Account acc[], int index_number){
    double money;
    double current = acc[index_number].balance;
    printf("Withdraw amount: ");
    scanf("%lf", &money);
    if (money > current) printf("Insufficient funds.\n");
    else {
        acc[index_number].balance = acc[index_number].balance - money;
        printf("$%0.3f has been withdrawn from your account.\n", money);
    }   
}

int main(){
    Account account[3] = { {1001, 1234, 500.00, "Nagro"}, 
                         {1002, 3125, 600.45, "Noobde"},
                         {1003, 5641, 445.20, "Negar"}
                       };
    int acc_num, pin_num, j, index_num;                
    while(1){
        printf("Your account number: ");
        scanf("%d", &acc_num);
        printf("You pin number: ");
        scanf("%d", &pin_num);
        for(j = 0; j < 3; j++){
            if(acc_num == account[j].account_number && pin_num == account[j].pin){
                index_num = j;
                printf("Welcome Mr. %s, What would you like to do today?\n", account[j].name);
                while(1){
                    int option;
                    printf("1. Check balance\n2. Deposit\n3. Withdraw\n4. Logout\n");
                    printf("Your choice (1-4): ");
                    scanf("%d", &option);
                    if(option == 1) check_balance(account, index_num);
                    else if (option == 2) deposit(account, index_num);
                    else if (option == 3) withdraw(account, index_num);
                    else if (option == 4) break;
                    else printf("Invalid choice.\n"); 
                }                
                break;
            }
        }
        if(j == 3)printf("Invalid credentials.\n");    
        printf("Press 0 if you want to exit: ");
        scanf("%d", &j);
        if(j == 0) return 0;
    }
}
