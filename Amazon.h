#include "Structs.h"
#include "Hero.h"

class Amazon : public Hero {

    public:
    Amazon(VitalData data) {
        _name = AMAZON_NAME;
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
        _attackCounter--;
        if(_vitalData.currMana >= _spells[STRONGER_SPELL].manaCost){
            std::cout << _name << " casting " << _spells[STRONGER_SPELL].name
                      << " for " << _spells[STRONGER_SPELL].manaCost << " mana" << std::endl;
            _vitalData.currMana -= _spells[STRONGER_SPELL].manaCost;
            if(_attackCounter == 0){
                _attackCounter = AMAZON_PASSIVE_ABILITY_COUNTER;
                return _spells[STRONGER_SPELL].damage * ((100 + AMAZON_DAMAGE_INCREASE_PERCENT) / 100.0);
            } 
            else return _spells[STRONGER_SPELL].damage;
        }
        else {
            std::cout << _name << " casting " << _spells[WEAKER_SPELL].name
                      << " for " << _spells[WEAKER_SPELL].manaCost << " mana" << std::endl;
            _vitalData.currMana -= _spells[WEAKER_SPELL].manaCost;
            if(_attackCounter == 0){
                _attackCounter = AMAZON_PASSIVE_ABILITY_COUNTER;
                return _spells[WEAKER_SPELL].damage * ((100 + AMAZON_DAMAGE_INCREASE_PERCENT) / 100.0);
            } 
            else return _spells[WEAKER_SPELL].damage;
        }
    }

    void takeDamage(int damage) {
        _vitalData.health -= damage;
        std::cout << _name << " took " << damage << " damage and is left with "
                  << _vitalData.health << " health" << std::endl;
    }

    void regenerate() {
        if(_vitalData.currMana + _vitalData.manaRegenRate > _vitalData.maxMana){
            std::cout << _name << " regained " << _vitalData.maxMana - _vitalData.currMana 
                      << " mana for up to " << _vitalData.currMana << std::endl;
            _vitalData.currMana = _vitalData.maxMana;
        }
        else {
            std::cout << _name << " regained " << _vitalData.manaRegenRate 
                      << " mana for up to " << _vitalData.currMana + _vitalData.manaRegenRate << std::endl;
            _vitalData.currMana += _vitalData.manaRegenRate;
        }
    }

    bool isDead() const {
        return _vitalData.health <= 0;
    }

    private:
        int _attackCounter = AMAZON_PASSIVE_ABILITY_COUNTER;
};