#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int char_map[256];
    memset(char_map, -1, sizeof(char_map));
    int max_length = 0;
    int left = 0;
    int len = strlen(s);
    for (int right = 0; right < len; right++) {
        unsigned char current_char = s[right];
        if (char_map[current_char] >= left) {
            left = char_map[current_char] + 1;
        }
        char_map[current_char] = right;
        max_length = MAX(max_length, right - left + 1);
    }
    return max_length;
}
