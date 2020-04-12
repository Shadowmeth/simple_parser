#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* parser for grammar:
 * <non-zero-digit>         ::= 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
 * <letter>                 ::= A | B | C | x | y | z
 * <group>                  ::= <letter> | <letter><group>
 * <variable-identifier>    ::= <non-zero-digit><group>
*/

char input[1000];
int i = 0;

bool non_zero_digit()
{
    if (input[i] >= '1' && input[i] <= '9') {
        i++;
        return true;
    } else {
        return false;
    }
}

bool letter()
{
    if ((input[i] >= 'A'  && input[i] <= 'C') || (input[i] >= 'x' && input[i] <= 'z')) {
        i++;
        return true;
    } else {
        return false;
    }
}

bool rest()
{
    
}

bool group()
{
    if (!letter()) {
        return false;
    }
        
    return rest();
}

void variable_identifier()
{
    if (!non_zero_digit()) {
        printf("Syntax error: Expected 1-9, found %c\n", input[i]);
        exit(1);
    }

    if (!group()) {
        printf("Syntax error: Expected A-C or x-z, found %c\n", input[i]);
        exit(1);
    }
}

int main()
{
    fgets(input, 2000, stdin);
    input[strlen(input) - 1] = 0;
    variable_identifier();


    return 0;
}
