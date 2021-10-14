#include "Class.h"

#include <iostream>
#include <string>

using namespace std;

namespace Records
{
    Class::Class()
    {
        studyingYear = 0;
        classLetter = ' ';
        classId = 0;
        classTypeId = 0;
        teacherId = 0;
        pupilsAmount = -1;
        creationYear = 0;
        isGraduated = false;
    }

    void Class::addPupils(size_t addAmount)
    {
        setPupilsAmount(getpupilsAmount() + addAmount);
    }

    void Class::removePupils(size_t addAmount)
    {
        setPupilsAmount(getpupilsAmount() - addAmount);
    }

    void Class::graduate() 
    {
        isGraduated = true;
    }

    void Class::enroll()
    {
        isGraduated = false;
    }

    void Class::display()
    {
        cout << "Class: " << getStudyingYear() << "-" << getClassLetter() << endl;
        cout << "-------------------------" << endl;
        cout << (getIsGraduated() ? "Graduted class" : "Current class") << endl;
        cout << "Class ID: " << getClassId() << endl;
        cout << "Class type ID: " << getClassTypeId() << endl;
        cout << "Class teacher ID: " << getTeacherId() << endl;
        cout << "Pupils count: " << getpupilsAmount() << endl;
        cout << "Creation year: " << getCreationYear() << endl << endl;
    }

    // Accessors and setters
    void Class::setClassId(size_t classId)
    {
        this->classId = classId;
    }

    size_t Class::getClassId()
    {
        return classId;
    }

    void Class::setTeacherId(size_t teacherId)
    {
        this->teacherId = teacherId;
    }

    size_t Class::getTeacherId()
    {
        return teacherId;
    }

    void Class::setClassTypeId(size_t classTypeId)
    {
        this->classTypeId = classTypeId;
    }

    size_t Class::getClassTypeId()
    {
        return classTypeId;
    }

    void Class::setPupilsAmount(int pupilsAmount)
    {
        if (pupilsAmount > kMaxpupilsAmount)
        {
            cerr << "There can be no more " << kMaxpupilsAmount << " pupils in one class" << endl;
            throw exception();
        }
        else if (pupilsAmount < 0)
        {
            cerr << "Pupils count can't be less than 0" << endl;
            throw exception();
        }

        this->pupilsAmount = pupilsAmount;
    }

    int Class::getpupilsAmount()
    {
        return pupilsAmount;
    }

    void Class::setClassLetter(char classLetter)
    {
        this->classLetter = classLetter;
    }

    char Class::getClassLetter()
    {
        return classLetter;
    }

    void Class::setStudyingYear(size_t studyingYear)
    {
        if (studyingYear > kMaxStudyingYear)
        {
            cerr << "The year of study cannot be more than " << kMaxStudyingYear << endl;
            throw exception();
        }

        this->studyingYear = studyingYear;
    }

    size_t Class::getStudyingYear()
    {
        return studyingYear;
    }

    void Class::setCreationYear(size_t creationYear)
    {
        this->creationYear = creationYear;
    }

    size_t Class::getCreationYear()
    {
        return creationYear;
    }

    bool Class::getIsGraduated()
    {
        return isGraduated;
    }
}
