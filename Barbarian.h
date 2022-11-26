#include "Structs.h"
#include "Hero.h"

class Barbarian : public Hero {

    public:
    Barbarian(VitalData data){
        _name = BARBARIAN_NAME;
        _vitalData = data;
    }

    void readSpellFromInput(SpellType spellType) {
        SpellData data;

        std::string currSpell;
        getline(std::cin, currSpell);
        std::istringstream istr(currSpell);
        
        if(spellType == SpellType::Weak){
            istr >> data.name;
            istr >> data.damage;
            _spells[WEAKER_SPELL] = data;
        }
        else if(spellType == SpellType::Strong){
            istr >> data.name;
            istr >> data.damage;
            istr >> data.manaCost;
            _spells[STRONGER_SPELL] = data;
        }
    }

    int castSpell() {
        if(_vitalData.currMana >= _spells[STRONGER_SPELL].manaCost){
            std::cout << _name << " casting " << _spells[STRONGER_SPELL].name
                      << " for " << _spells[STRONGER_SPELL].manaCost << " mana" << std::endl;
            _vitalData.currMana -= _spells[STRONGER_SPELL].manaCost;
            return _spells[STRONGER_SPELL].damage;
        }
        
        else {
            std::cout << _name << " casting " << _spells[WEAKER_SPELL].name
                      << " for " << _spells[WEAKER_SPELL].manaCost << " mana" << std::endl;
            return _spells[WEAKER_SPELL].damage;
        }
    }

    void takeDamage(int damage) {
        _blockCounter--;
        if(_blockCounter == 0){
            _vitalData.health -= (damage * BARBARIAN_DAMAGE_BLOCK_PERCENT) / 100;

            std::cout << _name << " took " << (damage * BARBARIAN_DAMAGE_BLOCK_PERCENT) / 100
                      << " damage and is left with " << _vitalData.health << " health" << std::endl;

            _blockCounter = BARBARIAN_PASSIVE_ABILITY_COUNTER;
        }
        else {
            _vitalData.health -= damage;
            std::cout << _name << " took " << damage
                      << " damage and is left with " << _vitalData.health << " health" << std::endl;
        }
    }

    void regenerate() {
        int regainedMana = 0;
        if(_vitalData.currMana + _vitalData.manaRegenRate > _vitalData.maxMana){
            regainedMana = _vitalData.maxMana - _vitalData.currMana;
            _vitalData.currMana += regainedMana;
        }
        else regainedMana = _vitalData.manaRegenRate, _vitalData.currMana += regainedMana;
        
        std::cout << _name << " regained " << regainedMana << " mana for up to "
                  << _vitalData.currMana << std::endl;
    }

    bool isDead() const {
        return _vitalData.health <= 0;
    }

    private:
        int _blockCounter = BARBARIAN_PASSIVE_ABILITY_COUNTER;
};