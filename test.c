// Input your program here for testing.
#include <stdio.h>
#include <string.h>
#define MAX 100
#define PI 3.14

int main()
{
    /* ---------- KEYWORDS + IDENTIFIERS ---------- */

    int count = 123;
    float value = 12.5;
    char letter = 'A';
    double result = 10.25;

    const int hex = 0xFF;


    /* ---------- CHARACTER CONSTANTS ---------- */

    char newline = '\n';
    char tab = '\t';
    char backslash = '\\';
    char quote = '\'';
    char doublequote = '"';


    /* ---------- STRING ---------- */

    printf("Hello World");
    printf("Value = %d\n", count);


    /* ---------- ARITHMETIC OPERATORS ---------- */

    count = count + 10;
    count = count - 5;
    count = count * 2;
    count = count / 2;


    /* ---------- COMPOUND OPERATORS ---------- */

    count += 2;
    count -= 1;
    count *= 2;
    count /= 2;


    /* ---------- INCREMENT / DECREMENT ---------- */

    count++;
    count--;


    /* ---------- RELATIONAL OPERATORS ---------- */

    if(count == 123)
    {
        count = count != 0;
        count = count >= 10;
        count = count <= 200;
    }


    /* ---------- LOGICAL OPERATORS ---------- */

    count = count && 1;
    count = count || 0;


    /* ---------- SINGLE LINE COMMENT ---------- */

    // This comment should not appear as a token


    /* ---------- MULTI LINE COMMENT ---------- */

    /*
       This is a
       multi-line comment.
       It should not appear as tokens.
    */


    /* ---------- SPECIAL CHARACTERS ---------- */

    int array[3];

    array[0] = 10;
    array[1] = 20;
    array[2] = 30;


    /* ---------- VALID NUMBERS ---------- */

    int integer = 100;
    float decimal = 12.5;
    float leading_decimal = .5;
    float scientific1 = 1e10;
    float scientific2 = 1.5e3;
    float scientific3 = 2.5E-2;
    float scientific4 = 3.14e+5;


    /* ---------- MORE KEYWORDS ---------- */

    if(integer > 50)
    {
        return 0;
    }

    return 0;
}

    