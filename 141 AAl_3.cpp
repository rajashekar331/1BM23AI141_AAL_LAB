#include<stdio.h>
#include<string.h>

int main() {
    char str[] = "nobody_noticed_him"; 
    int length = strlen(str);
    char str1[] = "him"; 
    int length1 = strlen(str1);

    for (int i = 0; i < length - length1 + 1; i++) {
        int j = 0;
        while (j < length1 && str1[j] == str[i + j]) {
            j++;
        }
        if (j == length1) {
            printf("Match found at index %d\n", i);
            return 0; 
        }
    }
    printf("Match not found\n");
    return -1;
}

##output
Match found at index 16
