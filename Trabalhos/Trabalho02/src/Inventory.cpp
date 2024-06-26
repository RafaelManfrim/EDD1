#include "../headers/Inventory.h"

Inventory::Inventory(): head(nullptr) {}

Inventory::~Inventory() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Inventory::addItem(const std::string& name, int buff, int type, int duration) {
    Node* newNode = new Node(Item(name, buff, type, duration));
    newNode->next = head;
    head = newNode;
}

void Inventory::removeItem(const std::string& name) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->item.name != name) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return;

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
}

void Inventory::removeItemByIndex(int index) {
    Node* current = head;
    Node* previous = nullptr;
    int counter = 1;

    while (current != nullptr && counter != index) {
        previous = current;
        current = current->next;
        counter++;
    }

    if (current == nullptr) return;

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
}

void Inventory::displayInventory() const {
    Node* current = head;
    int counter = 1;
    while (current != nullptr) {
        std::cout << counter << " - Item: " << current->item.name << ", Bonus: " << current->item.buff << ", pode ser usado por mais " << current->item.duration << " lutas" << std::endl;
        current = current->next;
        counter++;
    }
}

bool Inventory::isEmpty() const {
    return head == nullptr;
}

std::string Inventory::getItemNameByType(int type) const {
    switch (type) {
        case ItemType::LIFE:
            return "Armuleto de Vida";
        case ItemType::ATTACK:
            return "Espada de Ataque";
        case ItemType::DEFENSE:
            return "Escudo de Defesa";
        case ItemType::LUCK:
            return "Anel de Sorte";
        default:
            return "Tipo inválido";
    }
}

Item Inventory::getItemByIndex(int index) const {
    if (index == 0) return Item("", 0, 0, 0);

    Node* current = head;
    int counter = 1;

    while (current != nullptr && counter != index) {
        current = current->next;
        counter++;
    }

    return current->item;
}

void Inventory::decrementDuration(int index) {
    Node* current = head;
    int counter = 1;

    while (current != nullptr && counter != index) {
        current = current->next;
        counter++;
    }

    if(current && current->item.duration > 1) {
        current->item.duration--;
    } else {
        removeItemByIndex(index);
    }
}