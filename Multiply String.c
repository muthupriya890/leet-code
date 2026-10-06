#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char *zero = (char *)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total_len = len1 + len2;

    
    int *res_arr = (int *)calloc(total_len, sizeof(int));

    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res_arr[i + j + 1];

            res_arr[i + j + 1] = sum % 10;   
            res_arr[i + j] += sum / 10;      
        }
    }
    char *result_str = (char *)malloc((total_len + 1) * sizeof(char));
    int str_idx = 0;
    int start_saving = 0;
    for (int i = 0; i < total_len; i++) {
        if (res_arr[i] != 0) {
            start_saving = 1; 
        }
        if (start_saving) {
            result_str[str_idx++] = res_arr[i] + '0';
        }
    }
    result_str[str_idx] = '\0'; 
    free(res_arr); 
    return result_str;
}
