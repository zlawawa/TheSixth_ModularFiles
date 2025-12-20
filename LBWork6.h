#include <vector>

struct CInfo {
        int Year;
        int Month;
        int Duration;
        int ClientCode;
};
void ExamTaskC2();

union PupilData {
      short int Reading; 
      float ExamScores;
      short int KTMath;
};
struct Pupil {
      int Grade;
      std::string Name;
      std::string SurName;
      PupilData PD;
};
bool InputPupil(Pupil& PL, int id);
void Task2();

struct Student {
      std::string Name;
      int Age;
      float Points;
};
int SelectAction();
void AddStudent(std::vector<Student>& Students);
void OutputInformationAboutAStudent(const std::vector<Student>& ST);
int CntStudetsPoints(const std::vector<Student>& ST);
void SearchStudents(const std::vector<Student>& ST, int Age);
void ModifyStudInfo(std::vector<Student>& ST);
double CalculateGPA(const std::vector<Student> ST);
void Task3();
