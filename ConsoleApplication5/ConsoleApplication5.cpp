// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
using namespace std;

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
