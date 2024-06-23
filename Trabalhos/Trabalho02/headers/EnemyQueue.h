#pragma once

#include <queue>

#include <SFML/Graphics.hpp>

#include "./Enemy.h"

class EnemyQueue {
public:
    EnemyQueue(int &difficulty);
    virtual ~EnemyQueue();

    Enemy* pop();
    bool isEmpty() const;
    std::queue<Enemy*> getQueue() const;
    std::vector<Enemy*> getEnemies() const;

protected:

private:
    int difficulty;

    void initQueue(int size);

    std::queue<Enemy*> enemies;
};