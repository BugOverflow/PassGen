#include <stdbool.h>

char lowerCase [] = {'a' , 'b' , 'c' , 'd' , 'e' , 'f' ,
                    'g' , 'h' , 'i' , 'j' , 'k' ,
                    'l' , 'm', 'n' , 'o' , 'p' ,
                    'q' , 'r' , 's' , 't' , 'u' ,
                    'v' , 'w' , 'x' , 'y' , 'z'} ;
const unsigned short sizeLowerCase = 25;
bool enableLowerCase = false;

char upperCase [] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' ,
                    'G' , 'H' , 'I' , 'J' , 'K' ,
                    'L' , 'M', 'N', 'O', 'P',
                    'Q', 'R' , 'S' , 'T', 'U',
                    'V', 'W', 'X' , 'Y' , 'Z'} ;
const unsigned short sizeUpperCase = 25;
bool enableUpperCase = false;

char digits [] = {'0' , '1' , '2' , '3' , '4' ,
                    '5' , '6', '7' , '8' , '9'} ;
const unsigned short sizeDigits = 9;
bool enableDigits = false;

char symbols [] = {'"', '#' , '$' , '%', '&', 
					'(', '\'', ')', '*', '+',
 					',', '-', '.', '/', ':', 
					 ';', '<' , '=' , '>','?',
 					'@','[','\\',']','^','_',
 					'`','{','|','}','~'};
const unsigned short sizeSymbols = 30;
bool enableSymbols = false;
