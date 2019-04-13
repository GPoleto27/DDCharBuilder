#ifndef CHAR_BUILDER_H
#define CHAR_BUILDER_H
#include <bits/stdc++.h>

using namespace std;

enum Race
{
    Dragonborn = 0,
    Dwarf,
    Elf,
    Gnome,
    HalfElf,
    Halfling,
    HalfOrc,
    Human,
    Tiefling
};

enum Class
{
    Barbarian = 0,
    Bard,
    Cleric,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Rogue,
    Sorcerer,
    Warlock,
    Wizard
};

class Character
{
public:
    Character(string name, Race charRace, Class charClass);
    void showCharacter();

private:
    string name;

    Race charRace;
    Class charClass;

    int strength;
    int constitution;
    int dexterity;
    int intelligence;
    int charisma;
    int wisdom;
};

#endif // CHAR_BUILDER_H
