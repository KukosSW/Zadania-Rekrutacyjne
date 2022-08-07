/**
 * Zaprojektuj strukture OVector (jako pseudo klase).
 * OVector to struktura przechowujaca dynamiczna tablice dowolnych obiektow.
 * Implementacja powinna dzialac tak, aby ten sam kod obslugiwal vector int, double, char* itd.
 * Podczas tworzenia uzytkownik podaje rozmiar elementu jaki bedzie przechowywany w vectorze, np sizeof(int)
 *
 * Poczatkowo tablica wewnatrz OVectora ma rozmiar K (K dobierz sam), gdy tablica jest pelna, alokujemy wieksza tablice
 * (nowy rozmiar K' > K) i przepisujemy wszystkie K elementow do nowej tablicy. Uzytkownik nie moze widziec tej zmiany,
 * to znaczy on dziala na strukturze OVector i nie interesuje go jakie metadane przechowujesz w swojej strukturze.
 * Oznacza to, ze musisz zadbac o pelna hermetyzacje swojego kodu.
 *
 * 1. Napisz konstruktor swojej struktury OVector (funkcja new), destruktor (funkcja delete), wstawianie do OVectora (funkcja insert)
 *      oraz funkcje usuwania (erase) z OVectora dowolnego elementu (elementu na indeksie idx)
 *      Dla ulatwienia, zakladamy ze wstawianie dziala jako dodawanie elementu na koniec.
 * 2. Dopisz odpowiednie gettery, jak pobieranie liczby elementow czy pobieranie elementu z danego indeksu
 * 3. Napisz kilka prostych testow. Mozesz do tego uzyc funkcji assert. Pokaz ze powiekszanie tablicy dziala.
 * 4. Jak szybko dziala OVector? Jaka jest zlozonosc obliczeniowa (asymptotycznie) dodawania kolejnego elementu?
 *      Mozesz uzyc do tego kosztu zamortyzowanego i policzyc ile zajmuje dodanie n elementow gdzie (n = (K'/ K) ^ P)
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
#include <stdarg.h>

#define K 4

typedef struct OVector
{
    uint8_t* arr;

    size_t elem_size;
    size_t memory_max_elems;
    size_t num_elems;

} OVector;

OVector* ovector_new(size_t elem_size);
void ovector_delete(OVector* ov);
void ovector_insert(OVector* restrict ov, const void* restrict val);
void ovector_erase(OVector* ov, size_t index);
size_t ovector_get_len(const OVector* ov);
int ovector_get_elem(const OVector* restrict ov, size_t index, void * restrict elem);

OVector* ovector_new(const size_t elem_size)
{
    if (elem_size == 0)
        return 0;

    OVector* const ov = calloc(1, sizeof(*ov));
    if (ov == NULL)
        return NULL;

    // *ov = (OVector)
    // {
    //     .elem_size = elem_size,
    //     .num_elems = 0,
    //     .memory_max_elems = K,
    //     .arr = malloc(K * elem_size),
    // };

    ov->elem_size = elem_size;
    ov->num_elems = 0;
    ov->memory_max_elems = K;

    ov->arr = malloc(ov->memory_max_elems * elem_size);
    if (ov->arr == NULL)
    {
        free(ov);
        return NULL;
    }

    return ov;
}

void ovector_delete(OVector* const ov)
{
    if (ov == NULL)
        return;

    free(ov->arr);
    free(ov);
}

void ovector_insert(OVector* const restrict ov, const void* const restrict val)
{
    if (ov == NULL || val == NULL)
        return;

    if (ov->num_elems >= ov->memory_max_elems)
    {
        ov->memory_max_elems *= 2;
        ov->arr = realloc(ov->arr, ov->memory_max_elems * ov->elem_size);
        if (ov->arr == NULL)
        {
            perror("realloc returned null");
            return;
        }
    }

    uint8_t* const ptr = &ov->arr[ov->num_elems * ov->elem_size];
    memcpy(ptr, val, ov->elem_size);

    ++ov->num_elems;
}

size_t ovector_get_len(const OVector* const ov)
{
    if (ov == NULL)
        return 0;

    return ov->num_elems;
}

int ovector_get_elem(const OVector* const restrict ov, size_t index, void * const restrict elem)
{
    if (ov == NULL || elem == NULL || index >= ovector_get_len(ov))
        return 1;

    const uint8_t* const ptr = &ov->arr[index * ov->elem_size];
    memcpy(elem, ptr, ov->elem_size);

    return 0;
}

void ovector_erase(OVector* const ov, const size_t index)
{
    if (ov == NULL || index >= ovector_get_len(ov))
        return;

    if (index != ovector_get_len(ov) - 1)
    {
        uint8_t* const ptr = &ov->arr[index * ov->elem_size];
        memmove(ptr, ptr + ov->elem_size, (ov->num_elems - index - 1) * ov->elem_size);
    }

    --ov->num_elems;
}

int main(void)
{
    OVector* ov = ovector_new(sizeof(int));
    assert(ov != NULL);

    assert(ovector_get_len(NULL) == 0);
    assert(ovector_get_len(ov) == 0);

    ovector_insert(NULL, 0);
    for (size_t i = 0; i < K + 1; ++i)
        ovector_insert(ov, &(int){(int)i});

    assert(ovector_get_len(ov) == K + 1);

    int ret_var = 0;
    assert(ovector_get_elem(NULL, 0, &ret_var) != 0);
    assert(ovector_get_elem(ov, 0, NULL) != 0);
    assert(ovector_get_elem(ov, 2 * K, &ret_var) != 0);

    for (size_t i = 0; i < K + 1; ++i)
    {
        assert(ovector_get_elem(ov, i, &ret_var) == 0);
        assert(ret_var == (int)i);
    }

    ovector_delete(NULL);
    ovector_delete(ov);

    const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int exp_arr[] = {1, 2, 3, 5, 6, 8, 9};
    const size_t arr_len = sizeof(arr) / sizeof(arr[0]);
    const size_t exp_arr_len = sizeof(exp_arr) / sizeof(exp_arr[0]);

    ov = ovector_new(sizeof(int));
    assert(ov != NULL);

    for (size_t i = 0; i < arr_len; ++i)
        ovector_insert(ov, &(int){arr[i]});

    ovector_erase(NULL, 0);
    ovector_erase(ov, arr_len);
    ovector_erase(ov, arr_len + 1);

    ovector_erase(ov, 4);
    ovector_erase(ov, 0);
    ovector_erase(ov, 5);
    ovector_erase(ov, 7);

    assert(ovector_get_len(ov) == exp_arr_len);

    for (size_t i = 0; i < exp_arr_len; ++i)
    {
        assert(ovector_get_elem(ov, i, &ret_var) == 0);
        assert(ret_var == exp_arr[i]);
    }

    ovector_delete(NULL);
    ovector_delete(ov);

    return 0;
}
