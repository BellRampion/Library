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
