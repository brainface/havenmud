#ifndef l_classes_h
#define l_classes_h

class Skill {
    int SkillClass;
    int Average;
}

class Class {
    int Complete;
    mapping Multis;
    mapping Skills;
}

varargs string *GetClasses();
#endif /* l_classes_h */
