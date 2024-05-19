#include <iostream>
#include <string>

using namespace std;

//  EX 1 | шаблонная функция для целочисленных типов
template <typename T>
T gcd(T a, T b)
{
    static_assert(std::is_integral<T>::value, "Only integer types are used.");
    
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//  EX 1 | шаблонная функция для типа double
template <>
double gcd(double a, double b) {
    const double epsilon = 1e-9;
    while (fabs(b) > epsilon) {
        double temp = b;
        b = fmod(a, b);
        a = temp;
    }
    return a;
}

//  EX 2 | шаблонная функция для всех типов
template <typename T>
T* concatenate(const T* arr1, size_t size1, const T* arr2, size_t size2) {

    T* result = new T[size1 + size2];
    

    for (size_t i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    

    for (size_t i = 0; i < size2; ++i) {
        result[size1 + i] = arr2[i];
    }
    
    return result;
}

//  Примеры для первого задания
void ex1test()
{
    //  Пример использования переменными типа int
    cout << "INT:\n";
    int a = 46;
    int b = 138;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    //  Пример использования переменными типа long
    cout << "LONG:\n";
    long x = 1257778604;
    long y = 2087402222;
    cout << "GCD of " << x << " and " << y << " is " << gcd(x, y) << endl;

    //  Пример использования переменными типа long long
    cout << "LONG LONG:\n";
    long long p = 3153543841235654654;
    long long q = 7435134564568468454;
    cout << "GCD of " << p << " and " << q << " is " << gcd(p, q) << endl;
    
    //  Пример использования переменными типа short
    cout << "SHORT:\n";
    short z = 4;
    short v = 7;
    cout << "GCD of " << z << " and " << v << " is " << gcd(z, v) << endl;

    //  Пример использования переменными типа double
    cout << "DOUBLE:\n";
    double m = 26.4;
    double n = 6.15;
    cout << "GCD of " << m << " and " << n << " is " << gcd(m, n) << endl;
}

//  Примеры для второго задания
void ex2test()
{
    //  Пример использования с массивами типа int
    cout << "INT:\n";
    int arr1[] = {8, 5, 7};
    int arr2[] = {1, 6, 2};
    
    size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
    size_t size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int* result = concatenate(arr1, size1, arr2, size2);
    
    cout << "Concatenated array: ";
    for (size_t i = 0; i < size1 + size2; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    delete[] result;

    //  Пример использования с массивами типа double
    cout << "DOUBLE:\n";
    double arr3[] = {5.9, 6.3, 7.8};
    double arr4[] = {3.7, 2.9, 6.2};
    
    size_t size3 = sizeof(arr3) / sizeof(arr3[0]);
    size_t size4 = sizeof(arr4) / sizeof(arr4[0]);
    
    double* result2 = concatenate(arr3, size3, arr4, size4);
    
    cout << "Concatenated array: ";
    for (size_t i = 0; i < size3 + size4; ++i) {
        cout << result2[i] << " ";
    }
    cout << endl;
    
    delete[] result2;

    //  Пример использования с массивами типа string
    cout << "STRING:\n";
    string arr5[] = {"hello ", "everybody ", "my "};
    string arr6[] = {"name ", "is ", "welcome"};
    
    size_t size5 = sizeof(arr5) / sizeof(arr5[0]);
    size_t size6 = sizeof(arr6) / sizeof(arr6[0]);
    
    string* result3 = concatenate(arr5, size5, arr6, size6);
    
    cout << "Concatenated array: ";
    for (size_t i = 0; i < size5 + size6; ++i) {
        cout << result3[i] << " ";
    }
    cout << endl;
    
    delete[] result3;

    //  Пример использования с массивами типа char
    cout << "CHAR:\n";
    char arr7[] = {'g', 'a', 'y'};
    char arr8[] = {'b', 'a', 'r'};
    
    size_t size7 = sizeof(arr7) / sizeof(arr7[0]);
    size_t size8 = sizeof(arr8) / sizeof(arr8[0]);
    
    char* result4 = concatenate(arr7, size7, arr8, size8);
    
    cout << "Concatenated array: ";
    for (size_t i = 0; i < size7 + size8; ++i) {
        cout << result4[i] << " ";
    }
    cout << endl;
    
    delete[] result4;
}

int main()
{
    cout << "Practice 11 | Version 10\n";
    
    cout << "\nEX 1\n";
    ex1test();

    cout << "\nEX 2\n";
    ex2test();
    
    return 0;    
}