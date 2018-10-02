#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct player {
	int hp;
	char * name;
};

struct player random_player(char* name){
	struct player p;
	p.hp = rand() % 1000;
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

void print_player(struct player p){
	printf("Player %s: %d HP\n", p.name, p.hp);  
}

int main(){
	srand(time(NULL));

	struct player p1 = random_player("Jared");
	struct player p2 = random_player("Mark");

	print_player(p1);
	print_player(p2);

	attack(&p1, 1);
	printf("Expecting p1 to have 1 less HP...\n");
	print_player(p1);

	attack(&p1, 1000);
        printf("Expecting p1 to be dead...\n");
        print_player(p1);

	return 0;
}


