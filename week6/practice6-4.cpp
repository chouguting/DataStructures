#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    char prefix[100];
    fgets(prefix, 100, stdin);
    strtok(prefix, "\r\n");
    char suffix[100];
    fgets(suffix, 100, stdin);
    strtok(suffix, "\r\n");

    int characterFrequency;
    cin >> characterFrequency;
    getchar();
    getchar();

    int wordFrequency;
    cin >> wordFrequency;
    getchar();
    getchar();

    char data[10000];
    fgets(data, 10000, stdin);
    strtok(data, "\r\n");
    int characterCount[26] = {};
    string dataStr(data);

    set<string> prefixes;
    set<string> suffixes;
    map<string, int> wordCount;
    set<string> wordSets;


    char *p;
    char punc[2] = " ";
    p = strtok(data, punc);
    while (p != NULL) {
        char *findSomething;
        findSomething = strstr(p, prefix);
        if (findSomething != NULL && findSomething == p) {
            string temp(p);
            prefixes.insert(temp);
        }
        findSomething = strstr(p, suffix);
        if (findSomething != NULL && findSomething == p + strlen(p) - strlen(suffix)) {
            string temp(p);
            suffixes.insert(temp);
        }
        for (int j = 0; j < strlen(p); j++) {
            characterCount[p[j] - 'a']++;
        }

        auto iter = wordCount.find(p);
        if (iter == wordCount.end()) {
            string temp(p);
            wordSets.insert(temp);
            wordCount[temp] = 1;
        } else {
            string temp(p);
            wordCount[temp]++;
        }
        p = strtok(NULL, punc);

    }

    printf("prefix of %s:\n", prefix);
    for (auto it = prefixes.begin(); it != prefixes.end(); ++it) {
        cout << *it << endl;
    }
    printf("suffix of %s:\n", suffix);
    for (auto it = suffixes.begin(); it != suffixes.end(); ++it) {
        cout << *it << endl;
    }

    printf("character frequency over %d:\n", characterFrequency);
    for (int i = 0; i < 26; i++) {
        if (characterCount[i] >= characterFrequency) {
            printf("%c,%d\n", 'a' + i, characterCount[i]);
        }
    }


    printf("word frequency over %d:\n", wordFrequency);
    for (auto it = wordSets.begin(); it != wordSets.end(); ++it) {
        string findStr = *it;
        auto iter = wordCount.find(findStr);
        if (iter->second >= wordFrequency) {
            cout << findStr << "," << iter->second << endl;
        }
    }
}