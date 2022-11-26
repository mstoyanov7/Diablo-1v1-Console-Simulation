#include <cstdlib>
#include <memory>
#include <vector>

#include "Hero.h"
#include "Structs.h"

class BattleField {

    public:
    void createHeroes();
    void createSpells();
    void startBattle();
    void printWinner(const std::unique_ptr<Hero> &hero);

    private:
    std::vector<std::unique_ptr<Hero>> _heroes;
};
