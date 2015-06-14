/*
3. Declare a list structure
struct ListStruct {
	unsigned int DataH;
	unsigned int DataL;
	unsigned int NextPtr;
}
struct ListStruct ListArray[1000];
#define NULL 0xFFFF

a.	ListHead is the first entry index of the list, so that ‘ListArray[ListHead]’ is the first entry.
b.	Given an index ‘Entry1’, and its next index ‘Entry2’, Entry2 = ListArray[Entry1].NextPtr;
c.	If ‘Entry2’ equal to NULL, it means Entry1 is the last entry index.
Else the value of entry ((ListArray[Entry2].DataH<<16)+ListArray[Entry2].DataL) must bigger than the value ((ListArray[Entry1].DataH<<16)+ListArray[Entry1].DataL)

Question:
Now given 2 numbers DATA_A and DATA_B, please write a function to find if any entry index of the list (DATA_A == DataH) and (DATA_B == DataL).
Report the entry index match the 2 numbers as “FoundEntry” and it’s previous entry index “PreEntry” (ListArray[PreEntry].NextPtr = FoundEntry)

Ie. FoundEntry = ListHead, PreEntry = NULL
If no any enty matches, must report not found
*/

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