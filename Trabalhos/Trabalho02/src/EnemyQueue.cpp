#include <random>
#include <iostream>

#include "../headers/EnemyQueue.h"
#include "../headers/Game.h"

void EnemyQueue::initQueue(int size) {
    std::random_device generator;
    std::uniform_int_distribution<int> available_enemies(1, 11);
    std::uniform_int_distribution<int> available_bosses(1, 5);

    for (int i = 1; i <= size; i++) {
        int enemy_id_draw = available_enemies(generator);
        Enemy* enemy = new Enemy(enemy_id_draw, i, 1, this->difficulty);

        this->enemies.push(enemy);
    }

    int boss_id_draw = available_bosses(generator);

    Enemy* boss = new Enemy(boss_id_draw, size + 1, 2, this->difficulty);
    this->enemies.push(boss);
}

EnemyQueue::EnemyQueue(int &difficulty): difficulty(difficulty) {
    int queue_size = 0;

    switch (this->difficulty) {
        case Difficulty::EASY:
            queue_size = 5;
            break;
        case Difficulty::MEDIUM:
            queue_size = 7;
            break;
        case Difficulty::HARD:
            queue_size = 9;
            break;
    }

    initQueue(queue_size);
}

EnemyQueue::~EnemyQueue() {

}

Enemy* EnemyQueue::pop() {
    if (this->enemies.empty()) {
        return nullptr;
    }
    Enemy* enemy = this->enemies.front();
    this->enemies.pop();
    return enemy;
}

bool EnemyQueue::isEmpty() const {
    return this->enemies.empty();
}

std::queue<Enemy*> EnemyQueue::getQueue() const {
    return this->enemies;
}

std::vector<Enemy*> EnemyQueue::getEnemies() const {
    std::vector<Enemy*> enemyList;
    std::queue<Enemy*> tempQueue = this->enemies;

    while (!tempQueue.empty()) {
        enemyList.push_back(tempQueue.front());
        tempQueue.pop();
    }

    return enemyList;
}
