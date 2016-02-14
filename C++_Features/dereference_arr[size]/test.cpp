#include <iostream>
#include <algorithm>

void mysort(int* arr, std::size_t size)
{
    std::sort(&arr[0], &arr[size]);
}

int main()
{
    int a[] = {42, 12, 60};
    mysort(a, 3);
    return 0;
}
