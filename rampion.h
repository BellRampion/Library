/*rampion.h*/

//Functions are listed in alphebetical order before macros. Each group is sorted within itself. 

/****FUNCTIONS****/

//**bgetline**
int bgetline(char s[], int putNl);
int bgetline(char s[], int putNl){
	int i, c;
	
	for (i=0; i<MAXLENGTH-1 && (c=getchar()) !='$' && c!='\n'; ++i)
		s[i] = c;
	if ((c == '\n') && (putNl == 1))
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
//**compare**
int compare(char s1[], char s2[]);
int compare(char s1[], char s2[]){
	int i, j, k, l, m;
	i = 0;
	k = 0;

	for (i = 0; s1[i] != '\0'; i++){ //i and j start out at 0. Test to see if the end of 's1' has been reached.
		//printf("i: %i\n", i); // Print the value of i, a.k.a. the place it's at in 's1'. 
	    //printf("K: %i\n", k);
		    if (s1[i] != s2[k])//If the current character in 's1' is not equal to the current character in 's2',
		    {
		    	//printf("k: %i\n", k); //Print where it is in 's2';
			    printf("Strings are not identical. s1[i]: %c s2[k]: %c\n", s1[1], s2[k]);
			    return 2;			
		    }
		    else k++;
	}
    
    return i;
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
        DEBUG("Value:", val);
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; (s[i] >=48) && (s[i] <= 57); i++){
        val = 10.0 * val + (s[i] - '0'); //the value is equal to 10 times the current value (to move it up one place) plus the numeral converted from ASCII
        DEBUG("Value:", val);
        power *= 10.0;
        DEBUG("So far power is:", power);
    }
    
    DEBUG("String converted to double:", sign*val/power);
    return sign * val / power; //returns the string converted to a double
}

/****MACROS****/

//ctoi
#define ctoi(c) i = (c -'0');

//intDebug
#define intDebug(y, x) if (debug == 1) \
                            { \
                                printf("%s %i\n", y, x);\
                            }

//fileLength
#define fileLength(fp, i, fileName, s) fp = fopen(fileName, "r"); \
									for (i = 0; fgets(s, MAXLENGTH, fp) != NULL; i++){ \
										; \
									} 
									
//floatDebug
#define DEBUG(y, x) if (debug == 1) \
                            { \
                                printf("%s %f\n", y, x);\
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
#define toLowercase(c) ((c >= 'A') && (c <= 'Z')) ? c + ('a' - 'A') : c; //if c >= 'A' && c <= 'Z', then add 'a' - 'A' to c; else leave it be

//toUppercase
#define toUppercase(c) if (c >= 'a' && c <= 'z') \
                            { \
                                c+= ('A' - 'a'); \
                            }
