#ifndef COMPARATOR_H
#define COMPARATOR_H

#include "Student.h"

class StudentIdComparator {
public:
    bool isLessThan(const Student& s1, const Student& s2) const {
        return s1.getId() < s2.getId();
    }
};

class StudentNameComparator {
public:
    bool isLessThan(const Student& s1, const Student& s2) const {
        if (s1.getLastName() != s2.getLastName()) {
            return s1.getLastName() < s2.getLastName();
        }
        return s1.getFirstName() < s2.getFirstName();
    }
};

#endif //COMPARATOR_H