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
int string_compare(char* str1, char* str2)
{
	int i = 0;
	int flag = 0;
	
	while(str1[i]!='\0' && str2[i]!='\0')	
	{
		if(str1[i] != str2[i]){
			flag = 1;
			break;
		}
		i++;
	}
	if(flag == 0 && str1[i]=='\0' && str2[i]=='\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
