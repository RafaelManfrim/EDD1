#pragma once

#include <iostream>

#include "Util.h"

enum ItemType {
    LIFE = 1,
    ATTACK = 2,
    DEFENSE = 3,
    LUCK = 4
};

struct Item {
    std::string name;
    int buff;
    int type;
    int duration;

    Item(const std::string& name, int buff, int type, int duration): name(name), buff(buff), type(type), duration(duration) {}
};

class Node {
public:
    Item item;
    Node* next;

    Node(const Item& item): item(item), next(nullptr) {}
};

class Inventory {
public:
    Inventory(Util* util);
    ~Inventory();

    Util* util;
    Item getItemByIndex(int index) const;

    void addItem(const std::string& name, int buff, int type, int duration);
    void removeItem(const std::string& name);
    void removeItemByIndex(int index);
    void displayInventory() const;
    bool isEmpty() const;
    void decrementDuration(int index);
    int getSize();

    std::string getItemNameByType(int type) const;

private:
    Node* head;
};

