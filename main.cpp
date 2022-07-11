#include <iostream>
#include <map> // для создания словаря с ключом-строкой и значением-массивом 
#include <vector> // массив в котором хранится номера(с единицы) строк
#include <fstream> // файловый поток
#include <sstream> // строковый поток   
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus"); //Включение русского языка.
    map<string, vector<uint32_t>> dict; //Словарь (map сортирует слова в алфавитном порядке)
    //Определение расположения файла.
    string fn; //Инициализация местоположения сканируемого файла.
    cout << "Введите расположение файла: ";
    cin >> fn;
    ifstream file(fn); //Открытие файла.
    string line;
    string word;
    uint32_t nos = 0; //Число строк в файле

    //Обработка файла.
    while (getline(file, line))
    {
        nos++; //Новая строка.
        istringstream ist(line); //Функция обработки текущей строки
        for (std::string word; ist >> word;)
        {
            if (dict.find(word) == dict.end())
            {
                vector<uint32_t> vect;
                dict[word] = vect;
            }
            dict[word].push_back(nos);
        }

    }
    file.close(); //Закрытие файла.

    for (map<string, vector<uint32_t>>::iterator it = dict.begin(); it != dict.end(); it++)
    {
        cout << "Слово <" << it->first << "> найдено в строках [ "; //Вывод найденного слова в алфавитном порядке.
        for (uint32_t i = 0; i < (it->second).size(); i++)
            cout << it->second[i] << " "; //Номера линий, в которых найдено слово.
        cout << "]" << endl;
    }
    return 0;
}
