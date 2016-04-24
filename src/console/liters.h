#include <stdbool.h>

char lowerCase [] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' ,
                    'g' , 'h' , 'i' , 'j' , 'k' ,
                    'l' , 'm', 'n' , 'o' , 'p' ,
                    'q' , 'r' , 's' , 't' , 'u' ,
                    'v' , 'w' , 'x' , 'y' , 'z', '\0'} ;
const unsigned short sizeLowerCase = 26;
bool enableLowerCase = false;

char upperCase [] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' ,
                    'G' , 'H' , 'I' , 'J' , 'K' ,
                    'L' , 'M', 'N', 'O', 'P',
                    'Q', 'R' , 'S' , 'T', 'U',
                    'V', 'W', 'X' , 'Y' , 'Z', '\0'} ;
const unsigned short sizeUpperCase = 26;
bool enableUpperCase = false;

char digits [] = {'0' , '1' , '2' , '3' , '4' ,
                    '5' , '6', '7' , '8' , '9', '\0'} ;
const unsigned short sizeDigits = 10;
bool enableDigits = false;

char symbols [] = {'"', '#' , '$' , '%', '&', 
					'(', '\'', ')', '*', '+',
 					',', '-', '.', '/', ':', 
					 ';', '<' , '\\' , '=' , '>','?',
 					'@','[',']','^','_',
 					'`','{','|','}','~', '\0'};
const unsigned short sizeSymbols = 31;
bool enableSymbols = false;
