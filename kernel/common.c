//common.c for all common tasks 
//Jacob Mealey
//

int string_length(char* string)
{
	int i = 0;
	while(string[i] != '\0')	
	{
		i++;
	}
	return i;
}
void concatc(char* a, char b, char* c)
{
	int len = string_length(a) + 1;
	int i =0;
	while(i < string_length(a))
	{
		c[i] = a[i];
		i++;
	}
	c[i] = b;
	c[len] = '\0';
}
