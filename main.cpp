#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdint>
#include <windows.h>
#include <vector>
#include <random>
using namespace std;

//untuk generate random numbers
random_device rd;  
mt19937 gen(rd()); 
uniform_int_distribution<> high(60, 80), medium(30, 60), low(10, 30), codeRange(0,100);
// Contoh implementasi -> high(gen)

struct boss{
    string name;
    double strength;
    double agility;
    double luck;
    boss *right = nullptr;
    boss *left = nullptr;
    boss(string n, double s, double a, double l) : name(n), strength(s), agility(a), luck(l), right(nullptr), left(nullptr) {}
};

struct regulerEnemy{
    string name;
    double strength;
    double agility;
    double luck;
};

class Item{
    //akan ada 5 jenis item
    private:
        string name;
        int price;
        int strengthEffect;
        int agilityEffect;
        int luckEffect;
        int itemCode;
    public:
        Item(string n, int p, int s, int a, int l) : name(n), price(p), strengthEffect(s), agilityEffect(a), luckEffect(l), itemCode(codeRange(gen)) {}
        string getName() const { return name; }
        int getPrice() const { return price; }
        int getStrengthEffect() const { return strengthEffect; }
        int getAgilityEffect() const { return agilityEffect; }
        int getLuckEffect() const { return luckEffect; }
        int getItemCode() const { return itemCode; }
};




class Inventory{
    //total inventory slot bisa 25
    private:
        Item items[25];

    public:
        int hashFunction(Item items) const{
            return items.getItemCode() % 25;
        }

        void addItem(const Item& item) {
            int index = hashFunction(item);
            // Cek apakah slot sudah terisi
            while (!items[index].getName().empty()) {
                index = (index + 1) % 25; // Linear probing
            }
            items[index] = item;
        }

        void removeItem(int itemCode) {
            int index = itemCode % 25;
            // Cek apakah item ada di slot tersebut
            while (!items[index].getName().empty()) {
                if (items[index].getItemCode() == itemCode) {
                    items[index] = Item("", 0, 0, 0, 0); // Menghapus item dengan mengosongkan slot
                    return;
                }
                index = (index + 1) % 25; // Linear probing
            }
        }

};



int main(){
    cout << "Hello, World!" << endl;
    return 0;
}