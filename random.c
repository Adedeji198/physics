#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int   getRandom(int min,int max);
void  seed();
void  resetRandomIndex(int Max);
int   getRandomIndex();
void  displayRandomIndex();
int   getRandomSign();

int   *RandomIndex, IndexSet = 0, IndexCount = 0;

void seed(){
	static int changer=0;
	long sd ;
	
	sd = (unsigned) time(&sd);
	srand(sd+(++changer));

}

int   getRandom(int min,int max){
	return min + (rand()*(max-min))/RAND_MAX;
}


void resetRandomIndex(int Max){
	int i;
	seed();

	if(IndexSet){
		free(RandomIndex);
	}

	
	RandomIndex = (int*) malloc(Max * sizeof(int));
	
	for(i=0; i<Max; i++){
		RandomIndex[i] = i;
	}

	IndexSet    = 1;
	IndexCount  = Max;
}

int getRandomIndex(){
	
	int index ,i,ret;
	
	index = getRandom(0,IndexCount);

	ret = RandomIndex[index];
	for(i=index; i<IndexCount-1; i++){
		RandomIndex[i] = RandomIndex[i+1];
	}

	IndexCount--;

	return ret;
}

void displayRandomIndex(){
	int i;
	
	printf("Random index array:\n");

	for(i=0; i< IndexCount; i++){
		printf("%d\n",RandomIndex[i]);
	}
}

int getRandomSign(){
	
	int Signs[] = {1,-1,1,-1,1,-1,1,-1,1,-1};
	
	getRandom(3,5);

	return Signs[getRandom(0,9)];
}