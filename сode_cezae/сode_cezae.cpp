#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

bool init();
string code_cezar(int offset, string input);
vector<char> get_array_abc(string language);
vector<char> get_array_char(string text);
int main()
{
    if (!init())
        return 0;
    cout << "Приветствую,я программа шифрующая сообщение на Русском языке с помощью шифра цезаря"<< endl;
    string text{ "" };
    int offset{ 0 };
    cout << "Введи предложение или слово которое будем шифровать:";getline(cin,text);cout << endl;
    cout << "Введи на сколько позиций сместить буквы в словах:";cin >> offset;cout << endl;
    cout << code_cezar(offset, text)<<endl;
    SetConsoleCP(866);
    SetConsoleOutputCP(866);
    system("pause");
}

bool init() {
    setlocale(0, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    return true;
}

string code_cezar(int offset, string input)
{
    vector<char> abc = get_array_abc("rus");
    vector <char> char_array_input = get_array_char(input);
    string output{ "" };
    for (auto i : char_array_input) {
        if (i == ' ') {
            output += " ";
        }
        else {
            int n = 0;
            for (auto j = abc.begin(); j != abc.end(); j++) {
                n++;
                if (i == *j) {

                    auto k = j;
                    if ((n + offset) <= abc.size())
                    {
                        k += offset;
                        output += *k;
                    }
                    else
                    {
                        k = abc.begin() + (((n + offset) - abc.size()) - 1);

                        output += *k;
                    }
                }

            }
        }
    }
    return output;
}

vector<char> get_array_abc(string language)
{
    vector<char> output{};
    string abc = "";
    if (language == "rus") {
        abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        for (auto i : abc) {
            output.push_back(i);
        }
    }
    return output;
}

vector<char> get_array_char(string text)
{
    vector<char> output{};
    for (auto i : text) {
        output.push_back(i);
    }
    return output;
}
