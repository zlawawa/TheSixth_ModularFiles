#ifdef _WIN64
#include <windows.h>
#endif

#include <iostream>
#include "LBWork6.h"
#include <fstream>
using namespace std;

int ChooseTask() {
    int ChoiceTasks;
    std::cout << "\nВыберите задачу: \n";
    std::cout << "1. Задача №1 - ExamTaskC2; \n";
    std::cout << "2. Задача №2 - 2; \n";
    std::cout << "3. Задача №3 - 3; \n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";
    std::cin >> ChoiceTasks;
    std::cout << "\n";
    return ChoiceTasks;
}

int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif

    int Choice1;
    do {
        Choice1 = ChooseTask();
        if (Choice1 == 0) { 
            std::cout << "Завершение работы...\n";
            std::cout << "Работа завершена.\n";
            break; 
        }
        switch (Choice1) {
            case 1: {
                ExamTaskC2();
                break;
            } case 2: {
                Task2();
                break;
            } case 3: {
                Task3();
                break;
            } default: {
                std::cout << "Неверно ввведены данные!\n";
                break;
            }
        } 
    } while (true);
    return 0;
}
