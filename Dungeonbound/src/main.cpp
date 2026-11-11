
#include <iostream>
#include <string>
using namespace std;

// ==========================================
//              PARENT CLASS
// ==========================================

class Player
{
private:
    string name;
    string playerClass;
    int health;
    int attack;

public:

    // CONSTRUCTOR
    Player(string n, string c, int h, int a)
    {
        name = n;
        playerClass = c;
        health = h;
        attack = a;
    }

    // GETTERS
    string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getAttack()
    {
        return attack;
    }

    // SETTER
    void setHealth(int h)
    {
        if (h >= 0 && h <= 150)
        {
            health = h;
        }
    }

    // DISPLAY PLAYER
    void display()
    {
        cout << "\n========== PLAYER PROFILE ==========" << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << playerClass << endl;
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
    }

    // TAKE DAMAGE
    void takeDamage(int damage)
    {
        health -= damage;

        if (health <= 0)
        {
            health = 0;
            cout << name << " has been defeated!" << endl;
        }
        else
        {
            cout << name << " has "
                 << health << " health remaining." << endl;
        }
    }

    // HEAL PLAYER
    void healPlayer(int heal)
    {
        if (heal > 0 && health > 0)
        {
            health += heal;

            if (health > 150)
            {
                health = 150;
            }

            cout << name << " healed to "
                 << health << " health!" << endl;
        }
    }

    // VIRTUAL FUNCTION
    virtual void specialAttack()
    {
        cout << name << " performs a basic attack!" << endl;
    }

    // VIRTUAL DESTRUCTOR
    virtual ~Player() {}
};


// ==========================================
//              WARRIOR CLASS
// ==========================================

class Warrior : public Player
{
public:

    Warrior(string n, int h, int a)
        : Player(n, "Warrior", h, a)
    {
    }

    void specialAttack() override
    {
        cout << getName()
             << " performs a powerful sword strike!" << endl;
    }
};


// ==========================================
//                MAGE CLASS
// ==========================================

class Mage : public Player
{
private:
    int mana;

public:

    Mage(string n, int h, int a, int m)
        : Player(n, "Mage", h, a)
    {
        mana = m;
    }

    // MANA GETTER
    int getMana()
    {
        return mana;
    }

    // MANA SETTER
    void setMana(int m)
    {
        if (m >= 0 && m <= 100)
        {
            mana = m;
        }
    }

    void specialAttack() override
    {
        if (mana >= 20)
        {
            mana -= 20;

            cout << getName()
                 << " launches a magical fireball!" << endl;

            cout << "Mana remaining: " << mana << endl;
        }
        else
        {
            cout << "Not enough mana!" << endl;
        }
    }
};


// ==========================================
//             ADVENTURER CLASS
// ==========================================

class Adventurer : public Player
{
public:

    Adventurer(string n, int h, int a)
        : Player(n, "Adventurer", h, a)
    {
    }

    void specialAttack() override
    {
        cout << getName()
             << " performs a swift double strike!" << endl;
    }
};


// ==========================================
//                MAIN FUNCTION
// ==========================================

int main()
{
    // CREATE CHARACTERS

    Warrior Aries("Aries", 150, 40);

    Mage Aeloria("Aeloria", 70, 20, 100);

    Adventurer Leif("Leif", 100, 30);


    cout << "\n===================================" << endl;
    cout << "          DUNGEONBOUND" << endl;
    cout << "===================================" << endl;


    // DISPLAY CHARACTERS

    cout << "\n--- WARRIOR ---" << endl;
    Aries.display();

    cout << "\n--- MAGE ---" << endl;
    Aeloria.display();
    cout << "Mana: " << Aeloria.getMana() << endl;

    cout << "\n--- ADVENTURER ---" << endl;
    Leif.display();


    // SPECIAL ATTACKS

    cout << "\n===================================" << endl;
    cout << "          SPECIAL ATTACKS" << endl;
    cout << "===================================" << endl;

    Aries.specialAttack();
    Aeloria.specialAttack();
    Leif.specialAttack();


    // COMBAT TEST

    cout << "\n===================================" << endl;
    cout << "          COMBAT TEST" << endl;
    cout << "===================================" << endl;

    Aries.takeDamage(30);

    Aeloria.takeDamage(20);

    Leif.takeDamage(40);


    // HEALING TEST

    cout << "\n===================================" << endl;
    cout << "          HEALING TEST" << endl;
    cout << "===================================" << endl;

    Aries.healPlayer(20);


    // MANA TEST

    cout << "\n===================================" << endl;
    cout << "          MANA TEST" << endl;
    cout << "===================================" << endl;

    Aeloria.setMana(80);

    cout << "Aeloria's mana: "
         << Aeloria.getMana() << endl;


    return 0;
}
