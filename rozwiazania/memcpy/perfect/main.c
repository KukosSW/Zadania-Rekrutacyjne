/**
 * 1. Zaimplementuj funkcje my_memcpy i my_memmove. Powinny dzialac tak samo jak oryginaly.
 *      Zobacz opisy tych funkcji z cpp-reference wstawione nizej w kodzie.
 *      O co chodzi z tym restrict? Co robi to slowo kluczowe w jezyku C.
 * 2. Napisz testy jednostkowe
 * 3. Wyznacz zlozonosc asymptotyczna swojego rozwiazania w notacji duze O.
 * 4. Zaproponuj jakas optymalizacje, ktora znaczaco przyspieszy kopiowanie. Zaimplementuj optymalizacje
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
#include <immintrin.h>

/*
    from: https://www.cplusplus.com/reference/cstring/memcpy/

    Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.
    The underlying type of the objects pointed to by both the source and destination pointers are irrelevant for this function.
    The result is a binary copy of the data.

    The function does not check for any terminating null character in source - it always copies exactly num bytes.

    To avoid overflows, the size of the arrays pointed to by both the destination and source parameters, shall be at least num bytes,
    and should not overlap (for overlapping memory blocks, memmove is a safer approach).
*/
void* my_memcpy(void* restrict dest, const void* restrict src, size_t bytes);

/*
    from: https://www.cplusplus.com/reference/cstring/memmove/

    Copies the values of num bytes from the location pointed by source to the memory block pointed by destination.
    Copying takes place as if an intermediate buffer were used, allowing the destination and source to overlap.

    The underlying type of the objects pointed by both the source and destination pointers are irrelevant for this function;
    The result is a binary copy of the data.

    The function does not check for any terminating null character in source - it always copies exactly num bytes.

    To avoid overflows, the size of the arrays pointed by both the destination and source parameters, shall be at least num bytes.
*/
void* my_memmove(void* dest, const void* src, size_t bytes);

void* my_memcpy(void* const restrict dest, const void* const restrict src, const size_t bytes)
{
    if (dest == NULL || src == NULL || bytes == 0)
        return dest;

    const size_t nr_of_u256_chunks = bytes / sizeof(__m256i);
    const size_t reminder_bytes = bytes % sizeof(__m256i);

    {
        __m256i* restrict dest_ptr = dest;
        const __m256i* restrict src_ptr = src;
        for (size_t i = 0; i < nr_of_u256_chunks; ++i)
            _mm256_storeu_si256(&dest_ptr[i], _mm256_loadu_si256(&src_ptr[i]));
    }

    /* Copy 0 - 31  bytes */
    {
        uint8_t * restrict dest_ptr = &(((uint8_t*)(dest))[bytes - reminder_bytes]);
        const uint8_t * restrict src_ptr = &(((const uint8_t*)(src))[bytes - reminder_bytes]);

        for (size_t i = 0; i < reminder_bytes; ++i)
            dest_ptr[i] = src_ptr[i];
    }

    return dest;
}

#define MIN(a, b) (((uintptr_t)(&(a) - &(b)) * 0 + a) < (b) ? (a) : (b))

void* my_memmove(void* const dest, const void* const src, const size_t bytes)
{
    if (dest == NULL || src == NULL || bytes == 0)
        return dest;

    enum { BUFFER_SIZE = 2048 };
    uint8_t buffer[BUFFER_SIZE] = {0};

    size_t bytes_to_copy = bytes;
    uint8_t *dest_ptr = dest;
    const uint8_t *src_ptr = src;

    while (bytes_to_copy > 0)
    {
        const size_t one_copy_bytes = MIN(bytes_to_copy, (size_t){BUFFER_SIZE});
        my_memcpy(&buffer[0], src_ptr, one_copy_bytes);
        my_memcpy(dest_ptr, &buffer[0], one_copy_bytes);

        dest_ptr += one_copy_bytes;
        src_ptr += one_copy_bytes;

        bytes_to_copy -= one_copy_bytes;
    }

    return dest;
}

int main(void)
{
    int t1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
    int t2[] = {34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    assert(my_memcpy(NULL, NULL, sizeof(t1)) == NULL);
    assert(my_memcpy(NULL, &t1[0], sizeof(t1)) == NULL);
    assert(my_memcpy(&t1[0], NULL, sizeof(t1)) == &t1[0]);

    assert(my_memcpy(&t2[0], &t1[0], sizeof(t1)) == &t2[0]);

    assert(memcmp(&t2[0], &t1[0], sizeof(t1)) == 0);
    assert(t2[34] == 0);

    int t3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
    int t4[] = {34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    assert(my_memmove(NULL, NULL, sizeof(t3)) == NULL);
    assert(my_memmove(NULL, &t3[0], sizeof(t3)) == NULL);
    assert(my_memmove(&t3[0], NULL, sizeof(t3)) == &t3[0]);

    assert(my_memmove(&t4[0], &t3[0], sizeof(t3)) == &t4[0]);

    assert(memcmp(&t4[0], &t3[0], sizeof(t3)) == 0);
    assert(t4[34] == 0);

    int t5[] = {2, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
    assert(my_memmove(&t3[0], &t3[1], 3 * sizeof(t3[0])) == &t3[0]);
    assert(memcmp(&t3[0], &t5[0], sizeof(t3)) == 0);

    return 0;
}
