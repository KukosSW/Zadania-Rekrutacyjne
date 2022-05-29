#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void q1(void);
static void q2(void);
static void q3(void);
static void q4(void);
static void q5(void);
static void q6(int);
static void q8(void);
static size_t q9(const char*);
static void q10(void);

/* 1. Co się pokaże na ekranie. */
static void q1(void)
{
    printf("%s: ", __func__);

    int a = 0;

    if (a = 0) /* ((a = 0)) wtedy bez warna */
        printf("IF");
    else
        printf("ELSE");

    printf("\n");
}

/* 2. Co się pokaże na ekranie. */
static void q2(void)
{
    printf("%s: ", __func__);

    int* ptr = NULL;

    {
        int a = 10;
        ptr = &a;
    }

    printf("%d", *ptr); /* dangling pointer */

    printf("\n");
}

/* 3. Co się pokaże na ekranie */
static void q3(void)
{
    printf("%s: ", __func__);

    const char* str = "Welcome in Tieto"; // .rodata
    const int*  ptr = (int *)str;
    ptr += 2; // (char)ptr + sizeof(*ptr) * 2
    printf("%s", (char *)ptr);

    printf("\n");
}

/* 4. Jaka jest różnica pomiędzy: */
static void q4(void)
{
    struct S
    {
        int a;
        int b;
    };

    struct
    {
        int a;
        int b;
    } S; /* struktura anonimowa (bez imienia) */

    struct S s;
    // S s; /* nie ma typedefa, S to nazwa zmiennej */
}

/* 5. Czego nie mogę zrobić ze strukturą takiego typu: */
static void q5(void)
{
    struct S
    {
        int a;
        int b;
        int c;
        char d[]; /* FAM - Flexible Array Member */
        // char e[]; /* Forbidden, tylko 1 FAM na koncu */
    };

    // struct S s1; /* Forbidden, FAM bedzie puste */
    // struct S s2[100]; /* Forbidden, FAM nie dziala jako Tablica */
    // struct S2
    // {
    //     int a;
    //     struct S s; /* Forbidden, FAM jako podstruktura, tylko ptr dziala */
    // };
    // static struct S s3; /* Forbidden, FAM jako statyczna struktura */

    // struct S s0 = malloc(sizeof(struct S) + sizeof(d[0]) * 100);  /* OK */
}

/* 6. Jak to napisać lepiej? Podaj wady i zalety Twojego rozwiązania. */
static void q6(int n)
{
    int buffer[n]; /* VLA */
    memset(&buffer[0], 0, sizeof(buffer)); /* sizeof(buffer) OK, bedzie w runtime jak sizeof(buffer[0]) * n */

    /*
        WADY:
        1. Stack overflow
        2. Brak NULL gdy sie nie powiedzie
        3. Dla duzych rozmiarow bedzie sporo PageFault do Linuxa i bedzie wolniejsze niz sbrk w malloc
        4. Nie da sie zerowac jako = {0}

        ZALTEY:
        1. RAII - nie trzeba zwalniac
        2. Zajmie tyle pamieci ile potrzeba
        3. Zazwyczaj szybsze niz malloc

        PODSUMOWANIE:
        1. Dla bezpieczenstwa uzyc malloc i sprawdzac NULL
        2. Do optymalizacji gdy wiemy z jakiego zakresdu bedzie n, dorzucic assert / ifa + error na wartosc n i elegancko
     */
}

/* 7. Czy można w ten sposób zapisać deklarację funkcji i tablicy jako argument? */

/*
    TAK.
    int [restrict], int [const] == int * restrict, int * const

    OD C11 [static 1] --> mowi ze funkcja dziala gdy tablica ma >= 1 element
*/
// void foo(double a[restrict 3][5]);
// void foo2(double a[restrict static 3][5]);

/* 8. Czy wywołania funkcji foo są poprawne? */

static void copy(int n, int * restrict p, int * restrict q);
static void copy(int n, int * restrict p, int * restrict q)
{
    while (n-- > 0)
        *p++ = *q++;
}

static void q8(void)
{
    int tmp[100];
    // extern int tmp[100]; /* extern dla zmylki :) aby byla okazja dopytac co robi extern */
    copy(50, tmp + 50, tmp); // OK. tmp[0 .. 49], tmp[50 .. 99] to rozlaczne zbiory dla funkcji
    copy(50, tmp + 1, tmp); // NOK tmp[0 .. 49], tmp [1 .. 50] nachodza na siebie
}

/* 9. Czy poniższa funkcja spełnia KISS? */
static size_t q9(const char* const str)
{
    const char* ptr = str; // 1. Niektorzy mowia ze nie da sie zrobic przypisania bo str to const ptr

    while (*ptr++); /* 1. pusta petla | 2. Brak explicit == '\0'  | 3. Confused. *ptr czy ptr++ pierwsze? */

    return ptr - str - 1; // 1. Po co -1? | 2. odejmowanie ptr do ptrdiff_t a nie size_t wiec brak casta

    /* WERSJA Z KISS */
    // size_t len = 0;
    // while (str[len] != '\0')
    //     ++len;

    // return len;
}


/* 10. Wymień możliwe błędy wynikające z użycia tych makr. Czy potrafisz napisać to lepiej? Widzisz tutaj jakieś elementy bad style? */
#define MIN(a, b) a <= b ? a : b;

static void q10(void)
{
    /*
        MIN. Srednik nie pozwala na if, for, func
    */
//    if (MIN(2, 3) == 2) { }

    /*
        Kandydat poprawia na
        #define MIN(a, b) a <= b ? a : b

        Teraz brak nawiasow
    */
   #undef MIN
   #define MIN(a, b) a <= b ? a : b

   int c = MIN(2, 3) * 5; /* Wynik to  2 a nie 10, bo skleilo w 2 <= 3 ? 2 : (3 * 5) */

    /*
        Kandydat dodaje nawiasy

        #define MIN(a, b) ((a) <= (b) ? (a) : (b))

        Dalej pozwalamy na porownania roznych typow
     */

    #undef MIN
    #define MIN(a, b) ((a) <= (b) ? (a) : (b))

    int d = MIN((int){2}, (long){3});

    /*
        Aby to rozwiazac mozemy uzyc arytmetyki wskaznikow


        #define MIN(a, b) ((a + ((&a - &b) * 0)) <= (b) ? (a) : (b))
     */

    #undef MIN
    #define MIN(a, b) ((a + ((&a - &b) * 0)) <= (b) ? (a) : (b))
    // int e = MIN((int){2}, (long){3});

    /*
        Pozostaje nam blad z MIN(a++, b--) ale tego nie unikniemy jesli nie mamy GNU C i operatora typeof
    */
}

int main(void)
{

    q1();
    q2();
    q3();
    q4();
    q5();
    q6(100);
    q8();
    (void)q9("TEST");
    q10();


    return 0;
}
