#include <stdlib.h>
#include <string.h>
typedef struct {
    int value;
    const char *symbol;
} RomanMapping;

char* intToRoman(int num) {
    RomanMapping mapping[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    char *result = (char *)malloc(16 * sizeof(char));
    result[0] = '\0'; 
for (int i = 0; i < 13; i++) {
        while (num >= mapping[i].value) {
            strcat(result, mapping[i].symbol); 
            num -= mapping[i].value;           
        }
        if (num == 0) {
            break;
        }
    }
return result;
}
