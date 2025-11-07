#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class FileVideException : public runtime_error {
public:
    FileVideException() : runtime_error("Erreur : la file est vide, impossible de défiler.") {}
};

class File {
private:
    vector<int> elements;
    size_t capacite; 

public:
    File(size_t cap = 10) : capacite(cap) {}

    
    void enfiler(int valeur) {
        if (elements.size() >= capacite) {
            cout << "⚠️  La file est pleine !" << endl;
            return;
        }
        elements.push_back(valeur);
    }


    void defiler() {
        if (estVide()) throw FileVideException();
        elements.erase(elements.begin());
    }

  
    bool estVide() const { return elements.empty(); }


    bool estPleine() const { return elements.size() == capacite; }


    void afficher() const {
        if (estVide()) cout << "[vide]" << endl;
        else {
            for (int v : elements) cout << v << " ";
            cout << endl;
        }
    }
};

// --- Programme principal ---
int main() {
    File file(5); // file de taille max 5
    int choix, valeur;

    do {
        cout << "\n--- MENU FILE D'ATTENTE ---\n";
        cout << "1. Enfiler (ajouter)\n";
        cout << "2. Defiler (retirer)\n";
        cout << "3. Afficher la file\n";
        cout << "4. Quitter\n";
        cout << "Choix : ";
        cin >> choix;

        try {
            switch (choix) {
                case 1:
                    cout << "Entrer une valeur : ";
                    cin >> valeur;
                    file.enfiler(valeur);
                    break;
                case 2:
                    file.defiler();
                    cout << "✔️  Élément retiré avec succès.\n";
                    break;
                case 3:
                    cout << "Contenu de la file : ";
                    file.afficher();
                    break;
                case 4:
                    cout << "Fin du programme.\n";
                    break;
                default:
                    cout << "Choix invalide.\n";
            }
        }
        catch (const FileVideException& e) {
            cout << e.what() << endl;
        }

    } while (choix != 4);

    return 0;
}
