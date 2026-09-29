#include <iostream>
#include <string>
#include <vector>
#include <numeric>

class Student
{
private:
    std::string name;
    std::vector<int> grades;  

public:
    
    Student() : name("Неизвестный") {}

    
    Student(const std::string& student_name) : name(student_name) {}

    
    void add_grade(int grade)
    {
        if (grade < 1 || grade > 5)
        {
            std::cout << "Ошибка: оценка должна быть от 1 до 5!\n";
            return;
        }
        grades.push_back(grade);
    }

    
    void add_grades(std::initializer_list<int> new_grades)
    {
        for (int g : new_grades)
        {
            add_grade(g);
        }
    }

    void print_grades() const
    {
        if (grades.empty())
        {
            std::cout << "У студента " << name << " пока нет оценок.\n";
            return;
        }

        std::cout << "Оценки студента " << name << ": ";
        for (int g : grades)
        {
            std::cout << g << " ";
        }
        std::cout << "\n";
    }

    double average() const
    {
        if (grades.empty()) return 0.0;
        double sum = std::accumulate(grades.begin(), grades.end(), 0);
        return sum / grades.size();
    }
    
    
    const std::string& get_name() const { return name; }

    size_t count() const { return grades.size(); }
};

int main()
{
    Student s1("Иван Иванов");
    s1.add_grade(5);
    s1.add_grade(4);
    s1.add_grade(3);
    s1.add_grades({ 5, 4, 5 });

    s1.print_grades();
    std::cout << "Средний балл: " << s1.average() << "\n";
    std::cout << "Всего оценок: " << s1.count() << "\n\n";

    Student s2("Пётр Петров");
    s2.print_grades();

    return 0;
}