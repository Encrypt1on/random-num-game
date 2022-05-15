// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
using namespace std;
/*void randn(int a, int b, int rand_num, int tmp) {
    
    int user_num;
    tmp++;
    cout << "Vvodi chislo: ";
    cin >> user_num;
    if (user_num < rand_num) {
        
        cout << "Men'she" << endl;
        randn(a, b,rand_num,tmp);
    }
    else if (user_num > rand_num) {
        cout << "Bol'she" << endl;
        randn(a, b,rand_num,tmp);
    }
    else {
        cout << "Ygadal!!! Chislo popitok - " << tmp;
        return;
    }
    
}
int main()
{
    int a, b,rand_num;
    cout << "Vvedite granici cherez probel: ";
    cin >> a >> b;
    srand(time(0));
    rand_num = rand() % b + a;
    cout << "Zagadal!\n";
    int tmp = 0;
    randn(a, b,rand_num,tmp);
}


int rand_num, user_num;
    rand_num = rand() % b + a;
    cout << "Zagadal!\n";
    int tmp = 1;
    while (1) {
        cout << "Vvodi chislo: ";
        cin >> user_num;
        if (user_num < rand_num) {
            cout << "Men'she" << endl;
        }
        else if (user_num > rand_num) {
            cout << "Bol'she" << endl;
        }
        else {
            cout << "Ygadal!!! Chislo popitok - " << tmp;
            break;
        }
        tmp++;
    }
void Fizzbuzz(int i) {
    if (i == 101) {
        return;
    }
    if (i % 3 == 0) {
        if (i % 5 == 0) {
            cout << "FizzBuzz" << endl;
            i++;
            Fizzbuzz(i);
        }
        else {
            cout << "Fizz" << endl;
            i++;
            Fizzbuzz(i);
        }
    }
    else if (i % 5 == 0) {
        cout << "Buzz" << endl;
        i++;
        Fizzbuzz(i);
    }
    else {
        cout << i << endl;
        i++;
        Fizzbuzz(i);
    }
}

int main()
{
    int i = 1;
    Fizzbuzz(i);
}

void prog(int min,int max) {

    int sr;
    char ch;
    cout << "max = " << max << " min = " << min << endl;
    sr = min + ((max - min) / 2);
    if (max - 1 == min + 1) {
        cout << "Tvoye chislo - " << sr << "! Ya ygadal!!!\n\n" ;
        return;
    }
    cout << "Chislo = " << sr << "?(b/m/y)";
    cin >> ch;
    
    if (ch == 'b') {
        min = sr;
        prog(min, max);
    }
    else if (ch == 'm') {
        max = sr;
        prog(min, max);
    }
    else if (ch == 'y') {
        cout << "Tvoye chislo - " << sr << "! Ya ygadal!!!";
        return;
    }
    
    else {
        cout << "Drygyu bukbu" << endl;
        prog(min, max);
    }
}

void choice() {
    int ch;
    cout << "Menu\n1 - zadat svoi diapozon\n2 - programma zadaet diapozon, vi vibiraete chislo, i ona pitaetsya ygadat'" << endl << "Vash vibor: ";
    cin >> ch;
    if (ch == 1) {
        int a, b;
        cout << "Granici: ";
        cin >> a >> b;
        prog(a, b);
    }
    else if (ch == 2) {
        
        int a = rand() % 100 + 0;
        int b = rand() % 100 + a;
        cout << "Granici: " << a << '-' << b << endl;
        prog(a, b);
    }
}
*/
class Game {
public:
    void StartGuessGame() {
        int ch;
        cout << "1 - go to menu\n2 - exit\nChoice: ";
        cin >> ch;
        if (ch == 2) {
            cout << "\nBye!\n";
            return;
        }
        choice();
    }
private:
    void choice() {
        int ch;
        cout << "\nMenu\n1 - zadat svoi diapozon\n2 - programma zadaet diapozon, vi vibiraete chislo, i ona pitaetsya ygadat'" << endl << "Vash vibor: ";
        cin >> ch;
        if (ch == 1) {
            int a, b;
            cout << "Granici(example - 10 20): ";
            cin >> a >> b;
            prog(a, b);
            StartGuessGame();
        }
        else if (ch == 2) {
            srand(time(0));
            int a = rand() % 100 + 0;
            int tmp = a + 1;
            int b = rand() % 100 + tmp;
            cout << "\nGranici: " << a << '-' << b << endl;
            prog(a, b);
            StartGuessGame();
        }
    }
    void prog(int min, int max) {

        int sr;
        char ch;
        cout << "max = " << max << " min = " << min << endl;
        sr = min + ((max - min) / 2);
        if (max - 1 == min + 1) {
            cout << "\nTvoye chislo - " << sr << "! Ya ygadal!!!\n\n";
            return;
        }
        cout << "Chislo = " << sr << "?(b/m/y)";
        cin >> ch;

        if (ch == 'b') {
            min = sr;
            prog(min, max);
        }
        else if (ch == 'm') {
            max = sr;
            prog(min, max);
        }
        else if (ch == 'y') {
            cout << "Tvoye chislo - " << sr << "! Ya ygadal!!!\n\n";
            return;
        }

        else {
            cout << "Drygyu bukbu" << endl;
            prog(min, max);
        }
    }
};
int main()
{
    Game guessGame;
    guessGame.StartGuessGame();  
}