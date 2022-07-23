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
#include <limits.h>

typedef struct INode
{
    int val;
    struct INode* next;
} INode;

INode* inode_new(int val);
void inode_delete(INode* in);

typedef struct IList
{
    INode* head;
    INode* tail;

    size_t num_elems;
} IList;

IList* ilist_new(void);
void ilist_delete(IList* il);
void ilist_push_back(IList* il, int val);
size_t ilist_get_len(const IList* il);
bool ilist_is_empty(const IList* il);
int ilist_get_elem(const IList* const il, const size_t index);

/* Dopisz pozostale funkcje */

INode* inode_new(const int val)
{
    INode* const in = malloc(sizeof(*in));
    if (in == NULL)
        return NULL;

    in->next = NULL;
    in->val = val;

    return in;
}

void inode_delete(INode* const in)
{
    if (in == NULL)
        return;

    free(in);
}

IList* ilist_new(void)
{
    IList* const il = malloc(sizeof(*il));
    if (il == NULL)
        return NULL;

    il->head = NULL;
    il->tail = NULL;
    il->num_elems = 0;

    return il;
}

void ilist_delete(IList* const il)
{
    if (il == NULL)
        return;

    INode* cur = il->head;
    for (size_t i = 0; i < il->num_elems; ++i)
        if (cur == NULL)
        {
            free(il);
            return;
        }
        else
        {
            INode* const temp = cur->next;
            inode_delete(cur);
            cur = temp;
        }

    free(il);
}

void ilist_push_back(IList* const il, const int val)
{
    if (il == NULL)
        return;

    INode* const new_node = inode_new(val);
    if (new_node == NULL)
        return;

    // empty list
    if (il->head == NULL)
    {
        il->head = new_node;
        il->tail = new_node;
    }
    else // non empty
    {
        il->tail->next = new_node;
        il->tail = new_node;
    }

    ++il->num_elems;
}

size_t ilist_get_len(const IList* const il)
{
    if (il == NULL)
        return 0;

    return il->num_elems;
}

bool ilist_is_empty(const IList* const il)
{
    if (il == NULL)
        return true;

    return ilist_get_len(il) == 0;
}

int ilist_get_elem(const IList* const il, const size_t index)
{
    if (il == NULL || index >= ilist_get_len(il))
        return INT_MAX;

    const INode* cur = il->head;
    for (size_t i = 0; i < index; ++i)
        if (cur == NULL)
            return INT_MAX;
        else
            cur = cur->next;

    return cur->val;
}

int main(void)
{
    IList* il = ilist_new();
    assert(il != NULL);

    assert(ilist_get_len(NULL) == 0);
    assert(ilist_get_len(il) == 0);

    assert(ilist_is_empty(NULL) == true);
    assert(ilist_is_empty(il) == true);

    // tutaj za INT_MAX wpisac kod bledu z impl kandydata
    assert(ilist_get_elem(NULL, 0) == INT_MAX);
    assert(ilist_get_elem(il, 0) == INT_MAX);

    ilist_push_back(NULL, 12345);

    const size_t k = 10;
    for (size_t i = 0; i < k; ++i)
        ilist_push_back(il, (int)i + 1);

    assert(ilist_get_len(il) == k);
    assert(ilist_is_empty(il) == false);

    for (size_t i = 0; i < k; ++i)
        assert(ilist_get_elem(il, i) == (int)i + 1);

    ilist_delete(NULL);
    ilist_delete(il);

    return 0;
}
