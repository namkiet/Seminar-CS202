#include "BookCollection.h"
#include "ClothesCollection.h"
#include "ElectronicsCollection.h"
#include <iostream>

int main() {
    BookCollection books;
    ClothesCollection clothes;
    ElectronicsCollection electronics;

    std::cout << "--- Books ---\n";
    for (auto it = books.createIterator(); it->hasNext(); it->next())
        it->current().display();

    std::cout << "\n--- Clothes ---\n";
    for (auto it = clothes.createIterator(); it->hasNext(); it->next())
        it->current().display();

    std::cout << "\n--- Electronics ---\n";
    for (auto it = electronics.createIterator(); it->hasNext(); it->next())
        it->current().display();

    return 0;
}
