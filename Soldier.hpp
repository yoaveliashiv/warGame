//
// Created by netanel & Or on 25/05/2020.
//

#ifndef WARGAME_SOLDIER_HPP
#define WARGAME_SOLDIER_HPP
#include <vector>
class Soldier{
public:
    int health;
    int damage;
    int num_player;
    int max;

public:
    Soldier(int h,int d,int num_p,int max):health(h),damage(d),num_player(num_p), max(max){}
    int get_health(){return health;}
    void set_health(int health){this->health=health;}
    int get_damage(){return damage;}
    int get_max(){return max;}
    int get_num_player(){return num_player;}
    virtual void Fight(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> dest)=0;

    virtual ~Soldier(){
    }
};





#endif //WARGAME_SOLDIER_HPP
