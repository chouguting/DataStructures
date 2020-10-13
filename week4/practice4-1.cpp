#include <iostream>
#include <cstring>
#include <regex>

using namespace std;

int main() {
    char *P = new char[1000];
    char *Q = new char[1000];
    char *R = new char[1000];

    fgets(P, 1000, stdin);
    strtok(P, "\r\n");
    string Pstr(P);

    fgets(Q, 1000, stdin);
    strtok(Q, "\r\n");
    string Qstr(Q);

    fgets(R, 1000, stdin);
    strtok(R, "\r\n");
    string Rstr(R);

    Pstr = std::regex_replace(Pstr, std::regex(Qstr), Rstr);

    cout << Pstr << endl;

}