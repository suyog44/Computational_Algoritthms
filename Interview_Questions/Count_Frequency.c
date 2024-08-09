#include <stdio.h>
#include <stdlib.h>

int *sortedArrayList(int arrayCount, int *arrayList, int *resultArray){
	
	if(arrayCount<=0)
		return NULL;

	int i,j;
	int *uniqueEle = malloc(sizeof(int)*arrayCount);
	int *count = malloc(sizeof(int)*arrayCount);
	int uniqueCount = 0;

	for(i=0; i<arrayCount; i++){
		int num = arrayList[i];
		int matchFound = 0;
		printf("Processsing Num: %d\n", num);
		for(j=0; j<uniqueCount; j++){
			if(uniqueEle[j] == num){
				count[j]++;
				matchFound=1;
				printf("Found num: %d\n Count increment: %d\n", num, count[j]);
				break;
			}
		}
		if(!matchFound){
			uniqueEle[uniqueCount] = num;
			count[uniqueCount] = 1;
			printf("New number added: %d\n", num);
			uniqueCount++;
		}
	}

	printf("\n=========================================\n");
	printf("Before Sorting:\n");

	for(i=0;i<uniqueCount;i++)
		printf("Number %d Count %d\n", uniqueEle[i], count[i]);

	for(i=0;i<uniqueCount-1;i++){
		for(j=i+1;j<uniqueCount;j++){
			if(count[i]>count[j]){
				int tempCount = count[i];
				count[i]=count[j];
				count[j]=tempCount;

				int tempNum = uniqueEle[i];
				uniqueEle[i]=uniqueEle[j];
				uniqueEle[j]=tempNum;
			}
		}
	}

	printf("\n=========================================\n");
	printf("After Sorting:\n");

	for(i=0;i<uniqueCount;i++)
		printf("Number %d Count %d\n", uniqueEle[i], count[i]);

	int index = 0;
	for(i=0;i<uniqueCount;i++){
		for(j=0;j<count[i];j++){
			resultArray[index++]=uniqueEle[i];
		}
	}

	free(uniqueEle);
	free(count);	
	
	return resultArray;
}

void printArray(int count, int *arrayList)
{
	int i=0;
	while(count--)
		printf("%d ", arrayList[i++]);
}

int main(int argc, char **argv){
	int arrayList[]={1,2,1,2,2,3};
	printf("Array List: ");
	printArray(sizeof(arrayList)/sizeof(arrayList[0]), arrayList);
	int *output=malloc(sizeof(int)*(sizeof(arrayList)/sizeof(arrayList[0])));
	output = sortedArrayList(sizeof(arrayList)/sizeof(arrayList[0]), arrayList, output);
	printArray(sizeof(arrayList)/sizeof(arrayList[0]), output);
	return 0;
}
