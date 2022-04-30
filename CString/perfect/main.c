// Zaprojektuj CString. Ma być to tylko wrapper na char*.
// Pobranie długości ma być w czasie O(1)
// Pobranie dowolnego znaku ma być w czasie O(1)
// Zmiana dowolnego znaku ma być w czasie O(1)

// *** Pobranie całego ciągu znaków również ma być w czasie O(1). Ale mamy uniemożliwić zmianę znaków po pobraniu go. (zmieniamy tylko za pomocą funkcji z punktu powyżej)

// typedef struct CString
// {
// /* Wypełnij */


// } CString;

// CString* cstring_new(const char* str)
// {
//   /* Wypełnij */
// }

// /* Dopisz pozostałe funkcje które są Ci potrzebne */

#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct CString
{
    size_t len;
    char str[]; // FAM
} CString;

static CString* cstring_new(const char* str);
static void cstring_delete(CString* c);
static size_t cstring_get_len(const CString* c);
static char cstring_get_char(const CString* c, size_t index);
static void cstring_set_char(CString *c, size_t index, char new_c);
static const char* cstring_get_str(const CString* c);

static CString* cstring_new(const char* str)
{
    if (str == NULL)
        return NULL;

    const size_t len = strlen(str);
    CString* c = malloc(sizeof(*c) + (len + 1));
    if (c == NULL)
        return NULL;

    c->len = len;

    strncpy(c->str, str, len + 1);

    return c;
}

static void cstring_delete(CString* c)
{
    if (c == NULL)
        return;

    free(c);
}

static size_t cstring_get_len(const CString* c)
{
    if (c == NULL)
        return 0;

    return c->len;
}

static char cstring_get_char(const CString* c, size_t index)
{
    if (c == NULL)
        return '\0';

    if (index >= c->len)
        return '\0';

    return c->str[index];
}

static void cstring_set_char(CString *c, size_t index, char new_c)
{
    if (c == NULL)
        return;

    if (index >= c->len)
        return;

    c->str[index] = new_c;
}

static const char* cstring_get_str(const CString* c)
{
    if (c == NULL)
        return NULL;

    return c->str;
}

int main(void)
{
    // TDD
    const char* const str = "Ala ma kota"; // .rodata
    CString* c = cstring_new(str);
    assert(c != NULL);

    assert(cstring_get_len(c) == strlen(str));
    assert(strcmp(cstring_get_str(c), str) == 0);
    assert(cstring_get_char(c, 0) == 'A');

    cstring_set_char(c, 3, '_');
    assert(cstring_get_char(c, 3) == '_');

    cstring_delete(c);

    return 0;
}
