#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int n1 = 65;  
    char c1 = (char)n1;  
    printf("Example 1 - Integer to Character:\n");
    printf("Integer %d as character: %c\n\n", n1, c1);

    char n2 = '5';  
    int c2 = n2 - '0';  
    printf("Example 2 - Character to Integer:\n");
    printf("Character %c as integer: %d\n\n", n2, c2);

    int n3 = 10;
    float c3 = (float)n3; 
    printf("Example 3 - Integer to Float:\n");
    printf("Integer %d as float: %.2f\n\n", n3, c3);

    char str[] = "12345";
    int n4 = atoi(str);  
    printf("Example 4 - String to Integer:\n");
    printf("String \"%s\" as integer: %d\n\n", str, n4);

   
    float celsius = 25.0;
    float fahrenheit = (celsius * 9/5) + 32;  
    printf("Example 5 - Celsius to Fahrenheit:\n");
    printf("%.2f Celsius is %.2f Fahrenheit\n\n", celsius, fahrenheit);

    int n5 = 7;
    double c5 = (double)n5;  
    printf("Example 6 - Integer to Double:\n");
    printf("Integer %d as double: %.2lf\n", n5, c5);

    return 0;
}

