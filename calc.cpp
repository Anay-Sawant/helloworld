#include <iostream>
using namespace std;

double num1;
double num2;


void numbers(){
    cout << "Enter the 1st number :" << endl;
    cin >> num1;
    cout << "Enter the 2nd number :" << endl;
    cin >> num2;
}

int main()
{
    int num;
    cout << "Hello!" << endl;
    cout << "Press 1 for addition of numbers." << endl;
    cout << "Press 2 for subtraction of numbers." << endl;
    cout << "Press 3 for multiplication of numbers." << endl;
    cout << "Press 4 for division of numbers." << endl;
    cout << "Press 5 for trigonometric functions." << endl;
    cin >> num;
    if (num == 1){
        numbers();
        cout << "Sum of the numbers is : " << num1 + num2 << endl;
    }
    else if(num == 2){
        numbers();
        if(num1 - num2 >= 0){
            cout << "Difference of numbers is : " << num1 - num2 << endl;
        }
        else{
            cout << "Difference of numbers is : " << num2 - num1 << endl;
        }
    }
    else if(num == 3){
        numbers();
        double add = num1*num2;
        cout << "Product of numbers is : " << add << endl;
    }
    else if(num == 4){
        numbers();
        cout << "Division of number 1 by number 2 : " << num1/num2 << endl;
        cout << "Division of number 2 by number 1 : " << num2/num1 << endl;
    }
    else if(num == 5){
        int choice;
        double x;
        cout << "Enter the angle in radians : " << endl;
        cin >> x;
        cout << "Enter 1 for sin and cosec value" << endl;
        cout << "Enter 2 for cos and sec value" << endl;
        cout << "Enter 3 for tan and cot value" << endl;
        cin >> choice;
        double sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
        double cose = 1 - (x*x)/2 + (x*x*x*x)/24;
        double tane = x + (x*x*x)/3 + (2*x*x*x*x*x)/15;
        if(choice == 1){
            cout << "Sin : " << sine << " Cosec : " << 1/sine << endl;
        }
        else if(choice == 2){
            cout << "Cos : " << cose << " Sec : " << 1/cose << endl;
        }
        else if(choice == 3){
            cout << "Tan : " << tane << " Tane : " << 1/tane << endl;
        }
        else{
            cout << "Wrong input" << endl;
        }
    }
    else{
        cout << "Wrong input" << endl;
    }
    return 0;
}
