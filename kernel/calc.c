// calc.c 
// simple calculator for JOS 
// Author: Jacob Mealey

#include "calc.h"

void set_sing_pos(int sign)
{
	CALC_AMOUNT = CALC_AMOUNT * sign;
}

void add_number(int number)
{
	CALC_AMOUNT = CALC_AMOUNT + number;
}
