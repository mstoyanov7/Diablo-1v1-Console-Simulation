# Diablo-1v1-Console-Simulation
Simple 1v1 console simulation

The game consists of 2 heroes. Barbarian with index 0 and Amazon with index 1.
Each hero has 3 attributes. Health, mana and manaRegenRate.

The heroes take turns attacking each other. First the Barbarian attacks the Amazon, then the Amazon
attacks the Barbarian, etc...

A simple turn consists of: one of the heroes' attacks, the other defends and after that the attacker
regains some mana (based on his/hers manaRegenRate).

The game is played until one of the heroes dies (his/hers health becomes 0 or below 0).

Each hero has 2 active spells (stronger and weaker) and a passive spell.
Active spell means somethig the hero acts (attacks) with.
Passive spell means a bonus that the hero can add to his/hers attacks or deffends.
The stronger active spell requires mana to be casted.
When the hero attacks, if he/she has enough mana for his stronger spell - he/she always casts that spell
and the required mana for the spell is subtracted from his/her mana pool.
If the hero doesn't have enough mana for his stronger spell - he/she uses the weaker spell.
The weaker spell requires no mana (can be casted for 0 mana).

Each spell has name, damage and cost.

Heroes' passive abilities:

Barbarian:
Each 3rd defend of the Barbarian results in the hero blocking half of the incoming damage.

Amazon:
Each 2nd attack of the Amazon has 25% increased damage.

Input:
The 1st and 2nd rows of data are representing the data for each Hero.
Health - MaxMana - ManaRegenRate

3rd and 4th rows of data are representing the Barbarian's spells.
3rd row (Weaker spell - name and damage).
4th row (Stronger spell - name, damage and mana cost).

5th and 6th rows of data are representing the Amazon's spells.
3rd row (Weaker spell - name and damage).
4th row (Stronger spell - name, damage and mana cost).

Sample input:
100 50 5 | 120 40 8 | Bash 24 | Whirlwind 44 30 | PowerStrike 28 | LightningArrow 60 20 
('|' means new line in console input)

Sample output:
===== Staring turn 1 =====
Barbarian casting Whirlwind for 30 mana
Amazon took 44 damage and is left with 76 
health 
Barbarian regained 5 mana for up to 25

===== Staring turn 2 =====
Amazon casting LightningArrow for 20 mana
Barbarian took 60 damage and is left with 
40 health
Amazon regained 8 mana for up to 28

===== Staring turn 3 =====
Barbarian casting Bash for 0 mana
Amazon took 24 damage and is left with 52 
health 
Barbarian regained 5 mana for up to 30

===== Staring turn 4 =====
Amazon casting LightningArrow for 20 mana
Barbarian took 75 damage and is left with -
35 health 
Amazon has won!


----------------------------------------------------------------------------------------------------------------------------------------------------
The damage of each of the heroes'spells must be devisible by 4 to avoid floating point numbers.
