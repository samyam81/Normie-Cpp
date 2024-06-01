#include <iostream>

#include <vector>

using namespace std;

class Student
{

private:
    int rollno, age;
    string name;
public:
    Student(int stdId, string stdName, int stdAge)
    {
        rollno = stdId;
        name = stdName;
        age = stdAge;
    }
    void setRollno(int stdId)
    {
        rollno = stdId;
    }

    int getRollno()
    {
        return rollno;
    }

    void setName(string stdName)
    {
        name = stdName;
    }

    string getName()
    {
        return name;
    }

    void setAge(int stdAge)
    {
        age = stdAge;
    }

    int getAge()
    {
        return age;
    }

    void displayStudent()
    {
        cout << "Roll No : " << rollno << endl;
        cout << "Name :" << name << endl;
        cout << "Age : " << age << endl;
    }
};

// Create functionto update Student record

void updateStudent(vector<Student> &students)
{
    string sname;
    bool found = false;
    int choice;
    cout << "\t\tEnter Name to Update Record :";
    cin.ignore();
    getline(cin, sname);
    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getName() == sname)
        {

            found = true;

            cout << "\t\t---Student Found -----" << endl;

            cout << "\t\t 1. Update Rollno " << endl;

            cout << "\t\t 2. Update Name " << endl;

            cout << "\t\t 3. Update Age " << endl;

            cout << "\t\tEnter Your Choice :";

            cin >> choice;

            switch (choice)
            {

            case 1:
            {

                int rno;

                cout << "\t\tEnter New Rollno :";

                cin >> rno;

                students[i].setRollno(rno);

                break;
            }

            case 2:
            {

                string name;

                cout << "\t\tEnter New Name :";

                cin.ignore();

                getline(cin, name);

                students[i].setName(name);

                break;
            }

            case 3:
            {

                int age;

                cout << "\t\tEnter New Age :";

                cin >> age;

                students[i].setAge(age);

                break;
            }

            default:

                cout << "\t\tInvalid Number" << endl;
            }
        }

        if (!found)
        {

            cout << "\t\tRecord Not Found" << endl;

            return;
        }
    }
}

// create function to search studnet in list

void SearchStudent(vector<Student> &students)
{

    int rollno;

    cout << "\t\tEnter Rollno :";

    cin >> rollno;

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getRollno() == rollno)
        {

            cout << "\t\t--------Student Found ------------" << endl;

            students[i].displayStudent();

            return;
        }
    }
}

// create function to show all list of  student

void DisplayAllStudent(vector<Student> &students)
{

    if (students.empty())
    {

        cout << "\t\t No Student Found " << endl;

        return;
    }

    for (int i = 0; i < students.size(); i++)
    {

        students[i].displayStudent();

        cout << endl;
    }
}

// create function to add new student

void addNewStudent(vector<Student> &students)
{

    int rollno, age;

    string name;

    cout << "Enter Rollno :";

    cin >> rollno;

    // check if student already exit

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getRollno() == rollno)
        {

            cout << "\t\tStudent Already Exit" << endl;

            return;
        }
    }

    cout << "Enter Name : ";

    cin >> name;

    cout << "Enter Age : ";

    cin >> age;

    Student newStudent(rollno, name, age);

    students.push_back(newStudent);
}

// create function to delete student in list

void deleteStudent(vector<Student> &students)
{

    string name;

    cout << "Enter Name to Delete :";

    cin.ignore();

    getline(cin, name);

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].getName() == name)
        {

            students.erase((students.begin() + i));

            cout << "\t\tStudent Remove Successfully" << endl;
        }
    }
}

main()
{

    vector<Student> students;

    students.push_back(Student(1, "ali", 35));

    char choice;

    do
    {

        system("cls");

        int op;

        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t*** Student Management System ***";

        cout << "\n\t\t--------------------------------";

        cout << "\n\t\t 1. Add New Student" << endl;

        cout << "\t\t 2. Display All Student " << endl;

        cout << "\t\t 3. Search Student" << endl;

        cout << "\t\t 4. Update Student" << endl;

        cout << "\t\t 5. Delete Student " << endl;

        cout << "\t\t 6. Exit" << endl;

        cout << "\t\t Enter Your Choice : ";

        cin >> op;

        switch (op)
        {

        case 1:

            addNewStudent(students);

            break;

        case 2:

            DisplayAllStudent(students);

            break;

        case 3:

            SearchStudent(students);

            break;

        case 4:

            updateStudent(students);

            break;

        case 5:

            deleteStudent(students);

            break;

        case 6:

            exit(1);

        default:

            cout << "\t\tInvalid Number " << endl;
        }

        cout << "\t\tDo You Want to Continue [Yes/No] ? :";

        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}
