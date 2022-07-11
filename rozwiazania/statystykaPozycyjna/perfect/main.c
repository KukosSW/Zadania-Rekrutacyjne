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

size_t partition_hoare(unsigned arr[], size_t left, size_t right);
unsigned quick_select(unsigned arr[], size_t left, size_t right, size_t kpos);

#define SWAP(a, b, type) \
    do { \
        const type temp = a; \
        a = b; \
        b = temp; \
    } while (0)


size_t partition_hoare(unsigned arr[const], const size_t left, const size_t right)
{
    unsigned pivot = arr[left]; /* can be random, right, middle, do not care now */

    ssize_t smaller_index = (ssize_t)left - 1;
    ssize_t greater_index = (ssize_t)right + 1;

    while (true)
    {
        do {
            ++smaller_index;
        } while (arr[smaller_index] < pivot);

        // while (arr[++smaller_index] < pivot);

        do {
            --greater_index;
        } while (arr[greater_index] > pivot);

        // while (arr[--greater_index] > pivot);

        if (smaller_index >= greater_index)
            break;

        SWAP(arr[smaller_index], arr[greater_index], unsigned);
    }


    return (size_t)greater_index;
}

unsigned quick_select(unsigned arr[const], const size_t left, const size_t right, const size_t kpos)
{
    if (left == right)
        return arr[left];

    size_t partition_right_index = partition_hoare(arr, left, right);

    if (partition_right_index < kpos)
        return quick_select(arr, partition_right_index + 1, right, kpos);

    return quick_select(arr, left, partition_right_index, kpos);
}

unsigned get_n_largest(const unsigned arr[const], const size_t len, const size_t n)
{
    if (arr == NULL || len == 0 || n == 0 || n > len)
        return 0;

    unsigned* arr_copy = malloc(sizeof(*arr_copy) * len);
    if (arr_copy == NULL)
        return 0;

    memcpy(arr_copy, arr, sizeof(*arr) * len);

    unsigned nmax = quick_select(arr_copy, 0, len - 1, len - n);
    free(arr_copy);

    return nmax;
}

int main(void)
{
    // Liczby sa dodatnie, wiec jako blad mozemy zwracac 0
    assert(get_n_largest(NULL, 5, 1) == 0);
    assert(get_n_largest((unsigned[]){1, 2, 3}, 3, 0) == 0);
    assert(get_n_largest((unsigned[]){1, 2, 3}, 3, 100) == 0);

    unsigned arr[] = {3, 6, 2, 8, 9, 1, 5, 7, 4};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);

    assert(get_n_largest(arr, arr_len, 1) == 9);
    assert(get_n_largest(arr, arr_len, 3) == 7);
    assert(get_n_largest(arr, arr_len, 5) == 5);
    assert(get_n_largest(arr, arr_len, 9) == 1);

    return 0;
}
