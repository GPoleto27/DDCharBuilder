
#include "CharBuilder.h"

Character::Character(string name, Race charRace, Class charClass)
{
    int roll[4];
    vector<int> stats;
    int sum;

    this->name = name;
    this->charRace = charRace;
    this->charClass = charClass;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            roll[j] = 1 + rand() % 6;
        }
        sort(roll, roll + 4);
        sum = 0;
        for (int j = 3; j > 0; j--)
        {
            sum += roll[j];
        }
        stats.push_back(sum);
    }
    sort(stats.begin(), stats.end());
    switch (charClass)
    {
    case Barbarian:
        strength = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Bard:
        charisma = stats.back();
        stats.pop_back();
        dexterity = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        strength = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Cleric:
        wisdom = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        strength = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    case Druid:
        wisdom = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        strength = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    case Fighter:
        strength = stats.back();
        stats.pop_back();
        dexterity = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        constitution = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Monk:
        dexterity = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        strength = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    case Paladin:
        strength = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Ranger:
        dexterity = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        strength = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    case Rogue:
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        strength = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Sorcerer:
        charisma = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        strength = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        break;

    case Warlock:
        charisma = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        intelligence = stats.back();
        stats.pop_back();
        strength = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    case Wizard:
        intelligence = stats.back();
        stats.pop_back();
        wisdom = stats.back();
        stats.pop_back();

        shuffle(begin(stats), end(stats), default_random_engine{});
        dexterity = stats.back();
        stats.pop_back();
        strength = stats.back();
        stats.pop_back();
        charisma = stats.back();
        stats.pop_back();
        constitution = stats.back();
        stats.pop_back();

        break;

    default:
        break;
    }

    switch (charRace)
    {
    case Dragonborn:
        strength += 2;
        charisma += 2;
        break;

    case Dwarf:
        constitution += 2;
        break;

    case Elf:
        dexterity += 2;
        break;

    case Gnome:
        intelligence += 2;
        break;

    case HalfElf:
        int ab1, ab2;
abilitiesSelect:
        cout << "Choose 2 abilities to add +1:\n";
        cout << "1 - Strength\n2 - Constitution\n3 - Dexterity\n4 - Intelligence\n5 - Wisdom\n";
        cin >> ab1 >> ab2;
        if (ab1 == ab2)
        {
            cout << "The abilities must be different\n";
            goto abilitiesSelect;
        }
        if (ab1 <= 0 || ab1 > 5 || ab2 <= 0 || ab2 > 5)
        {
            cout << "You must select valid abilities\n";
            goto abilitiesSelect;
        }

        charisma += 2;
        switch (ab1)
        {
        case 1:
            strength += 1;
            break;

        case 2:
            constitution += 1;
            break;

        case 3:
            dexterity += 1;
            break;

        case 4:
            intelligence += 1;
            break;

        case 5:
            wisdom += 1;
            break;

        default:
            break;
        }

        switch (ab2)
        {
        case 1:
            strength += 1;
            break;

        case 2:
            constitution += 1;
            break;

        case 3:
            dexterity += 1;
            break;

        case 4:
            intelligence += 1;
            break;

        case 5:
            wisdom += 1;
            break;

        default:
            break;
        }

        break;

    case Halfling:
        dexterity += 2;
        charisma += 2;
        break;

    case HalfOrc:
        strength += 2;
        constitution += 1;
        break;

    case Human:
        strength += 1;
        constitution += 1;
        dexterity += 1;
        intelligence += 1;
        charisma += 1;
        wisdom += 1;
        break;

    case Tiefling:
        charisma += 2;
        intelligence += 1;
        break;

    default:
        break;
    }
}

void Character::showCharacter()
{
    cout << "Name: " << name << "\n";
    cout << "Race: ";
    switch (charRace)
    {
    case Dragonborn:
        cout << "Dragonborn";
        break;

    case Dwarf:
        cout << "Dwarf";
        break;

    case Elf:
        cout << "Elf";
        break;

    case Gnome:
        cout << "Gnome";
        break;

    case HalfElf:
        cout << "Half-Elf";
        break;

    case Halfling:
        cout << "Halfling";
        break;

    case HalfOrc:
        cout << "Half-Orc";
        break;

    case Human:
        cout << "Human";
        break;

    case Tiefling:
        cout << "Tiefling";
        break;
    }
    cout << "\n";
    cout << "Class: ";
    switch(charClass)
    {
    case Barbarian:
        cout << "Barbarian";
        break;

    case Bard:
        cout << "Bard";
        break;

    case Cleric:
        cout << "Cleric";
        break;

    case Druid:
        cout << "Druid";
        break;

    case Fighter:
        cout << "Fighter";
        break;

    case Monk:
        cout << "Monk";
        break;

    case Paladin:
        cout << "Paladin";
        break;

    case Ranger:
        cout << "Ranger";
        break;

    case Rogue:
        cout << "Rogue";
        break;

    case Sorcerer:
        cout << "Sorcerer";
        break;

    case Warlock:
        cout << "Warlock";
        break;

    case Wizard:
        cout << "Wizard";
        break;
    }
    cout << "\n\n";
    cout << "Stats:\n";
    cout << "Strength: " << strength << "\n";
    cout << "Constitution: " << constitution << "\n";
    cout << "Dexterity: " << dexterity << "\n";
    cout << "Intelligence: " << intelligence << "\n";
    cout << "Charisma: " << charisma << "\n";
    cout << "Wisdom: " << wisdom << "\n\n";
}
