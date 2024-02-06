/*
Pointeri

 Un pointer este o variabilă care reține o adresă de memorie (adresa unei alte variabile)
 Obs: Adresele de memorie sunt numere în baza 16

 ex: A1B2, A1B3, A1B4, A1B5
       |
       5

 Declarație:
     <tip> *p, x;
     p ~ pointer (adresă)
     *p ~ Valoarea adresată la adresa p
     &x ~ adresa la care se memorează valoarea x

 Operații cu pointeri:

     1. Scăderea:
        p1 - p2 are ca rezultat un număr întreg care reprezintă numărul de locații de memorie care despart cele 2 adrese

     2. Incrementare / Decrementare:
        p++, p--, ++p, --p; (trecerea la adresa următoare / precedentă)

     3. Adunarea cu un număr întreg:
        p += x;
        x este int;

 Legătura dintre pointeri și vectori / matrice:
    int a[5]; - Alocare statică a memoriei

    Obs: Orice vector este un pointer constant

    valoarea: a[0] | a[1] | a[2] ...
    adresa:    a   | a+1  | a+2  ...

    a[i] este elementul la adresa a + i

    a[i] == (a + i) == (i + a) == i[a]

    Așa nu: a = b; - GRESIT

    Alocare dinamică:

        int *a;

        int *b;

        a = b;

        Acești pointeri dinamici necesită obligatoriu alocarea dinamică a memoriei (manual)

    int a[3][2];

    | a[0][0] | a[0][1] | a[1][0] | a[1][1] | a[2][0] | a[2][1] |

    a[i] == (a + i)

    a[i][j] = (*(a + i) + j)
*/