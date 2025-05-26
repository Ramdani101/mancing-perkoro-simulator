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
uniform_int_distribution<> high(60, 80), medium(30, 60), low(10, 30), codeRange(0,300);
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


//Lanjutkan untuk class Inventory nanti
/*
    class Inventory{
    private:
        Item items[300] = {Item("", 0, 0, 0, 0)};

    public:
        int hashFunction(Item items) const{
            return items.getItemCode() % 300;
        }
};
*/


int main(){
    cout << "Hello, World!" << endl;
    return 0;
}