#include <iostream>
#include <string>

using namespace std;


double E();  
double E_(double left);
double T();
double T_(double left);
double F();  
bool match(char c);
void spac();

string an;
int a = 0;
void token(string an, int index){

}

void spac(){
    while (a < an.length() && isspace(an[a])) {
        a++;
    }
}

bool match(char c) {
    if (a < an.length() && an[a] == c) {
        a++;
        return true;
    }
    return false;
}


double E() { 
    double left = T();
    return E_(left);
}

double E_(double left) { 
    spac();
    if (match('*')) {
        double right = T();
        return E_(left * right);
    }
    if (match('/')) {
        double right = T();
        if (right == 0) {
            cout << "Error";
            exit(1);
        }
        return E_(left / right);
    }
    return left; 
}

double T() { 
    double left = F();
    return T_(left);
}


double T_(double left) { 
    spac();
    if (match('+')) {
        double right = F();
        return T_(left + right);
    }
    if (match('-')) {
        double right = F();
        return T_(left - right);
    }
    return left; 
}

double F() { 
    spac();
    if (match('(')) {  
        double value = E();
        if (!match(')')) {
            cout << "no )";
            exit(1);
        }
        return value;
    }

    
    if (isdigit(an[a])) {
        double num = 0;
        while (isdigit(an[a])) {  
            num = num * 10 + (an[a] - '0');
            a++;
        }

        if (an[a] == '.') {
            a++;
            double decimalPart = 0.1;
            while (isdigit(an[a])) {
                num += (an[a] - '0') * decimalPart;
                decimalPart /= 10;
                a++;
            }
        }

        return num;
    }

    cout << "invlad";
    exit(1);
}



// string an;
// int a = 0;


int main(){
    // string an;

    cout << "Enter input string";
    getline(cin, an);

    a = 0;
    spac();

    double r = E();  

    if (a == an.length()) {
        cout << "Result" << a << endl;
    } else {
        cout << "invalid expression";
    }

    return 0;

}