#include<stdio.h>
int main()
{
    float num1,num2,res;
    int choice;
    printf("Enter the value of first number: ");
    scanf("%f",&num1);
    printf("Enter the value of second number: ");
    scanf("%f",&num2);
    printf("\nSelect to do which opertion to preform\n");
    printf(" 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        res=num1+num2;
        printf("Addition of two number:%.2f\n",res);
        break;
        case 2:
        res=num1-num2;
        printf("Subtraction of two number:%.2f\n",res);
        break;
        case 3:
        res=num1*num2;
        printf("Multipication of two number:%.2f\n",res);
        break;
        case 4:
        if(num2==0)
        {
            printf("Error\n");
        }
        else
        {
            res=num1/num2;
            printf("Division of two number:%.2f\n",res);
            break;
        }
        default:
        {
            printf("Invalid Input");
        }
    }
    return 0;
}