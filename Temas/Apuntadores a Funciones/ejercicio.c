#include <stdio.h>
#include <stdlib.h>

void sort();
void swap();

int main(){


	
	return 0;
}

void sort(int a[], int n)
{
        int i, j;
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < i; j++)
                {
                        if (a[i] < a[j])
                        {
                                swap(i, j, a);
                        }
                }
        }
}

void swap(int i, int j, int a[]) { int temp = a[i]; a[i] = a[j]; a[j] = temp; }
