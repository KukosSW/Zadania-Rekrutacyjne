/**
 * 1. Zaprojektuj i zaimplementuj funkcje is_anagrams, ktora sprawdzi czy 2 podane ciagi znakow sa anagramami.
 *      Dla ulatwienia mozemy przyjac ze ciagi znakow skladaja sie tylko z malych liter alfabetu lacinskiego
 *
 *      Anagramy to slowa powstale poprzez przestawienie liter. Zatem skladaja sie z tych samych liter tylko w innej (lub tej samej) permutacji
 *          "ala" "laa" sa anagramami
 *          "ala" "all" juz nie sa, jest wiecej liter 'a' w "ala" niz w 'all'
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

bool is_anagrams(const char* const str1, const char* const str2);

bool is_anagrams(const char* const str1, const char* const str2)
{
    /* Zaimplementuj funkcje */
    return false;
}

int main(void)
{
    /* Przyklady uzycia */
    const bool b1 = is_anagrams("ala", "laa"); // should be true
    const bool b2 = is_anagrams("ala", "aal"); // should be true
    const bool b3 = is_anagrams("ala", "lla"); // should be false

    /* Dopisz testy  */

    return 0;
}
