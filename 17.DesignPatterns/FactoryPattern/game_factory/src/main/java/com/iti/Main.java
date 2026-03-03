package com.iti;

import com.iti.interfaces.Enemy;

public class Main {
    void main(String[] args) {
        try {
        EnemyFactory enemy=new EnemyFactory();
            Enemy myEnemy=enemy.createEnemy("zombiE");
            myEnemy.attack();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}