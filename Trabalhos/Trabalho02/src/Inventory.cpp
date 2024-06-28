#include "../headers/Inventory.h"

Inventory::Inventory(Util* util): head(nullptr), util(util) {}

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
        this->util->addTextToList(std::to_string(counter) + " - Item: " + current->item.name + ", Bonus: " + std::to_string(current->item.buff) + ", pode ser usado por mais " + std::to_string(current->item.duration) + " lutas");
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
            return "Amuleto de Vida";
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
    Node* current = head;
    int counter = 1;

    while (current != nullptr && counter != index) {
        current = current->next;
        counter++;
    }

    if (current == nullptr || index == 0 || index == -1) {
        return Item("", 0, 0, 0);
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

int Inventory::getSize() {
    Node* current = head;
    int counter = 0;

    while (current != nullptr) {
        current = current->next;
        counter++;
    }

    return counter;
}