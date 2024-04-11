#include<stdio.h>
void main(){

	//Each target value has exacly one solution
	
	int a[5] = {1,2,3,4,5};
	int key;

	printf("The Array Elements Are\n");
	for(int i = 0 ; i <5 ; i ++){
		
	printf("%d\t,",a[i]);}
			printf("\n");

	printf("Enter The Key Value\n");
	scanf("%d",&key);

	for(int i = 0 ; i < 5 ; i++){
		for(int j =1;j<5;j++){
		if(key==a[i]+a[j]){
			printf("Yes : a[%d] and a[%d]\n",i,j);}}}}
