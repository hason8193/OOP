#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

Fraction getFraction() {
    Fraction f;
    cin >> f.numerator >> f.denominator;
    while (f.denominator == 0) {
        cin >> f.denominator;
    }
    return f;
}

void printFraction(Fraction f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

bool isGreater(Fraction a, Fraction b) {
    return (a.numerator * b.denominator > b.numerator * a.denominator);
}

bool isLess(Fraction a, Fraction b) {
    return (a.numerator * b.denominator < b.numerator * a.denominator);
}

void findMinMaxFraction(Fraction arr[], int n, Fraction& minF, Fraction& maxF) {
    minF = maxF = arr[0];
    for (int i = 1; i < n; i++) {
        if (isGreater(arr[i], maxF)) {
            maxF = arr[i];
        }
        if (isLess(arr[i], minF)) {
            minF = arr[i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    Fraction arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = getFraction();
    }

    Fraction minF, maxF;
    findMinMaxFraction(arr, n, minF, maxF);

    printFraction(minF);
    printFraction(maxF);

    return 0;
}
