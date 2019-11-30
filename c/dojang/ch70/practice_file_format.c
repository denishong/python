#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	char c1,c2;
	int x,y;

	FILE *fp = fopen("position.txt", "r");

	fscanf(fp, "%c
