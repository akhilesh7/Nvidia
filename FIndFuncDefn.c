#include <stdio.h>

int getLine(const char* _Str, const char* _Char)
{
	int line = 1;
	for (; _Str < _Char; ++_Str)
		if (*_Str == '\n' || (*_Str == '\\' && *(_Str + 1) == 'n'))
			line++;
	//printf("%d",line);
	return line;
}

int FindFunctionDefn(char* strFunctionName, char* strSourceCode)
{
	if (strFunctionName == 0 || strSourceCode == 0)
		return -1;

	char *pos = strSourceCode, *end = strSourceCode + strlen(strSourceCode), *tmp, c;
	int len = strlen(strFunctionName);
	while (pos <= end)
	{
		if ((pos = strstr(pos, strFunctionName)) == 0) // find the next function name match
			break;

		tmp = pos;
		pos += len; // move pointer after function name match, to check if it's a longer name func1, func2 etc or it's the correct target

		c = *pos;
		if (c == ' ' || c == '\t' || c == '\n' || c == '(') // check it's a correct target with optional spacing
			++pos;
		else
			continue; // if looking for func but we are find func1, func2 etc

		if ((pos = strchr(pos, ')')) == 0)
			break;

		pos++;
		while (pos != end)
		{
			c = *pos;
			if (c == ' ' || c == '\t' || c == '\n')
				pos++;
			else if (c == '{') // start of function body
				
				return getLine(strSourceCode, tmp);
			else if (c == ';') // end of statement where function was called
				continue;
		}
	}
	return 0;
}

int main()
{
	//Implement the following C function: unsigned int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode);
	//FindFuntionDefn takes two strings as inputs: a function name and a program string;
	//it returns as an output the line number that contains the function definition (differentiate this with the function calls) in the program string.
	//The program string is a valid C code; it contains a character "\n" indicate the end of a line with the line number starts from one.
	//The program string is guaranteed not to contain any C (or C++) comments. The function FindFunctionDefn returns 0 if it fails to find the function definition.
	//For example, char strFunctionName[] = "func2"; char strSourceCode[]= "int func1(){return 0;}\\n int func2(){return 1;}\\n" "int main(int argc, char*argv[]){return func2();}\\n";
	char strFunctionName[] = "func2";
	char strSourceCode[] = "int func1(){return 0;}\\n int func2(){return 1;}\\n" "int main\n(int argc, char*argv[]){return func2();}\\n";
	//FindFunctionDefn(strFunctionName, strSourceCode) should return 2.
	int testsFailed = 0;
	if (FindFunctionDefn(strFunctionName, strSourceCode) != 2) testsFailed++;
	if (FindFunctionDefn("func1", strSourceCode) != 1) testsFailed++;
	if (FindFunctionDefn("main", strSourceCode) != 3) testsFailed++;
	if (FindFunctionDefn("func", strSourceCode) != 0) testsFailed++;
	if (testsFailed == 0)
		printf("FindFunctionDefn tested succesfully\n");
	else
		printf("FindFunctionDefn failed %d tests", testsFailed);

	return testsFailed;

	
}
