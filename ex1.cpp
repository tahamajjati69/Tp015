#include <iostream>
using namespace std;

class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int val) : valeur(val), suivant(nullptr) {}
};

class ListeChainee {
private:
    Noeud* tete;

public:
    ListeChainee() : tete(nullptr) {}

    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
    }

    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        if (!tete) {
            tete = nouveau;
            return;
        }
        Noeud* temp = tete;
        while (temp->suivant)
            temp = temp->suivant;
        temp->suivant = nouveau;
    }

    void supprimer(int valeur) {
        if (!tete) return;

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            return;
        }

        Noeud* courant = tete;
        while (courant->suivant && courant->suivant->valeur != valeur)
            courant = courant->suivant;

        if (courant->suivant) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            delete temp;
        }
    }

    void afficher() const {
        Noeud* temp = tete;
        while (temp) {
            cout << temp->valeur << " -> ";
            temp = temp->suivant;
        }
        cout << "NULL" << endl;
    }

    int taille() const {
        int count = 0;
        Noeud* temp = tete;
        while (temp) {
            count++;
            temp = temp->suivant;
        }
        return count;
    }

    ~ListeChainee() {
        while (tete) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
        }
    }

    class Iterator {
        Noeud* courant;
    public:
        Iterator(Noeud* n) : courant(n) {}
        bool operator!=(const Iterator& autre) const { return courant != autre.courant; }
        int operator*() const { return courant->valeur; }
        Iterator& operator++() { courant = courant->suivant; return *this; }
    };

    Iterator begin() const { return Iterator(tete); }
    Iterator end() const { return Iterator(nullptr); }
};

int main() {
    ListeChainee liste;

    liste.ajouterFin(10);
    liste.ajouterFin(20);
    liste.ajouterDebut(5);
    liste.ajouterFin(30);

    cout << "Liste initiale : ";
    liste.afficher();

    cout << "Taille : " << liste.taille() << endl;

    liste.supprimer(20);
    cout << "Après suppression de 20 : ";
    liste.afficher();

    cout << "Parcours avec itérateur : ";
    for (auto it = liste.begin(); it != liste.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
