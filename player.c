#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
    int hp;
    int damage;
    char * name;
};

struct player random_player(char* name){
    struct player p;
    p.hp = rand() % 900 + 100;
    p.damage = rand() % 200 + 100;
    p.name = name;
    return p;
}

// Return HP if still living, 0 if dead
int attack(struct player * p, int damage){
    printf("Attacking %s for %d damage\n", p->name, damage);
    p->hp -= damage;
    if(p->hp <= 0){
        p->hp = 0;
    }
    return p->hp;
}

int player_attack(struct player * attacker, struct player * defender){
    return attack(defender, attacker->damage);
}

void print_player(struct player p){
    printf("Player %s: %d HP, Damage: %d\n", p.name, p.hp, p.damage);
}

int main(){
    srand(time(NULL));

    struct player p1 = random_player("Jared");
    struct player p2 = random_player("Mark");

    printf("Testing print functions\n");
    print_player(p1);
    print_player(p2);

    printf("\nTesting attack functions\n");
    attack(&p1, 1);
    printf("Expecting Jared to have 1 less HP...\n");
    print_player(p1);

    printf("\n");
    attack(&p1, 1000);
    printf("Expecting Jared to be dead :(\n");
    print_player(p1);

    printf("\n");
    attack(&p2, 100);
    printf("Expecting Mark to have 100 less HP...\n");
    print_player(p2);

    printf("\n");
    attack(&p2, 1000);
    printf("Expecting Mark to be dead :(\n");
    print_player(p2);

    printf("Mark and Jared have been brought back to life for a battle: \n");

    p1 = random_player("Jared");
    p2 = random_player("Mark");

    print_player(p1);
    print_player(p2);

    while(1){
        printf("--- New Turn ---\n");
        player_attack(&p1, &p2);
        if(!p2.hp){
            printf("%s has perished!\n", p2.name);
            break;
        }
        player_attack(&p2, &p1);
        if(!p1.hp){
            printf("%s has perished!\n", p1.name);
            break;
        }
        print_player(p1);
        print_player(p2);
    }


    return 0;
}
