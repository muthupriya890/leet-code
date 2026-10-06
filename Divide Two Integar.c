#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    int negative = (dividend < 0) ^ (divisor < 0);
    long long long_dividend = labs((long long)dividend);
    long long long_divisor = labs((long long)divisor);
    long long quotient = 0;
    while (long_dividend >= long_divisor) {
        long long temp_divisor = long_divisor;
        long long multiple = 1;
        while (long_dividend >= (temp_divisor << 1)) {
            temp_divisor <<= 1;
            multiple <<= 1;
        }
        long_dividend -= temp_divisor;
        quotient += multiple;
    }
    return negative ? -quotient : quotient;
}
