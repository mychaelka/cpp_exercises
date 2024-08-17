#include <string>
#include <cassert>


struct sword
{
    std::string name;

    int weight = 0; 
    int attack_damage = 0;
    int magic_damage = 0;
};


bool sword_is_heavy(const sword &s)
{
    return s.weight > 50;
}


struct shield
{
    std::string name;
    int weight = 0;
    int defense = 0;
};


class hero
{
    std::string _name;
    int _health;
    shield _shield;
    sword _sword;

public:

    bool wields_heavy_sword() const
    {
        return sword_is_heavy(_sword);
    }

    void wield(const sword &s)
    {
        _sword = s;
    }

    void get_shield(const shield &s) 
    {
        _shield = s;
    }


    hero(std::string name, int health)
        : _name(name), _health(health)
    {}
};


int main() 
{
    sword steel = {"Steel Sword", 10, 17, 0};
    sword silver = {"Silver Sword", 51, 10, 25};
    shield shield = {"Wooden Shield", 12, 36};
    hero protagonist("Geralt", 80);
    protagonist.wield(steel);
    protagonist.get_shield(shield);
    assert(!protagonist.wields_heavy_sword());
    protagonist.wield(silver);
    assert(protagonist.wields_heavy_sword());
}

