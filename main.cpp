#include "CharBuilder.h"

void clearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

void mainMenu(vector<Character> chars)
{
    string name;
    Race charRace;
    Class charClass;
    int choice, a;
    cout << "D&D Character Builder\n\n";
    cout << "1 - Create a Character\n2 - View Characters\n0 - Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        clearScreen();
        cout << "Charater name: ";
        cin >> name;
        clearScreen();

    raceSelect:
        cout << "Charater race:\n0 - Dragonborn\n1 - Dwarf\n2 - Elf\n3 - Gnome\n4 - Half-Elf\n5 - Halfling\n6 - Half-Orc\n7 - Human\n8 - Tiefling\n";
        cin >> a;
        if (a < 0 || a > 8)
        {
            cout << "Select a valid option\n";
            goto raceSelect;
        }
        charRace = (Race)a;
        clearScreen();

    classSelect:
        cout << "Character class:\n0 - Barbarian\n1 - Bard\n2 - Cleric\n3 - Druid\n4 - Fighter\n5 - Monk\n6 - Paladin\n7 - Ranger\n8 - Rogue\n9 - Sorcerer\n10 - Warlock\n11 - Wizard\n";
        cin >> a;
        if (a < 0 || a > 11)
        {
            cout << "Select a valid option\n";
            goto classSelect;
        }
        charClass = (Class)a;

        break;

    case 2:
        clearScreen();
        for (int i = 0; i < chars.size(); i++)
            chars[i].showCharacter();
        break;

    case 0:
        exit(0);
        break;

    default:
        clearScreen();
        cout << "Select a valid option\n";
        break;
    }
    if (choice == 1)
    {
        clearScreen();
        Character newChar(name, charRace, charClass);
        chars.push_back(newChar);
        newChar.showCharacter();
        cout << "Character successfully created\n";
    }
    fflush(stdin);
    getchar();
    cout << "\nPress any button to continue\n";
    fflush(stdin);
    getchar();
    clearScreen();
    mainMenu(chars);
}

int main()
{
    vector<Character> chars;
    mainMenu(chars);
    return 0;
}
