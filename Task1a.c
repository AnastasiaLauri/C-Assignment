// Exercise 1 Problem Solving
// Created by Anastasia Lauri ID 12600L on 09/11/2017.
// CPS 1011

#include <stdio.h> //This is a header which contains a library of functions for performing inputs and outputs,
                   //some variable types and several macros


int main(void)
{
    int year=0;     //Initialising year to zero
    float Tom=200;  //Tom's initial amount
    float Joan=200; //Joan's initial amount

    while(Joan<=Tom){   //Loop until Joan's interest exceeds Tom's interest

    year++;             //Increment yearly
    Tom+= 200*0.15;     //Tom's yearly increase in simple interest
    Joan+= 0.10*Joan;   //Joan 's yearly increase in compound interest
}
    printf("Joan's invested sum is larger than Tom's in Year %d.\n",year);
    printf("In this year Tom's invested sum is %.2feuro.\n",Tom);
    printf("While Joan's invested sum is %.2feuro.\n",Joan);        //Output yearly interest of Tom and Joan

    return 0;
}
