#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class TableHachage {
private:
    vector<list<pair<int, string>>> table;
    size_t taille;

    size_t hachage(int cle) const {
        return cle % taille;
    }

public:
    TableHachage(size_t t = 10) : taille(t), table(t) {}

    void inserer(int cle, const string& valeur) {
        size_t index = hachage(cle);
        for (auto& p : table[index])
            if (p.first == cle) { p.second = valeur; return; }
        table[index].push_back({cle, valeur});
    }

    string rechercher(int cle) const {
        size_t index = hachage(cle);
        for (auto& p : table[index])
            if (p.first == cle) return p.second;
        return "Non trouvé";
    }

    void supprimer(int cle) {
        size_t index = hachage(cle);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
            if (it->first == cle) { table[index].erase(it); return; }
    }

    void afficher() const {
        for (size_t i = 0; i < taille; ++i) {
            cout << i << ": ";
            for (auto& p : table[i]) cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
        }
    }
};

int main() {
    TableHachage th(5);
    th.inserer(1, "A");
    th.inserer(6, "B");
    th.inserer(11, "C");
    th.afficher();
    cout << th.rechercher(6) << endl;
    th.supprimer(6);
    th.afficher();
    return 0;
}
