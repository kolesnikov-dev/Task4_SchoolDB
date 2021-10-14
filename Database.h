#include "Class.h"

#include <iostream>

namespace Records
{
    const int kMaxClassesAmount = 100;
    const int kFirstClassId = 10;
    
    class Database
    {
    public:
        Database();
        Class &addClass(size_t studuingYear, char classLetter, int classTypeId, size_t teacherId, int pupilsAmount, size_t creationYear);
        Class &getClass(size_t classId);
        Class &getClass(size_t studyingYear, char classLetter);

        void displayAll();
        void displayGraduation();

    protected:
        Class Classes[kMaxClassesAmount];
        int nextSlot;
        int nextClassId;
    };
}
