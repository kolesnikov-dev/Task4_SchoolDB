#include "Database.h"

using namespace std;

namespace Records
{
    Database::Database()
    {
        nextSlot = 0;
        nextClassId = kFirstClassId;
    }

    Class &Database::addClass(size_t studyingYear, char classLetter, int classTypeId, size_t teacherId, int pupilsAmount, size_t creationYear)
    {
        if (nextSlot >= kMaxClassesAmount)
        {
            cerr << "More classes can't be added" << endl;
            throw exception();
        }

        Class theClass;
        theClass.setStudyingYear(studyingYear);
        theClass.setClassLetter(classLetter);
        theClass.setClassTypeId(classTypeId);
        theClass.setTeacherId(teacherId);
        theClass.setPupilsAmount(pupilsAmount);
        theClass.setCreationYear(creationYear);
        theClass.setClassId(nextClassId++);

        Classes[nextSlot] = theClass;

        return Classes[nextSlot++];
    }

    Class &Database::getClass(size_t classId)
    {
        for (int i = 0; i < nextSlot; ++i)
        {
            if (Classes[i].getClassId() == classId)
            {
                return Classes[i];
            }
        }
        cerr << "No match with ID " << classId << endl;
        throw exception();
    }

    Class &Database::getClass(size_t studyingYear, char classLetter)
    {
        for (int i = 0; i < nextSlot; ++i)
        {
            if (Classes[i].getStudyingYear() == studyingYear &&
                Classes[i].getClassLetter() == classLetter)
            {
                return Classes[i];
            }
        }
        cerr << "No match with studying year " << studyingYear << " and class letter " << classLetter << endl;
        throw exception();
    }

    void Database::displayAll()
    {
        if (nextSlot != 0)
        {
            for (int i = 0; i < nextSlot; ++i)
            {
                Classes[i].display();
            }
        }
        else
            cout << "There is no any classes" << endl;
    }

    void Database::displayGraduation()
    {
        if (nextSlot != 0)
        {
            bool isAnyGraduated = false;
            for (int i = 0; i < nextSlot; ++i)
            {
                if (Classes[i].getIsGraduated())
                {
                    isAnyGraduated = true;
                    Classes[i].display();
                }
            }

            if (!isAnyGraduated)
                cout << "There is no any graduated class" << endl;
        }
        else
            cout << "There is no any classes" << endl;
    }
}