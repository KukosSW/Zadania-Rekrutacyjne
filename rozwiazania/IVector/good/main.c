/**
 * Zaprojektuj strukture IVector (jako pseudo klase).
 * IVector to struktura przechowujaca dynamiczna tablice integerow. Dziala podobnie do std::vector<int> z C++.
 *
 * Poczatkowo tablica wewnatrz IVectora ma rozmiar K (K dobierz sam), gdy tablica jest pelna, alokujemy wieksza tablice
 * (nowy rozmiar K' > K) i przepisujemy wszystkie K elementow do nowej tablicy. Uzytkownik nie moze widziec tej zmiany,
 * to znaczy on dziala na strukturze IVector i nie interesuje go jakie metadane przechowujesz w swojej strukturze.
 * Oznacza to, ze musisz zadbac o pelna hermetyzacje swojego kodu.
 *
 * 1. Napisz konstruktor swojej struktury IVector (funkcja new), destruktor (funkcja delete) oraz wstawianie do IVectora (funkcja insert).
 *      Dla ulatwienia, zakladamy ze nie mozna nic usunac z IVector. A wstawianie dziala jako dodawanie elementu na koniec.
 * 2. Dopisz odpowiednie gettery, jak pobieranie liczby elementow czy pobieranie elementu z danego indeksu
 * 3. Napisz kilka prostych testow. Mozesz do tego uzyc funkcji assert. Pokaz ze powiekszanie tablicy dziala.
 * 4. Jak szybko dziala IVector? Jaka jest zlozonosc obliczeniowa (asymptotycznie) dodawania kolejnego elementu?
 *      Mozesz uzyc do tego kosztu zamortyzowanego i policzyc ile zajmuje dodanie n elementow gdzie (n = (K'/ K) ^ P)
 * 5. Napisz konstruktor IVectora w taki sposob aby uzytkownik mogl podac liczby, ktore maja znajdowac sie w vectorze zaraz po jego stworzeniu
 *      np. IVector* iv = ivector_new_vals(5, 1, 2, 3, 4, 5) // tworzymy ivector i wstawiamy od razu 5 liczb {1, 2, 3, 4, 5}
 *      np. IVector* iv = ivector_new_vals(1, 2, 3, 4, 5) // trudniejsza wersja bo nie podajemy liczby elementow ale same elementy
 *      np. ... mozesz uzyc swojego wlasnego pomyslu na realizacje tego punktu, wazne aby uzytkownik nie musial tworzyc dodatkowych zmiennych np tablic

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
#include <limits.h>

#define K 4

typedef struct IVector
{
    int* arr;
    size_t num_elems;
    size_t memory_max_elems;
} IVector;

IVector* ivector_new_n(size_t n);

IVector* ivector_new(void);
void ivector_delete(IVector* iv);
void ivector_insert(IVector* iv, int val);
size_t ivector_get_len(const IVector* iv);
int ivector_get_elem(const IVector*  iv, size_t index);
IVector* ivector_new_vals(size_t n, ...);
IVector* ivector_new_vals_tab(const int arr[], size_t len);

/* Dopisz pozostale funkcje */

IVector* ivector_new_n(const size_t n)
{
    IVector* const iv = malloc(sizeof(*iv));
    if (iv == NULL)
        return NULL;

    iv->num_elems = 0;
    iv->memory_max_elems = K;

    iv->arr = malloc(sizeof(*(iv->arr)) * n);
    if (iv->arr == NULL)
    {
        free(iv);
        return NULL;
    }

    return iv;
}

IVector* ivector_new(void)
{
    return ivector_new_n(K);
}

IVector* ivector_new_vals(const size_t n, ...)
{
    IVector* const iv = ivector_new_n(n);
    if (iv == NULL)
        return NULL;

    va_list args;
    va_start(args, n);

    for (size_t i = 0; i < n; ++i)
        ivector_insert(iv, va_arg(args,int));

    va_end(args);

    return iv;
}

IVector* ivector_new_vals_tab(const int arr[const], const size_t len)
{
    if (arr == NULL)
        return NULL;

    IVector* const iv = ivector_new_n(len);
    if (iv == NULL)
        return NULL;

    for (size_t i = 0; i < len; ++i)
        ivector_insert(iv, arr[i]);

    return iv;
}

#define ivector_new_vals2(...) ivector_new_vals_tab((int[]){__VA_ARGS__}, sizeof((int[]){__VA_ARGS__}) / sizeof(int))

void ivector_delete(IVector* const iv)
{
    if (iv == NULL)
        return;

    free(iv->arr);
    free(iv);
}

/*

// 2 * N

4:
0. [_]
1. [A] // 1
2. [A, B] // 1 + 1
3. [A, B, C, _] // 2 + 1
4. [A, B, C, D] // 1

(7) = 2^(LOG(N) + 1) - 1

1 + 2 + 4 + 8 = 2^4 - 1 = 15 --> SUMA 2^i gdzie I od 0 do LOG(N)
1 | 10 | 100 | 1000 -> 1111


SUMA 2^i dla i = 0 do LOG(N) - 1 (koszt kopiowania) + N (koszt wstawiania)
2^(LOG(N)) - 1 + N = 2^LOG(N + 1) - 1


*/
void ivector_insert(IVector* const iv, const int val)
{
    if (iv == NULL)
        return;

    if (iv->num_elems >= iv->memory_max_elems)
    {
        iv->memory_max_elems *= 2;
        iv->arr = realloc(iv->arr, iv->memory_max_elems * sizeof(*(iv->arr)));

        // Nie wymagamy tego od Junior i Regular
        if (iv->arr == NULL)
        {
            perror("realloc returned null");
            return;
        }
    }

    iv->arr[iv->num_elems++] = val;
}

size_t ivector_get_len(const IVector* const iv)
{
    if (iv == NULL)
        return 0;

    return iv->num_elems;
}

int ivector_get_elem(const IVector* const iv, const size_t index)
{
    if (iv == NULL || index >= ivector_get_len(iv))
        return INT_MAX;

    return iv->arr[index];
}

int main(void)
{
    IVector* iv = ivector_new();
    assert(iv != NULL);

    assert(ivector_get_len(NULL) == 0);
    assert(ivector_get_len(iv) == 0);

    ivector_insert(NULL, 0);
    for (size_t i = 0; i < K + 1; ++i)
        ivector_insert(iv, (int)i);

    assert(ivector_get_len(iv) == K + 1);

    // tutaj za INT_MAX wpisac kod bledu z impl kandydata
    assert(ivector_get_elem(NULL, 0) == INT_MAX);
    assert(ivector_get_elem(iv, 2 * K) == INT_MAX);
    for (size_t i = 0; i < K + 1; ++i)
        assert(ivector_get_elem(iv, i) == (int)i);

    ivector_delete(NULL);
    ivector_delete(iv);

    const size_t iv_elems = 5;
    IVector* iv2 = ivector_new_vals(iv_elems,
                                    1, 2, 3, 4, 5);
    assert(iv2 != NULL);

    assert(ivector_get_len(iv2) == iv_elems);
    for (size_t i = 0; i < iv_elems; ++i)
        assert(ivector_get_elem(iv2, i) == (int)i + 1);

    ivector_delete(iv2);

    IVector* iv3 = ivector_new_vals2(1, 2, 3, 4, 5);
    assert(iv3 != NULL);

    assert(ivector_get_len(iv3) == iv_elems);
    for (size_t i = 0; i < iv_elems; ++i)
        assert(ivector_get_elem(iv3, i) == (int)i + 1);

    ivector_delete(iv3);

    return 0;
}
