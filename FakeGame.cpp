#include <iostream>
#include <windows.h>
#include <iostream>

class Player {
public:
    int health = 0;
    int ammo = 0;

    Player(int health, int ammo) {
        this->health = health;
        this->ammo = ammo;
    }

    void ReduceAmmo(int amount) {
        printf("Ammo reduced by %d\n\n", amount);
        this->ammo -= amount;
    }

    void TakeDamage(int amount) {
        printf("Health reduced by %d\n\n", amount);
        this->health -= amount;
    }

    void Heal() {
        printf("Healing\n\n");
        this->health += 10;
    }
};

static Player* localplayer = nullptr;

void Function1() {
    printf("Function 1 called\n\n");
}

void Function2(const char* arg) {
    printf("Function2 Called Arg: %s\n\n", arg);
}

int Function3(int a, int b) {
    printf("Function 3 called Adding %d and %d\n\n", a, b);
    return a + b;
}

int main()
{
    Player player = Player(10, 100);

    printf("Function 1: 0x%p\n", Function1);
    printf("Function 2: 0x%p\n", Function2);
    printf("Function 3: 0x%p\n\n", Function3);

    printf("ObjectPtr address: 0x%p\n", &player);
    printf("Heal: 0x%p\n", &Player::Heal);
    printf("TakeDamage: 0x%p\n", &Player::TakeDamage);
    printf("ReduceAmmo: 0x%p\n", &Player::ReduceAmmo);
    printf("Current Health: %d\n", player.health);
    printf("Current Ammo: %d\n\n", player.ammo);

    printf("F1 for Function1, F2 for function2, F3 for function3\n");
    printf("F4 to Heal Player, F5 to TakeDamage, F6 to ReduceAmmo, F7 to show current health and ammo\n");

    while (!GetAsyncKeyState(VK_F12)) {
        if (GetAsyncKeyState(VK_F1) & 1) {
            Function1();
        }
        if (GetAsyncKeyState(VK_F2) & 1) {
            Function2("SHEESH");
        }
        if (GetAsyncKeyState(VK_F3) & 1) {
            Function3(12, 13);
        }
        if (GetAsyncKeyState(VK_F4) & 1 ) {
            player.Heal();
        }
        if (GetAsyncKeyState(VK_F5) & 1) {
            player.TakeDamage(2);
        }
        if (GetAsyncKeyState(VK_F6) & 1) {
            player.ReduceAmmo(2);
        }
        if (GetAsyncKeyState(VK_F7) & 1) {
            printf("Current Health: %d\nCurrent Ammo: %d\n", player.health, player.ammo);
        }
    }
}