/**
 * 1. Zaprojektuj i zaimplementuj funkcje get_n_largest, ktora znajdzie i zwroci nta najwieksza liczbe w tablicy
        (liczymy od 1, czyli max w tablicy to 1 najwieksza)
 *      Dla ulatwienia mozemy przyjac ze tablica skladac sie bedzie tylko z liczb dodatnich, ktore nie moga sie powtarzac
 *
 * 2. Napisz testy jednostkowe
 *
 * 3. Wyznacz zlozonosc asymptotyczna swojego rozwiazania w notacji duze O.
 *
 * Pokaz swoj styl programowania, pochwal sie znajomoscia dobrych metodyk oraz ficzerow jezyka C.
 *      Zadbaj o to aby Twoj kod byl bezpieczny, czytelny i szybki (wez pod uwage aspekty algorytmiczne jak i ficzery nowych cpu)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

unsigned get_n_largest(const unsigned arr[], size_t len, size_t n);

unsigned get_n_largest(const unsigned arr[const], const size_t len, const size_t n)
{
    /* Zaimplementuj funkcje */
    return 0;
}

int main(void)
{
    /* Przyklady */
    const unsigned arr[] = {3, 6, 2, 8, 9, 1, 5, 7, 4};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    assert(get_n_largest(arr, arr_len, 1) == 9);
    assert(get_n_largest(arr, arr_len, 3) == 7);
    assert(get_n_largest(arr, arr_len, 5) == 5);
    assert(get_n_largest(arr, arr_len, 9) == 1);

    /* Dopisz testy  */

    return 0;
}
