#include <iostream>
#include <string>
using namespace std;

// ----------- ABSTRACT CLASS (Abstraction) -----------
class Person {
protected:
    int studentId;
    string name;

public:
    Person(int id, string n) {
        studentId = id;
        name = n;
    }

    // Pure virtual function → makes this an abstract class
    virtual void displayDetails() = 0;
};


// ----------- COURSE CLASS -----------
class Course {
private:
    string courseName;

public:
    Course(string cname) {
        courseName = cname;
    }

    string getCourseName() {
        return courseName;
    }
};


// ----------- STUDENT CLASS (Inheritance + Encapsulation + Polymorphism) -----------
class Student : public Person {
private:
    Course course;
    double marks;

public:
    // Constructor
    Student(int id, string n, Course c, double m)
        : Person(id, n), course(c) {
        marks = m;
    }

    // Encapsulation (Getter & Setter)
    double getMarks() {
        return marks;
    }

    void setMarks(double m) {
        marks = m;
    }

    // Grade Calculation
    string calculateGrade() {
        if (marks >= 70)
            return "A";
        else if (marks >= 60)
            return "B";
        else if (marks >= 50)
            return "C";
        else if (marks >= 40)
            return "D";
        else
            return "FAIL";
    }

    // Polymorphism (Overriding virtual function)
    void displayDetails() override {
        cout << "Student ID : " << studentId << endl;
        cout << "Name       : " << name << endl;
        cout << "Course     : " << course.getCourseName() << endl;
        cout << "Marks      : " << marks << endl;
        cout << "Grade      : " << calculateGrade() << endl;
        cout << "-----------------------------------" << endl;
    }
};


// ----------- MAIN FUNCTION -----------
int main() {

    // Create Course Object
    Course ictCourse("ICT");

    // Create Student Objects
    Student s1(101, "Wayne", ictCourse, 82);
    Student s2(102, "Alice", ictCourse, 66);
    Student s3(103, "Brian", ictCourse, 45);

    // Display Details
    s1.displayDetails();
    s2.displayDetails();
    s3.displayDetails();

    return 0;
}
