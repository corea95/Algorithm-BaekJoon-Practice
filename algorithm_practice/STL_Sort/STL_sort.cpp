#include <iostream>
#include <algorithm>

using namespace std;

class Student
{
    public:
        string name;
        int score;
        Student(string name, int score)
        {
            this->name = name;
            this->score = score;
        }
        //정렬 기준은 점수가 작은 순서 
        bool operator < (const Student &student)const
        {
            return this->score < student.score;
        }
};

bool compare(int a, int b)
{
    return a > b;
}

int main(void)
{
    Student students[] = {
        Student("김민수", 90),
        Student("김영수", 80),
        Student("김땡수", 82),
        Student("김이수", 73),
        Student("김오수", 60)
    };
    sort(students, students + 5);
    for(int i = 0; i < 5; i++)
    {
        cout <<students[i].name<< "\n";
    }
}