#include <stdio.h>
#include <ctype.h>

//declaration of functions before the main method
void welcomePrompt();
float Shipping_calculation(float TotalKg);
float Discount_calculation(float Totalmoney);
void Receipt(float AKg, float BKg, float CKg, float Totalmoney, float Shipping);


int main(void)
{
    char ch;              //input character of user's choice
    float artichokes;     //Inputted amount of artichokes in Kg
    float onions;         //Inputted amount of onions in Kg
    float carrots;        //Inputted amount of carrots in Kg
    float AKg = 0;        //Cumulative total of artichokes in Kg
    float BKg = 0;        //Cumulative total of onions in Kg
    float CKg = 0;        //Cumulative total of carrots in Kg
    float Amoney = 0;     //Price of artichokes
    float Bmoney = 0;     //Price of onions
    float Cmoney = 0;     //Price of carrots
    float TotalKg = 0;    //Total amount of Kg of artichokes, onions and carrots.
    float Totalmoney = 0; //Total price for inputted artichokes, onions and carrots
    float Shipping = 0;   //Declaration of a variable for shipping
    float Discount = 0;   //Declaration of a variable for discount

    welcomePrompt(); //calling of function

    while ((ch = getchar()) != 'q') {  //enters a while loop while the inputted character is not equal to q
        while (getchar() != '\n');     //flushes the buffer so that the program considers only the first inputted letter and ignores any other inputted letters
        if (isupper(ch)) {             //if an uppercase is inputted, the program will output a message showing it reads lowercase only
            printf("I recognize only lowercase letters.\n");
            printf("Press:\n'a' to enter the amount in Kg of artichokes you desire.\n");
            printf("'b' to enter the amount in Kg of onions you desire.\n");
            printf("'c' to enter the amount in Kg of carrots you desire.\n");
            printf("Press q when you are done.\n");
        }
        else {
            switch (ch) { //switch statement is used to enter a case which matches the inputted character by the user.

                case 'a' : //case to input amount of artichokes
                    printf("Please enter the desired amount of artichokes in Kg:\n");
                    while(scanf("%f", &artichokes)<=0){ //if anything other than numbers are inputted, the program enters a while loop and
                        printf("Invalid input\n");      //an error is outputted to the user and asks for a valid input.
                        printf("Please enter a new amount of artichokes\n");
                        while (getchar() != '\n');      //flushes the buffer so that any inputs are then removed from the buffer so that they are not added each time
                    }
                    AKg+=(artichokes);                  //the cumulative total of artichokes in Kg are calculated for each case
                    while (getchar() != '\n');
                    break;

                case 'b' : //case to input amount of onions
                    printf("Please enter the desired amount of onions in Kg:\n");
                    while(scanf("%f", &onions)<=0) {
                        printf("Invalid input\n");
                        printf("Please enter a new amount of onions\n");
                        while (getchar() != '\n');
                    }
                    BKg+=(onions);
                    while (getchar() != '\n');
                    break;
                case 'c' :
                    printf("Please enter the desired amount of carrots in Kg:\n");
                    while(scanf("%f", &carrots)<=0) {
                        printf("Invalid input\n");
                        printf("Please enter a new amount of carrots\n");
                        while (getchar() != '\n');
                    }
                    CKg+=(carrots);
                    while (getchar() != '\n');
                    break;
                default : //when the inputted character does not match any of the cases, the program jumps to the default
                    printf("Please enter a, b or c.\n");

            }
            printf("Press:\n'a' to enter the amount in Kg of artichokes you desire.\n");
            printf("'b' to enter the amount in Kg of onions you desire.\n");
            printf("'c' to enter the amount in Kg of carrots you desire.\n");
            printf("Press q when you are done.\n");

        }

    }
    Amoney=(AKg * 2.05);        // the cumulative total of the amount of artichokes multiplied by the price for 1kg
    Bmoney=(BKg *1.15);         // the cumulative total of the amount of onions multiplied by the price for 1kg
    Cmoney=(CKg *1.09);         // the cumulative total of the amount of carrots multiplied by the price of 1Kg
    TotalKg=AKg+BKg+CKg;
    Totalmoney=Amoney+Bmoney+Cmoney;

    Shipping = Shipping_calculation(TotalKg);

    printf("Your total purchase is %.2fKg of artichokes, %.2fKg of onions and %.2fKg of carrots.\n", AKg, BKg, CKg);
    Discount = Discount_calculation(Totalmoney);
    printf("Your total cost excluding shipping is %.2feuros.\n",Totalmoney-Discount);
    printf("Your total cost including shipping is %.2feuros.\n",Shipping+Totalmoney-Discount);
    printf("Thank you for your purchase!\n");

    Receipt(AKg,BKg,CKg,Totalmoney,Shipping);

    return 0;
}

void welcomePrompt(){
    printf("Welcome to YouGreens.com\n");
    printf("Please input the letter:\n\t'a' to enter the amount in Kg of artichokes you desire.\n\t");
    printf("'b' to enter the amount in Kg of onions you desire.\n\t");
    printf("'c' to enter the amount in Kg of carrots you desire.\n");
    printf("Press q when you are done.\n"); //printing the instructions to the user
}

float Shipping_calculation(float TotalKg){
    if (TotalKg<=5) {
        return 6.50;

    } else if(5<TotalKg<20) {
        return 14;

    }else if(TotalKg>=20) {
        return 14 + (TotalKg * .5);
    }
}

float Discount_calculation(float Totalmoney){

    if (Totalmoney>=100) {
        printf("Congratulations! You get 5%% discount!\n");
        return (14 + (0.05 * Totalmoney));
    }
    return  0.0;
}

void Receipt(float AKg, float BKg, float CKg, float Totalmoney, float Shipping) {
    FILE *fp;

    fp = fopen("Receipt.txt", "w");
    fprintf(fp, "Thank you for your purchase!\n");
    fprintf(fp, "Your total purchase is %.2fKg of artichokes, %.2fKg of onions and %.2fKg of carrots.\n", AKg, BKg, CKg);
    fprintf(fp, "Your total cost excluding shipping is %.2f euros.\n", Totalmoney);
    fprintf(fp, "Your total cost including shipping is %.2f euros.\n", Shipping + Totalmoney);

    fclose(fp);
}

