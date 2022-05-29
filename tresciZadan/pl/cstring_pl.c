/**
 * Zaprojektuj strukture CString (jako pseudo klase).
 * Ma to byc wrapper na char*.
 * Musisz przyjmowac char* jako zmienne ze stosu (char str[] = "Ala ma kota")
 *      oraz jako stale ("Ala ma kota")
 *
 * Zaimplementuj wszystkie funkcje biorac pod uwage wszystkie restrykcje. Wszystkie funkcje dzialaja na strukturze CString
 * 1. Konstruktor (cstring_new) moze dzialac w dowolnym czasie
 * 2. Funkcja zwracajaca dlugosc char* zapisanego w strukturze CString musi dzialac w O(1)
 * 3. Funkcja zwracajaca jeden znak (z podanego indeksu, liczymy od 0) musi dzialac w O(1)
 * 4. Funkcja zmieniajaca jeden znak (z podanego indeksu, liczymy od 0) na nowy musi dzialac w O(1).
 * 5. Funkcja zwracajaca caly ciag znakow rowniez ma dzialac w czasie O(1).
 *      Mamy uniemożliwić zmianę znaków po pobraniu go (zmieniamy tylko za pomocą funkcji z punktu powyżej).
 *
 * Przetestuj w jakis sposob wszystkie funkcje.
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

typedef struct CString
{
    /* Wypelnij strukture */
} CString;

CString* cstring_new(const char* str);

/* Dopisz pozostale funkcje */

CString* cstring_new(const char* const str)
{
    /* Zaimplementuj konstruktor */
    return NULL;
}

int main(void)
{
    CString* cs = cstring_new("Ala ma kota");

    /* Dopisz pozostale funkcje i testy */

    return 0;
}
