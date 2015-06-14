#include <stdio.h>
#include <stdlib.h>
struct ListStruct {
	unsigned int DataH;
	unsigned int DataL;
	unsigned int NextPtr;
}
struct ListStruct ListArray[1000];

struct Report{
	int FoundEntry;
	int PreEntry;
};
#define NULL 0xFFFF
#define ListHead 0

void initial_ListArray(struct ListStruct *Array){
	int index=0, value=0;
	if(Array->NextPtr != NULL){
		while(Array++ != NULL){
			Array->DataH = value;
			Array->DataL = value++;
			//Array->NextPtr = &(Array+1);
			Array->NextPtr = index++;
		}
	}
}

struct Report find_AB(unsigned int DATA_A, unsigned int DATA_B){
	struct Report result = malloc(sizeof(struct Report));
	while(ListArray++ != NULL){
		if(ListArray.DataH == DATA_A && ListArray.DataL == DATA_B){
			if((ListArray-1).NextPtr != NULL)
				result->FoundEntry = (ListArray-1).NextPtr;
				result->PreEntry =  (ListArray-2).NextPtr;
			else{//is head
				result->FoundEntry = 0;
				result->PreEntry = NULL;
			}
			return result;
		}
	}
	result->FoundEntry = NULL;
	result->PreEntry = NULL;
	return result;
}
void main(){
	struct Report res = malloc(sizeof(struct Report));
	initial_ListArray(ListArray);
	res = find_AB(50, 0);
	if(res.FoundEntry ==NULL && res.PreEntry == NULL){
		printf("not found\n");
	}else{
		printf("FoundEntry: %d PreEntry: %d\n", res.FoundEntry, res.PreEntry);
	}
	res = find_AB(560, 560);
	if(res.FoundEntry ==NULL && res.PreEntry == NULL){
		printf("not found\n");
	}else{
		printf("FoundEntry: %d PreEntry: %d\n", res.FoundEntry, res.PreEntry);
	}
}