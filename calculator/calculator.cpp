#include <iostream>
#include <getopt.h>
using namespace std;
void help(){
    cout<<"Неверное количество значений"<<endl;
    exit(1);
}
int main(int argc, char *argv[])
{
    if (argc==1) {
        cout<<"Мультипликативный калькулятор"<<endl
            <<"Для использования калькулятора нужно ввести один из параметров"<<endl
            <<"-m — умножение всех введенных значений" << endl
            <<"-d — деление первого значения на все последующие введенные значения"<< endl
            <<"Количество значений от 4 до 6"<< endl
            <<"Для того чтобы продолжить запустите программу еще раз с нужным параметром и введите значения через пробел"<< endl;
    }
    int opt, i, a=1, b, d,st=0;
    for (i=2; i<argc; i++){
        st+=1;
    }
    if ((st > 0 and st<4) or (st>6)){
        help();
    }
    while ((opt = getopt (argc, argv, "d:m:")) != -1) {
        switch (opt) {
        case 'm':
            for(i=2; i<argc; i++) {
                b = strtol(argv[i], NULL, 10);
                a = a * b;
            }
            cout<< "Результат: "<< a << endl;
            break;
        case 'd':
            b = strtol(argv[2], NULL, 10);
            for(i=3; i<argc; i++) {
                d = strtol(argv[i], NULL, 10);
                b = b/d;
            }
            cout<< "Результат: "<< b << endl;
            break;
        }
    }
}

