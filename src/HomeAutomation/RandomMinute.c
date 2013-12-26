#include "RandomMinute.h"

static int random_bound;

void RandomMinute_Create(int bound){
	random_bound = bound;
}
/*
int RandomMinute_Get(){

	return 20;
}*/

int RandomMinute_GetImpl(void){

	return random_bound - rand() % (random_bound * 2 + 1);

}

int (*RandomMinute_Get)(void) = RandomMinute_GetImpl;





