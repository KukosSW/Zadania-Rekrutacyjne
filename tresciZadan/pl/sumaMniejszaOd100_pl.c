/**
 * 1. Zaprojektuj i zaimplementuj funkcje get_combinations_le_100, ktora zlicza 2 elementowe kombinacje liczb
 *      takie ze ich suma jest <= od 100
 *
 *      Funkcja przyjmuje jako argument tablice liczb unsigned. Ich wartosci moga byc dowolne.
 *      Jako kombinacje liczb uznajemy dowolne 2 liczby z 2 roznych miejsc w tablicy,
 *      Pamietaj ze kombinacja to zbior nieuporzadkowany, zatem {a, b} i {b, a} to ta sama kombinacja
 *
 *      Przyklad:
 *      unsigned t[] = {0, 2, 0, 99};
 *
 *      mamy nastepujace kombinacje (0 i 0 to dwie rozne liczby, bo ich indeksy sa rozne)
 *
 *      0 + 2, t[0] + t[1]
 *      0 + 0, t[0] + t[2]
 *      0 + 99, t[0] + t[3]
 *      2 + 0, t[1] + t[2]
 *      0 + 99, t[2] + t[3]
 *
 *      Zatem wynik to 5.
 *
 * 2. Napisz testy jednostkowe
 *
 * 3. Wyznacz zlozonosc asymptotyczna swojego rozwiazania w notacji duze O.
 *
 * Pokaz swoj styl programowania, pochwal sie znajomoscia dobrych metodyk oraz ficzerow jezyka C.
 *      Zadbaj o to aby Twoj kod byl bezpieczny, czytelny i szybki (wez pod uwage aspekty algorytmiczne jak i ficzery nowych cpu)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

size_t get_combinations_le_100(const unsigned t[], size_t t_len);

size_t get_combinations_le_100(const unsigned t[const], const size_t t_len)
{
    /* Zaimplementuj funkcje */
    return 0;
}

int main(void)
{
    /* Przyklad */
    const size_t no_combinations = get_combinations_le_100((unsigned[]){0, 2, 0, 99}, 4); /* should be 5 */

    /* Dopisz testy */

    return 0;
}
