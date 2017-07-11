#ifndef __trainer_h__
#define __trainer_h__
 
static void create();
static void init();
 
mixed AddTrainingSkills(string);
mixed RemoveTrainingSkills(string);
mapping SetTrainingSkills(mapping);
string *GetTrainingSkills();
mapping GetStudents();
 
int eventHelp(object who, string unused);
int eventTrain(object who, string verb, string skill);
 

#define TRAINING_WAIT 10
#endif __trainer_h__
