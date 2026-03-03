package com.iti;

import com.iti.interfaces.Enemy;

public class EnemyFactory{
    public Enemy createEnemy(String enemy) throws Exception{
        try{
        if(enemy ==null){
            throw new Exception("Cannot Be null");
        }
        
        switch (enemy.toLowerCase()) {
            case "gorilla":
               return new Gorilla(); 
            case "zombie":
                return new Zombie();
            default:
                throw new Exception("No valid Enemy was Provided");
        }
        }catch(Exception e){
            e.printStackTrace();
            return null;
        }

    }
}
