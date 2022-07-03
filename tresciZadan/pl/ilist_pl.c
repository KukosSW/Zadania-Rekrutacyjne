/**
 * Zaprojektuj strukture IList (jako pseudo klase).
 * IList przechowuje zbior intow jako linked lista (nieposortowana)
 *
 * 1. Napisz konstruktor swojej struktury IList (funkcja new), destruktor (funkcja delete) oraz wstawianie na koniec listy (push_back)
 *      Dla ulatwienia, zakladamy ze nie mozna nic usunac z IList.
 * 2. Dopisz odpowiednie gettery, jak pobieranie liczby elementow, sprawdzanie czy lista jest pusta oraz pobieranie elementu z danego indeksu
 * 3. Napisz kilka prostych testow. Mozesz do tego uzyc funkcji assert.
 * 4. Jak szybko dziala wstawianie do IListy? Podaj zlozonosc wstawiania, mozesz uzyc notacji duzego O

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

typedef struct INode
{
    int val;
    struct INode* next;
} INode;

typedef struct IList
{
    /* Wypelnij strukture */
} IList;

IList* ilist_new(void);
void ilist_delete(IList* il);
void ilist_push_back(IList* il, int val);

/* Dopisz pozostale funkcje */

IList* ilist_new(void)
{
    /* Zaimplementuj konstruktor */
    return NULL;
}

void ilist_delete(IList* const il)
{
   /* Zaimplementuj destruktor */
}

void ilist_push_back(IList* const il, const int val)
{
    /* Zaimplementuj dodawanie elementu na koniec */
}

int main(void)
{
    IList* il = ilist_new();

    /* Dopisz pozostale funkcje i testy */

    return 0;
}
