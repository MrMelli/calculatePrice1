#include <stdio.h>
#include "price_calculator.h"

int main() {
    // Exempel på användning:
    char product_id[] = "1234567890";
    float base_price = 100.0;
    char person_id[] = "6512311234";
    int day = 2;

    float result_price = calculatePrice(product_id, base_price, person_id, day);
    printf("Det justerade priset är: %.2f\n", result_price);

    return 0;
}
