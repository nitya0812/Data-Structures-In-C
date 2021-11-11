#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int[], int);
void selection(int[], int);
void insertionSort(int[], int);
void deepcopy(int[], int[], int);

int main()
{
    int count = 0;
    int choice = 0, ch = 0;
    int check = 0;
    int i = 0;

    printf("Enter the size of the list: ");
    scanf("%d", &count);

    int list[10000];
    int tlist[10000];

    for (i = 0; i < count; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &list[i]);
    }

    printf("\nNumbers entered: ");
    for (i = 0; i < count; i++)
        printf("%d,", list[i]);
    printf("\n");

    deepcopy(list, tlist, count);

    do {
        printf("Menu:\n\n");
        printf("1.Bubble sort\n2.Selection Sort\n3.Insertion sort\n4.Exit\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubble_sort(list, count);
            deepcopy(tlist, list, count);
            break;

        case 2:
            selection(list, count);
            deepcopy(tlist, list, count);

            break;

        case 3:
            insertionSort(list, count);
            deepcopy(tlist, list, count);
            break;

        case 4: return 0;

        default: printf("Invalid option\nRetry: ");
            break;


        }
        printf("Do you want to continue? (press 1 to continue any other number to exit): ");
        scanf("%d", &ch);
    } while (ch == 1);


    return 0;
}

void bubble_sort(int iarr[], int num) {
    int i, j, k, temp;

    printf("\nUnsorted Data:");
    for (k = 0; k < num; k++) {
        printf("%5d", iarr[k]);
    }

    for (i = 1; i < num; i++) {
        for (j = 0; j < num - 1; j++) {
            if (iarr[j] > iarr[j + 1]) {
                temp = iarr[j];
                iarr[j] = iarr[j + 1];
                iarr[j + 1] = temp;
            }
        }

        printf("\nAfter pass %d : ", i);
        for (k = 0; k < num; k++) {
            printf("%5d", iarr[k]);
        }
    }
    printf("\n");
}

void selection(int array[], int n)
{
    int j, k, temp, count = 0, position, swap = 0, i;
    for (i = 0; i < (n - 1); i++)
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[position] > array[j])
            {
                position = j;
                count++;
            }
            else
                count++;
        }
        if (position != i)
        {
            temp = array[i];
            array[i] = array[position];
            array[position] = temp;
            swap++;
        }
        count++;
        printf("\npass %d:\t", i + 1);
        for (k = 0; k < n; k++)
            printf("%d\t", array[i]);
    }
    printf("\n\nSorted list in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", array[i]);

    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printf("\nAfter pass %d : ", i);
        for (int k = 0; k < n; k++) {
            printf("%5d", arr[k]);
        }
    }
    printf("\n");
}

void deepcopy(int iarr[], int oarr[], int asize)
{
    //assuming size of arrays is same at this time
    for(int i = 0; i < asize; i++)
    {
        oarr[i] = iarr[i];
    }
}
