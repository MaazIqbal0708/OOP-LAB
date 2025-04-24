#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cred) : courseCode(code), credits(cred) {}
    virtual ~Course() {}
    virtual string calculateGrade() const = 0;
    virtual void displayInfo() const = 0;
};

class LectureCourse : public Course {
    double MTScore;
    double finalScore;
    double assignScore;

public:
    LectureCourse(string code, int cred, double mid, double fin, double assign)
        : Course(code, cred), MTScore(mid), finalScore(fin), assignScore(assign) {}

    string calculateGrade() const override {
        double total = (MTScore * 0.3) + (finalScore * 0.5) + (assignScore * 0.2);
        
        if(total >= 85) { return "A";
        } else if(total >= 75) { return "B";
        } else if(total >= 65) { return "C";
        } else if(total >= 50) { return "D";
        } else { return "F";
        }
    }

    void displayInfo() const override {
        cout << "LECTURE COURSE: " << courseCode << "\n"
            << "Credit Hours: " << credits << "\n"
            << "Grading Components:\n"
            << "- Midterm (30%): " << MTScore << "\n"
            << "- Final (50%): " << finalScore << "\n"
            << "- Assignments (20%): " << assignScore << "\n"
            << "Final Grade: " << calculateGrade() << "\n";
    }
};

class LabCourse : public Course {
    double labworksScore;
    double examScore;
    double attendanceScore;

public:
    LabCourse(string code, int cred, double reports, double practical, double attendance)
        : Course(code, cred), labworksScore(reports), examScore(practical), attendanceScore(attendance) {}

    string calculateGrade() const override {
        double total = (labworksScore * 0.4) + (examScore * 0.5) + (attendanceScore * 0.1);
        
        if(total >= 90) { return "A";
        } else if(total >= 80) { return "B";
        } else if(total >= 70) { return "C";
        } else if(total >= 60) { return "D";
        } else { return "F";
        }
    }

    void displayInfo() const override {
        cout << "LAB COURSE: " << courseCode << "\n"
            << "Credits: " << credits << "\n"
            << "Grading Components:\n"
            << "- Lab WOrks(40%): " << labworksScore << "\n"
            << "- Practical Exam(50%): " << examScore << "\n"
            << "- Attendance(10%): " << attendanceScore << "\n"
            << "Final Grade: " << calculateGrade() << "\n";
    }
};

int main() {
    const int num_courses = 3;
    Course* courses[num_courses] = {
        new LectureCourse("CS0542", 3, 80.5, 75.2, 90.7),
        new LabCourse("SE1234", 1, 85.1, 92.5, 95.4),
        new LectureCourse("MVC102", 4, 70.0, 65.6, 80.4)
    };

    for (int i = 0; i < num_courses; i++) {
        cout << "\n";
        courses[i]->displayInfo();
        cout << "------------------------\n";
    }

    for (int i = 0; i < num_courses; i++) {
        delete courses[i];
    }

    return 0;
}