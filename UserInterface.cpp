#include "Database.h"
#include "My_Stack/My_Stack.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
using namespace Records;

int displayMenu();
Class &doGetClass(Database &DB);
void doAddClass(Database &DB);
void doGraduate(Database &DB);
void doCurrent(Database &DB);
void doAddPupils(Database &DB);
void doRemovePupils(Database &DB);

int main(int argc, char **argv)
{
    // розміщення екземплярів класів у користувацькому стеку
    //MyStack<Database> DB_stack;
    //MyStack<Class> Class_stack;
    //Database *DatabasePtr = new Database; // екземпляр класу на купі
    //delete Database; // звільнення виділеної на купі пам'яті

    Database classDB; // екземпляр класу на стеку
    bool done = false;

    while (!done)
    {
        int selection = displayMenu();

        switch (selection)
        {
        case 1:
            doAddClass(classDB);
            break;
        case 2:
            doGraduate(classDB);
            break;
        case 3:
            doCurrent(classDB);
            break;
        case 4:
            doAddPupils(classDB);
            break;
        case 5:
            doRemovePupils(classDB);
            break;
        case 6:
            classDB.displayAll();
            break;
        case 7:
            classDB.displayGraduation();
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "An unknown command" << endl;
        }
    }
}

int displayMenu()
{
    int selection;

    cout << endl;
    cout << "Classroom Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Add a new current class" << endl;
    cout << "2) To make a class graduated" << endl;
    cout << "3) To make a class current" << endl;
    cout << "4) Add pupil(s) to the class" << endl;
    cout << "5) Remove pupil(s) from the class" << endl;
    cout << "6) List all classess" << endl;
    cout << "7) List all graduation classes" << endl;
    cout << "0) Quit" << endl
         << endl;
    cout << "---> ";

    cin >> selection;
    return selection;
}

Class &doGetClass(Database &DB)
{
    int selection;

    cout << "What information use to get a class:" << endl;
    cout << "1) Class ID" << endl;
    cout << "2) Studying year and class letter" << endl
         << endl;
    cout << "---> ";

    cin >> selection;

    switch (selection)
    {
    case 1:
        size_t classId;

        cout << "Class ID? ";
        cin >> classId;

        return DB.getClass(classId);

    case 2:
        size_t studyingYear;
        char classLetter;

        cout << "Studying year? ";
        cin >> studyingYear;
        cout << "Class letter? ";
        cin >> classLetter;

        return DB.getClass(studyingYear, classLetter);

    default:
        cerr << "An unknown command" << endl;

        throw exception();
    }
}

void doAddClass(Database &DB)
{
    size_t studyingYear;
    char classLetter;
    int classTypeId;
    size_t teacherId;
    int pupilsAmount;
    size_t creationYear;

    cout << "Studying year? ";
    cin >> studyingYear;
    cout << "Class letter? ";
    cin >> classLetter;
    cout << "Class Type Id? ";
    cin >> classTypeId;
    cout << "Teacher Id? ";
    cin >> teacherId;
    cout << "Pupils amount? ";
    cin >> pupilsAmount;
    cout << "Creation year? ";
    cin >> creationYear;
    cout << endl;

    try
    {
        Class theClass = DB.addClass(studyingYear, classLetter, classTypeId, teacherId, pupilsAmount, creationYear);
        cout << "Class with the following data has been added:" << endl;
        theClass.display();
    }
    catch (const exception &ex)
    {
        cerr << "Unable to add a new class" << endl;
    }
}

void doGraduate(Database &DB)
{
    try
    {
        Class &theClass = doGetClass(DB);
        if (theClass.getIsGraduated())
            cout << "Class has already been graduated" << endl;
        else
        {
            theClass.graduate();
            cout << "The class has been made graduated" << endl;
        }
    }
    catch (const exception &ex)
    {
        cerr << "Unable to make a class graduated" << endl;
    }
}

void doCurrent(Database &DB)
{
    try
    {
        Class &theClass = doGetClass(DB);
        if (!theClass.getIsGraduated())
            cout << "Class has already been current" << endl;
        else
        {
            theClass.enroll();
            cout << "The class has been made current" << endl;
        }
    }
    catch (const exception &ex)
    {
        cerr << "Unable to make a class current" << endl;
    }
}

void doAddPupils(Database &DB)
{
    try
    {
        int pupilsAmount;
        Class &theClass = doGetClass(DB);
        cout << "How many pupils to add? ";
        cin >> pupilsAmount;
        theClass.addPupils(pupilsAmount);
        cout << pupilsAmount << " pupils has been added" << endl;
        cout << "New pupils amount: " << theClass.getpupilsAmount() << endl;
    }
    catch (const exception &ex)
    {
        cerr << "Unable to add pupil(s)" << endl;
    }
}

void doRemovePupils(Database &DB)
{
    try
    {
        int pupilsAmount;
        Class &theClass = doGetClass(DB);
        cout << "How many pupils to delete? ";
        cin >> pupilsAmount;
        theClass.removePupils(pupilsAmount);
        cout << pupilsAmount << " pupils has been deleted" << endl;
        cout << "New pupils amount: " << theClass.getpupilsAmount() << endl;
    }
    catch (const exception &ex)
    {
        cerr << "Unable to delete pupil(s)" << endl;
    }
}