#include <iostream>

namespace Records
{
    const size_t kMaxpupilsAmount = 20;
    const size_t kMaxStudyingYear = 11;

    class Class
    {
    public:
        Class();

        void addPupils(size_t addAmount = 1); // append the pupil
        void removePupils(size_t addAmount = 1); // dismisses the pupil
        void graduate(); // to make the class graduated
        void enroll(); // to make the class current
        void display(); // outputs pupil info to the console

        // Accessors and setters
        void setClassId(size_t);
        size_t getClassId();
        void setTeacherId(size_t);
        size_t getTeacherId();
        void setClassTypeId(size_t);
        size_t getClassTypeId();
        void setPupilsAmount(int);
        int getpupilsAmount();
        void setClassLetter(char);
        char getClassLetter();
        void setStudyingYear(size_t);
        size_t getStudyingYear();
        void setCreationYear(size_t);
        size_t getCreationYear();
        bool getIsGraduated();

    private:
        size_t classId;
        size_t teacherId;
        size_t classTypeId;
        int pupilsAmount;
        char classLetter;
        size_t studyingYear;
        size_t creationYear;
        bool isGraduated;
    };
}
