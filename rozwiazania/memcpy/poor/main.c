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

    uint8_t * restrict dest_ptr = dest;
    const uint8_t * restrict src_ptr = src;

    for (size_t i = 0; i < bytes; ++i)
        dest_ptr[i] = src_ptr[i];

    return dest;
}

void* my_memmove(void* const dest, const void* const src, const size_t bytes)
{
    if (dest == NULL || src == NULL || bytes == 0)
        return dest;

    uint8_t *buffer = malloc(bytes);
    if (buffer == NULL)
        return NULL;

    my_memcpy(&buffer[0], src, bytes);
    my_memcpy(dest, &buffer[0], bytes);

    free(buffer);
    return dest;
}

int main(void)
{
    int t1[] = {1, 2, 3, 4, 5};
    int t2[] = {5, 4, 3, 2, 1, 0};

    assert(my_memcpy(NULL, NULL, sizeof(t1)) == NULL);
    assert(my_memcpy(NULL, &t1[0], sizeof(t1)) == NULL);
    assert(my_memcpy(&t1[0], NULL, sizeof(t1)) == &t1[0]);

    assert(my_memcpy(&t2[0], &t1[0], sizeof(t1)) == &t2[0]);

    assert(memcmp(&t2[0], &t1[0], sizeof(t1)) == 0);
    assert(t2[5] == 0);

    int t3[] = {1, 2, 3, 4, 5};
    int t4[] = {5, 4, 3, 2, 1, 0};

    assert(my_memmove(NULL, NULL, sizeof(t3)) == NULL);
    assert(my_memmove(NULL, &t3[0], sizeof(t3)) == NULL);
    assert(my_memmove(&t3[0], NULL, sizeof(t3)) == &t3[0]);

    assert(my_memmove(&t4[0], &t3[0], sizeof(t3)) == &t4[0]);

    assert(memcmp(&t4[0], &t3[0], sizeof(t3)) == 0);
    assert(t4[5] == 0);

    int t5[] = {2, 3, 4, 4, 5};
    assert(my_memmove(&t3[0], &t3[1], 3 * sizeof(t3[0])) == &t3[0]);
    assert(memcmp(&t3[0], &t5[0], sizeof(t3)) == 0);

    return 0;
}
