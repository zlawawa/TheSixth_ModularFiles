#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "LBWork6.h"

using namespace std;

void ExamTaskC2() {
    std::cout << "====== 1. Задание №1 - ExamTaskC2 ======\n";
    ofstream f2("LBWork6Answers.txt", ios::out);
    int N;
    std::cout << "Введите кол-во клиентов, о которых хотите узнать информацию: ";
    std::cin >> N;
    CInfo MaxT = {-100, -100, -100, -100};
    std::cout << "Введите данные в формате: Год (2000-2010)/Месяц (1-12)/Продолжительность (1-30)/Код_клиента (10-99).\n";
    for (int i = 0; i < N; i++) {
        CInfo Cl;
        std::cout << "Клиент №" << i + 1 << ": ";
        std::cin >> Cl.Year >> Cl.Month >> Cl.Duration >> Cl.ClientCode;
        std::cout << "\n";
        if (Cl.Year < 2000 || Cl.Year > 2010 || Cl.Month < 0 || Cl.Month > 12 || Cl.Duration < 1 || Cl.Duration > 30 || Cl.ClientCode < 10 || Cl.ClientCode > 99) {
            std::cout << "Вы неверно ввели данные!\n";
            return;
        }
        if (Cl.Duration > MaxT.Duration) {
            MaxT = Cl;
        }
    }
    std::cout << "Результаты (продолжительность/год/месяц): " << MaxT.Duration << " " << MaxT.Year << " " << MaxT.Month << "\n";
    f2 << "Результаты (продолжительность/год/месяц): " << MaxT.Duration << " " << MaxT.Year << " " << MaxT.Month << "\n";
    f2.close();
    std::cout << "========= Конец задачи =========\n";
}

bool InputPupil(Pupil& PL, int id) {
    PupilData PD;

    std::cout << "Введите ФИ ученика №" << id + 1 << ": ";
    std::cin >> PL.SurName >> PL.Name;

    std::cout << "Введите класс ученика: ";
    std::cin >> PL.Grade;
    if (PL.Grade < 1 || PL.Grade > 4) {
        std::cout << "Неверно введён класс!\n";
        return false;
    }

    if (PL.Grade == 1) {
        std::cout << "Введите скорость чтения ученика (слов/мин): ";
        std::cin >> PL.PD.Reading;
        if (PL.PD.Reading <= 0) { std::cout << "Скорость чтения должна быть больше нуля!"; return false; }
    } else if (PL.Grade == 2 || PL.Grade == 3) {
        std::cout << "Введите баллы за итоговую контрольную по математике (1 - 10): ";
        std::cin >> PL.PD.KTMath;
        if (PL.PD.KTMath < 1 || PL.PD.KTMath > 10) { std::cout << "Ошибка: баллы должны быть от 1 до 10\n"; return false; }
    } else if (PL.Grade == 4) {
        std::cout << "Введите баллы за итоговую аттестацию ученика (1 - 100): ";
        std::cin >> PL.PD.ExamScores;
        if (PL.PD.ExamScores < 1 || PL.PD.ExamScores > 100) { std::cout << "Ошибка: баллы должны быть от 1 до 100\n"; return false; }
    } else { std::cout << "Неверно введены данные!"; return false; }
    return true;
}

void Task2() {
    std::cout << "====== 2. Задание №2 - Task2 ======\n";

    ofstream f2("LBWork6Answers.txt", ios::out);
    if (!f2) { std::cout << "Error!\n"; return; }

    int N;
    std::cout << "Введите кол-во учеников: ";
    std::cin >> N;

    vector <Pupil> Pupils(N);
    f2 << "№  |  Класс  |   Фамилия и Имя    |     Доп. информация\n";
    f2 << "_______________________________________________________\n";

    for (int i = 0; i < N; i++) {
        if (!InputPupil(Pupils[i], i)) {
            std::cout << "\nВы неверно ввели данные. Ввод прерван.\n";
            f2.close();
            return; 
        }
        f2 << i + 1 << "  |  " << Pupils[i].Grade << "      |  " << Pupils[i].SurName << " " << Pupils[i].Name << "   |   ";
        if (Pupils[i].Grade == 1) {
            f2 << Pupils[i].PD.Reading << " слов/мин\n";
        } else if (Pupils[i].Grade == 2 || Pupils[i].Grade == 3) {
            f2 << Pupils[i].PD.KTMath << " баллов (матем.)\n";
        } else if (Pupils[i].Grade == 4) {
            f2 << Pupils[i].PD.ExamScores << " баллов (итоговая атт.)\n";
        }
    }
    f2.close();
    std::cout << "Данные записаны в файл 'LBWork6Answers.txt'.\n\nРезультат:\n\n";

    std::cout << "№  |  Класс  |   Фамилия и Имя    |     Доп. информация\n";
    std::cout << "_________________________________________________________\n";

    for (int i = 0; i < Pupils.size(); i++) {
        std::cout << i + 1 << "  |  " << Pupils[i].Grade << "      |  " << Pupils[i].SurName << " " << Pupils[i].Name << "   |   ";
        if (Pupils[i].Grade == 1)
            std::cout << Pupils[i].PD.Reading << " слов/мин\n";
        else if (Pupils[i].Grade == 2 || Pupils[i].Grade == 3)
            std::cout << Pupils[i].PD.KTMath << " баллов (матем.)\n";
        else if (Pupils[i].Grade == 4)
            std::cout << Pupils[i].PD.ExamScores << " баллов (итоговая атт.)\n";
        }
    std::cout << "====================== Конец задачи =====================\n";
}

