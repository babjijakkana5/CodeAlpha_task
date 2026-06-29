#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Account 
{
    int accNo;
    char name[50];
    float balance;
};
void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();
int main() 
{
    int choice;
    while (1) 
    {
        printf("\n----- BANK MENU------\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: createAccount(); 
                break;
            case 2: deposit(); 
                break;
            case 3: withdraw();  
                break;
            case 4: balanceEnquiry();
                 break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
void createAccount() 
{
    struct Account acc;
    FILE *fp = fopen("bank.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Name: ");
    scanf("%s", acc.name);

    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}
void deposit() 
{
    int accNo, found = 0;
    float amount;
    struct Account acc;
    FILE *fp, *temp;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    fp = fopen("bank.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while (fread(&acc, sizeof(acc), 1, fp)) 
    {
        if (acc.accNo == accNo) 
        {
            acc.balance += amount;
            found = 1;
        }
        fwrite(&acc, sizeof(acc), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if (found)
        printf("Deposit successful!\n");
    else
        printf("Account not found!\n");
}
void withdraw() 
{
    int accNo, found = 0;
    float amount;
    struct Account acc;
    FILE *fp, *temp;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    fp = fopen("bank.dat", "rb");
    temp = fopen("temp.dat", "wb");

    while (fread(&acc, sizeof(acc), 1, fp)) 
    {
        if (acc.accNo == accNo) 
        {
            if (acc.balance >= amount) 
            {
                acc.balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
        }
        fwrite(&acc, sizeof(acc), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("bank.dat");
    rename("temp.dat", "bank.dat");

    if (!found)
        printf("Account not found!\n");
}
void balanceEnquiry() 
{
    int accNo, found = 0;
    struct Account acc;
    FILE *fp = fopen("bank.dat", "rb");

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) 
    {
        if (acc.accNo == accNo) {
            printf("Account Holder: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Account not found!\n");
}