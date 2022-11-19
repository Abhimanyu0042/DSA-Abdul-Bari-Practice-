#include <iostream>
using namespace std;

struct array
{
    int A[10];
    int size;
    int length;
};

void Display(struct array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

// this can be used to merge two arrays using third array
struct array *Union(struct array *arr1, struct array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = new array[arr3->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
        else
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
            j++;
        }
    }
    // copying the rest if the elements
    for (; i < arr1->length; i++)
    {
        arr3->A[k] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

// here we have to only copy equal elements in both the arrays to the 3rd array
struct array *intersection(struct array *arr1, struct array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = new array[arr3->size];

    while (i < arr1->length && j < arr2->length)
    {
        // here we will not copy elements which are different
        if (arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }

        // equal elements in both arrays are copied to third elements
        else if (arr1->A[i] = arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct array *Difference(struct array *arr1, struct array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct array *arr3 = new array[arr3->size];

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
        {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if (arr2->A[j] < arr1->A[i])
        {
            j++;
        }
        else if (arr1->A[i] = arr2->A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k] = arr1->A[i];
    }
    for (; j < arr2->length; j++)
    {
        arr3->A[k] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct array arr2 = {{2, 3, 9, 18, 28}, 10, 5};
    struct array *arr3;

    // arr3 = Union(&arr1,&arr2);
    arr3 = Difference(&arr1, &arr2);
    Display(*arr3);

    return 0;
}