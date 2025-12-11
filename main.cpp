// C/C++ Project 1 - Basic Syntax
// AMS 595
// Abby Bindelglass 

#include <iostream>
#include <vector>
using namespace std;

// 1. Conditional Statements
void run_q1() {
    int n;

    cout << "Enter a number: "; // ask user for input
    cin >> n; // read integer input

    // switch statement to check value of n and display in words
    switch (n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
    }
}
// 2. Printing a Vector
void print_vector(vector<int> v) {
    // loop through all vector elements
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        // print space after all but last element
        if (i < v.size() - 1)
            cout << " ";
    }
    cout << endl;
}
// demonstrate print_vector function with example
void run_q2() {
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Vector contents: ";
    print_vector(v);
}   
// 3. While Loops - Fibonacci
void fibonacci() {
    int a = 1, b = 2; // first two Fibonacci numbers
    while (a <= 4000000) { // continue as long as current Fibonacci number is <= 4,000,000
        cout << a << " "; // print current Fibonacci number
        int next = a + b; // calculate next Fibonacci number
        // shift for next iteration
        a = b;
        b = next;
    }
    cout << endl; // end line after printing all numbers
}
void run_q3() {
    cout << "Fibonacci numbers up to 4,000,000\n";
    fibonacci();
}
// 4.1. If Prime
bool isprime(int n) {
    // numbers less than or equal to 1 are not prime
    if (n <= 1) 
        return false;
    // divisibility check from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) // if any divides evenly, not prime
            return false;
    }
    return true; // no divisors found, is prime
}
void test_isprime() {
    // test cases for isprime function
    cout << "isprime(2) = " << isprime(2) << '\n';
    cout << "isprime(10) = " << isprime(10) << '\n';
    cout << "isprime(17) = " << isprime(17) << '\n';
}
// 4.2. Factorize
vector<int> factorize(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++) { // check all numbers from 1 to n
        if (n % i == 0)
            answer.push_back(i); // if i divides n, add to factors
    }
    return answer;
}
// test examples for factorize function
void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}
// 4.3. Prime Factorization
vector<int> prime_factorize(int n) {
    vector<int> answer;
    int d = 2; // divider starting from smallest prime
    while (n > 1) { // continue until n is reduced to 1
        if (n % d == 0) { 
            answer.push_back(d); // d is a prime factor
            n /= d; // divide n by d
        } else {
            d++; // try next integer as possible factor
        }
    }
    return answer;
}
// test examples for prime_factorize function
void test_prime_factorize() {
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}
// 5. Recursive Functions and Loops
void pascal(int n) {
    vector<int> row; // hold current row
    for (int i = 0; i < n; i++) { // generate rows from 0 to n-1
        vector<int> new_row(i + 1); // new row has i+1 elements
        // first and last elements are 1
        new_row[0] = 1;
        new_row[i] = 1;
        // fill in interior elements using previous row
        for (int j = 1; j < i; j++)
            new_row[j] = row[j - 1] + row[j];
        row = new_row; // update row to be new_row for next iteration
        // print current row
        for (int x : row)
            cout << x << " ";
        cout << endl; // end line after each row
    }
}
void run_q5() {
    cout << "Pascal's Triangle (first 5 rows)\n";
    pascal(5); // print first 5 rows of Pascal's Triangle
}
//main
int main() {
    cout << "C/C++ Project 1\n\n";

    cout << "Question 1\n";
    run_q1();
    cout << "\n";

    cout << "Question 2\n";
    run_q2();
    cout << "\n";

    cout << "Question 3\n";
    run_q3();
    cout << "\n";

    cout << "Question 4.1\n";
    test_isprime();
    cout << "\n";

    cout << "Question 4.2\n";
    test_factorize();
    cout << "\n";

    cout << "Question 4.3\n";
    test_prime_factorize();
    cout << "\n";

    cout << "Question 5\n";
    run_q5();
    cout << "\n";

    return 0;
}