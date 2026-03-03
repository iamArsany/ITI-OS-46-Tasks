package com.iti;

import com.iti.interfaces.Enemy;

public class Gorilla implements Enemy{
    @Override
    public void attack() {
        System.out.println("Attacking from Gorilla!");
    }
}
