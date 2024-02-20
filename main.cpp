#include<iostream>
#include<cstring>

using namespace std;

/*
 * 7.
 *
 * char *strtok(char *S, char *delim);
 *
 * delim = " .,?!";
 *
 * Ana are mere, pere sau gutui? Nu are nimic!
 *  t   t   t     t    t    t    t   t    t
 *
 *  delim = "+-=";
 *
 *  56+13=Nu stiu
 *  t  t  t   t
 *
 *  t = "Ana"; t = strtok(S, " .,?!")
 *  t = "are"; t = strtok(0, " .,?!")
 *
 * char *t
 *
 * OBS:
 * - Funcția strtok strică stringul parcurs punând 0-uri după fiecare cuvânt procesat
 * - Atunci când folosesc strtok nu știu câți delimitatori sunt între cuvinte deci nu mai pot reface, îl mai pot folosi eventual dacă păstrez o copie a lui
 * - Se recomandă folosirea acestei funcții doar atunci când nu mai avem nevoie de șirul inițial sau când știm exact structura lui pentru a-l putea reface (ex. Cuvinte despărțite printr-un singur spațiu)
 *
 *
 * Se citește un șir de caractere format din cuvinte despărțite printr-un singur spațiu. Să se afișeze șirul inițial în care cuvintele palindrom se înlocuiesc cu cuvântul palindrom. Înlocuirea se va face efectiv în memorie
 **/

bool isPal(char *t) {
    int dr = strlen(t) - 1;

    int st = 0;

    while (st < dr) {
        if (t[st] != t[dr]) {
            return false;
        }

        st++, dr--;
    }

    return true;
}

int main() {
    char S[100];

    cin.getline(S, 100);

    char delim[] = " ";

    char result[100];

    for (char *t = strtok(S, delim); t; t = strtok(nullptr, delim)) {
        if (isPal(t)) {
            strcat(result, "palindrom");
        } else {
            strcat(result, t);
        }

        strcat(result, " ");
    }

    result[strlen(result) - 1] = 0;

    strcpy(S, result);

    cout << S;

    return 0;
}