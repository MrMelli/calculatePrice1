#include <stdio.h>
#include <check.h>
#include "price_calculator.h"

// Enhetsstester för calculatePrice
START_TEST(test_calculatePrice) {
    char product_id[] = "1234567890";
    float base_price = 100.0;
    char person_id[] = "6512311234";

    // Testa för en tisdag (förväntad rabatt: 5%)
    ck_assert_float_eq_tol(calculatePrice(product_id, base_price, person_id, 2), 95.0, 0.001);

    // Testa för över 50 år (förväntad rabatt: 1%)
    ck_assert_float_eq_tol(calculatePrice(product_id, base_price, "7001011234", 2), 99.0, 0.001);

   
}
END_TEST


int main(void) {
    Suite *s1 = suite_create("Price Calculator");
    TCase *tc1 = tcase_create("calculatePrice");
    tcase_add_test(tc1, test_calculatePrice);
    suite_add_tcase(s1, tc1);

    SRunner *sr = srunner_create(s1);
    srunner_run_all(sr, CK_NORMAL);

    int failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
