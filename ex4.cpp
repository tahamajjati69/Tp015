#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Pile {
private:
    vector<T> elements;

public:
    void empiler(const T& element) { elements.push_back(element); }

    T depiler() {
        if (elements.empty()) throw runtime_error("Pile vide");
        T val = elements.back();
        elements.pop_back();
        return val;
    }

    T sommet() const {
        if (elements.empty()) throw runtime_error("Pile vide");
        return elements.back();
    }

    bool estVide() const { return elements.empty(); }

    void inverser() {
        vector<T> tmp;
        while (!elements.empty()) {
            tmp.push_back(depiler());
        }
        elements = tmp;
    }
};

int main() {
    Pile<int> p1;
    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);
    p1.inverser();
    while (!p1.estVide()) cout << p1.depiler() << " ";
    cout << endl;

    Pile<string> p2;
    p2.empiler("A");
    p2.empiler("B");
    cout << p2.sommet() << endl;

    Pile<double> p3;
    p3.empiler(1.5);
    p3.empiler(3.7);
    cout << p3.depiler() << endl;

    return 0;
}
