#include <stdio.h>
void view_stack_frame (int a, int b, int c, int d); //declaration of function before the main method

int main(void)
{
    int a = 12;      //all variables inside the callers’ stack frames are all of the same data type int
    int b = 400;    //The variables and values were chosen at random.
    int c = 32;
    int d = 53;

    view_stack_frame(a, b, c, d); //calling of function
}

void view_stack_frame(int a, int b,int c,int d) //A function is made up of the name of the function, return type and its parameters.
{
    printf("1st Variable: %p\t %d\n",&a,a);     //The function displays output organized in two columns, the first displaying the
    printf("2nd Variable: %p\t %d\n",&b,b);     // addresses of variables while the second displays their corresponding values.
    printf("3rd Variable: %p\t %d\n",&c,c);
    printf("4th Variable: %p\t %d\n",&d,d);
}
