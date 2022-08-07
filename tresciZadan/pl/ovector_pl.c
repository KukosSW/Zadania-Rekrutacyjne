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

typedef struct OVector
{
    /* Wypelnij strukture */
} OVector;

OVector* ovector_new(size_t elem_size);
void ovector_delete(OVector* ov);
void ovector_insert(OVector* ov, const void* val);
void ovector_erase(OVector* ov, size_t index);

/* Dopisz pozostale funkcje */

OVector* ovector_new(const size_t elem_size)
{
    /* Zaimplementuj konstruktor */
    return NULL;
}

void ovector_delete(OVector* const ov)
{
   /* Zaimplementuj destruktor */
}

void ovector_insert(OVector* const ov, const void* const val)
{
    /* Zaimplementuj dodawanie elementu */
}

void ovector_erase(OVector* const ov, const size_t index)
{
    /* Zaimplementuj usuwanie elementu */
}

int main(void)
{
    OVector* ov = ovector_new(sizeof(int));

    /* Dopisz pozostale funkcje i testy */

    return 0;
}
