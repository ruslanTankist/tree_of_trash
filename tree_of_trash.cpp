﻿// tree_of_trash.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Необходимо реализовать простую иерархию классов для хранения нескольких простых типов данных: 
// int (32 бита); char[10]; double. Предполагается единственный абстрактный базовый класс – BaseHolder, и его наследники – 
// IntHolder, CharArrayHolder и DoubleHolder. Далее необходимо реализовать структуру данных — дерево указателей на базовый класс — 
// и наполнить его в теле программы несколькими произвольными элементами, используя разные типы (int , char[], double).

//В рамках тестового задания необходимо реализовать код сохранения и восстановления дерева. 
//• Вариант 1. Бинарный файл – (можно применять любые API для чтения и записи).
//• Вариант 2. Текстовый файл – (можно применять любые API для чтения и записи). 
//• Вариант 3. Непрерывная область памяти, выделенная через new char[N].

#include <iostream>
#include <fstream>
#include <string>

#include "tree_class_hierarchy.h"

int main()
{
    char* line = new char[11];
    std::ifstream case1;
    case1.open("case1.txt");

    Tree* tree = new Tree();
    BaseHolder* element;
    if (case1.is_open()) {
        while (case1.getline(line, 11)) {
            char* data = &line[1];
            switch (line[0])
            {
            case 'i':
                element = new IntHolder(std::stoi(data));
                tree->push(element);
                break;
            case 'd':
                element = new DoubleHolder(std::stod(data));
                tree->push(element);
                break;
            case 's':
                element = new CharArrayHolder(data);
                tree->push(element);
                break;
            default:
                std::cout << "corrupted input, unknown value type: " << line[0] << std::endl;
            }
        }
        case1.close();
    }

    tree->show();

    tree->clear();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