int SelectAction() {
    int Choice;
    std::cout << "\nВыберите действие 1-6: \n";
    std::cout << "1. Добавить студента;\n";
    std::cout << "2. Вывести информацию о студенте;\n";
    std::cout << "3. Подсчёт кол-ва студентов с высоким средним баллом (выше 4.0);\n";
    std::cout << "4. Поиск студентов по возрасту;\n";
    std::cout << "5. Изменить информацию о студенте;\n";
    std::cout << "6. Вычислить общий средний балл определённого студента;\n";
    std::cout << "0. Вернуться к выбору заданий.\n";
    std::cout << "Ваш выбор? ";
    std::cin >> Choice;
    return Choice;
}

void AddStudent(std::vector<Student>& Students) {
    Student Add;
    std::cout << "Введите имя студента: ";
    std::cin >> Add.Name;
    std::cout << "Введите возраст студента: ";
    std::cin >> Add.Age;
    if (Add.Age >= 0 && Add.Age <= 70) {
        std::cout << "Введите средний балл студента: ";
        std::cin >> Add.Points;
        Students.push_back(Add);
        std::cout << "Студент успешно добавлен!\n";
    } else {
        std::cout << "Введите корректный возраст студента!\n";
    }
}

void OutputInformationAboutAStudent(const vector<Student>& ST) {
    if (ST.empty()) { std::cout << "\nСписок студентов пуст!\n"; return; }
    int NumStud;
    std::cout << "\nВведите любой номер студента №";
    std::cin >> NumStud;
    if (NumStud <= ST.size()) {
        std::cout << "\nСтудент с №" << NumStud << "\n";
        std::cout << NumStud << ". " << ST[NumStud - 1].Name << ", " << ST[NumStud - 1].Age << " лет, " << ST[NumStud - 1].Points << " баллов;\n";
    } else {
        std::cout << "Нет студента с таким номером.\n";
        return;
    }
}

int CntStudetsPoints(const std::vector<Student>& ST) {
    int Count = 0;
     for (int i = 0; i < ST.size(); i++) {
        if (ST[i].Points > 4.0) {
            Count++;
        }
    }
    return Count;
}

void SearchStudents(const std::vector<Student>& ST, int Age) {
    bool Found = false;
    std::cout << "Найденные студенты возраста " << Age << ":\n";
    for (int i = 0; i < ST.size(); i++) {
        if (ST[i].Age == Age) {
            std::cout << i + 1 << ". " << ST[i].Name << " " << ST[i].Points << "\n";
            Found = true;
        }
    }
    if (!Found) {
        std::cout <<  "Студентов такого возраста не найдено.\n";
    }
}

void ModifyStudInfo(std::vector <Student>& ST) {
    if (ST.empty()) { std::cout << "Список студентов пуст!\n"; return; }
    std::string Name;
    std::cout << "Введите имя студента для изменения: ";
    std::cin >> Name;
    for (int i = 0; i < ST.size(); i++) {
        if (ST[i].Name == Name) {
            std::cout << "Текущие данные студента: \n";
            std::cout << i + 1 << ". " << ST[i].Name << ", " << ST[i].Age << " лет, " << ST[i].Points << " баллов;\n";
            std::cout << "Введите новый возраст: ";
            std::cin >> ST[i].Age;
            std::cout << "Введите новый средний балл: ";
            std::cin >> ST[i].Points;
            std::cout << "\nДанные обновлены.\n";
            return;
        }
    }
    std::cout << "Студент с именем '" << Name << "' не найден.\n";
}

double CalculateGPA(const std::vector<Student> ST) {
    if (ST.empty()) {
        return 0.0;
    }
    double Sum = 0.0, Result = 0.0;
    int Quantity = ST.size(), Count, NumStud;
    for (int i = 0; i < ST.size(); i++) {
        std::cout << i + 1 << ". " << ST[i].Name << ", " << ST[i].Points << " баллов;\n";
    }
    std::cout << "Сколько студентов выбрать для вычисления общего среднего балла? ";
    std::cin >> Count;
    if (Count <= 0 || Count > Quantity) { std::cout << "Неверное кол-во.\n"; return 0.0; }
    std::cout << "Введите номера студентов: \n";
    for (int i = 0; i < Count; i++) {
        std::cin >> NumStud;
        if (NumStud < 1 || NumStud > ST.size()) {
            std::cout << "Некорректный номер: " << NumStud << ". Пропуск номера.\n";
            continue;
        }
        Sum += ST[NumStud - 1].Points;
    }
    Result = Sum / Quantity;
    return Result;
}

void Task3() {
    std::vector<Student> Students;
    while (true) {
          
        int Choice1 = SelectAction();
        if (Choice1 == 0) {
            std::cout << "Завершение работы...\n";
            std::cout << "Работа завершена.\n";
            return;
        }
        switch (Choice1) {
            case 1: {
                AddStudent(Students);
                break;
            } case 2: {
                OutputInformationAboutAStudent(Students);
                break;
            } case 3: {
                int Cnt = CntStudetsPoints(Students);
                std::cout << "\nСтудентов с баллами больше 4.0: " << Cnt << "\n";
                break;
            } case 4: {
                int Age;
                std::cout << "\nВведите возраст, по которому хотите найти студентов: ";
                std::cin >> Age;
                SearchStudents(Students, Age);
                break;
            } case 5: {
                ModifyStudInfo(Students);
                break;
            } case 6: {
                double GPA = CalculateGPA(Students);
                std::cout << "Общий средний балл всех студентов: " << GPA << "\n";
                break;
            } default: {
                std::cout << "Некорректно введены данные.\n";
                break;
            }
        }
    }
}