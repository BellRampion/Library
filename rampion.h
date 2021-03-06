/*rampion.h*/

//Functions are listed in alphebetical order before macros. Each group is sorted within itself.

/****FUNCTIONS****/

//**bgetline**
int bgetline(char s[], int putNl);
int bgetline(char s[], int putNl){
	int i, c;

	for (i=0; i<10000-1 && (c=getchar()) !='$' && c!='\n'; ++i)
		s[i] = c;
	if ((c == '\n') && (putNl == 1))
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
//**compStr**
int compStr(char s1[], char s2[]);
int compStr(char s1[], char s2[]){
	int i = 0;

	for (i = 0; s1[i] == s2[i]; i++){ //i and j start out at 0. Test to see if the end of 's1' has been reached.
        if (s1[i] == '\0')
            return 0;
	}
    return s1[i] - s2[i];
}
//**copySubStr**
//Copies a substring from src to dest using subStart and subEnd as indexes. Copies at most maxLen chars, not including the NULL pointer
int copySubStr(char src[], char dest[], int srcStart, int srcEnd, int maxLen);
int copySubStr(char src[], char dest[], int srcStart, int srcEnd, int maxLen){
    int iter, i;

    //Make sure start is less than end
    if (srcStart > srcEnd)
        return -1;

    //Make sure end is less than maxLen
    if (srcEnd > maxLen)
        return -2;

    //If srcEnd is -1, go to the end of the array
    if (srcEnd == -1)
        srcEnd = strlen(src);

    //Copy substring bounded by srcStart and srcEnd to dest
    for (iter = srcStart, i = 0; iter <= srcEnd && src[iter] != '\0' && i < maxLen; iter++, i++){
        dest[i] = src[iter];
    }

    dest[i] = '\0';

    //Return length of dest
    return i;
}
//**getIndentLevel**
//Returns the indent level of a string, calculated by the number of spaces or tabs before the first non-whitespace character
int getIndentLevel(char src[], int numSpaces);
int getIndentLevel(char src[], int numSpaces){
    int indentLevel = 0;
    int i;
    int spaceCount = 0; //For keeping track of how many spaces have been found so far

    //loop through string and check for whitespace until first non-whitespace character found
    for (i = 0; i < MAXLENGTH && src[i] != '\0'; i++){
        if (src[i] == 32)
        {
            spaceCount++;
        }
        else if (src[i] == '\t')
        {
            indentLevel++;
        }
        else break;

        //Check if a new indent level has been reached; if so, reset count
        if (spaceCount == numSpaces)
        {
            indentLevel++;
            spaceCount = 0;
        }
    }

    return indentLevel;

} //End getIndentLevel
//**indexOfStr**
//Finds and returns the index of the first char of subStr in mainStr, or -1 if not found
int indexOfStr(char *mainStr, char *subStr);
int indexOfStr(char *mainStr, char *subStr){
    int index;
    char *result;

    //If the substring is in the main string, find and return the index
    if (result = strstr(mainStr, subStr) != NULL)
    {
        index = result - mainStr;
    }
    //If no match, return -1
    else return -1;

    //Shouldn't happen, but as a safety net
    return 0;
}
//**pairMarkers**
//Given an opening marker index and the closing marker char, finds the matching closing marker for the opening marker at the index in src
int pairMarkers(int openIndex, char closingChar, char src[]);
int pairMarkers(int openIndex, char closingChar, char src[]){

    /*This function works by counting the number of markers found so far. The counter starts at 0. When the program finds another opening marker, it increases the counter by 1. When it finds the next closing marker, it decreases the counter by 1. When the counter reaches zero again and the closing marker is found, it must be the corresponding closing marker for the given opening one.*/

    int i, counter;
    char openingChar;

    counter = 0;

    //Make sure that openIndex is actually within the bounds of src's length
    if (strlen(src) <= openIndex)
        return -2;

    //Look through src for the closing marker, starting at the given index
    i = openIndex;
    openingChar = src[i];
    while (src[i] != '\0'){
        if (src[i] == openingChar)
        {
            counter++;
        }
        else if (src[i] == closingChar)
        {
            counter--;
            if (counter == 0)
            {
                return i;
            }
        }
        else ;
        i++;
    }

    //-1 means closing char not found
    return -1;
}
//**stof**
double stof(char s[]);
double stof(char s[]){

    double val, power;
    int i, sign;
    i = 0;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; (s[i] >=48) && (s[i] <= 57); i++){ //If the character is a numeral,
        val = 10.0 * val + (s[i] - '0'); //the value is equal to 10 times the current value (to move it up one place) plus the numeral converted from ASCII
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; (s[i] >=48) && (s[i] <= 57); i++){
        val = 10.0 * val + (s[i] - '0'); //the value is equal to 10 times the current value (to move it up one place) plus the numeral converted from ASCII
        power *= 10.0;
    }

    return sign * val / power; //returns the string converted to a double
}
char stringCopy(char *s, char *s2);
char stringCopy(char *s, char *s2){
    while(*s++ = *s2++){
        ;
     }
    return *s;
}

/****MACROS****/

//ctoi
#define ctoi(c) i = (c -'0');

//fileLength
#define fileLength(fp, filelength, fileName, s) fp = fopen(fileName, "r"); \
									for (filelength = 0; fgets(s, MAXLENGTH, fp) != NULL; filelength++){ \
										; \
									} \
                                    fclose(fp);

//floatDebug
#define floatDebug(y, x) if (debug == 1) \
                        { \
                            printf("%s %f\n", y, x);\
                        }
//intDebug
#define intDebug(y, x) if (debug == 1) \
                        { \
                            printf("%s %i\n", y, x);\
                        }
//printAsChar
#define printAsChar(expr, x, y) x = y; printf(#expr " %c\n", x);

//printNl
#define printNl printf("\n")

//strDebug
#define strDebug(y, x) if (debug == 1) \
                    { \
                        printf("%s %s\n", y, x);\
                    }

//toLowercase
#define toLowercase(c) ((c >= 'A') && (c <= 'Z')) ? c + ('a' - 'A') : c //if c >= 'A' && c <= 'Z', then add 'a' - 'A' to c; else leave it be

//toUppercase
#define toUppercase(c) if (c >= 'a' && c <= 'z') \
                        { \
                            c+= ('A' - 'a'); \
                        }
//Ternery version
#define toUppercase2(c) ((c >= 'A') && (c <= 'Z')) ? c + ('A' - 'a') : c
