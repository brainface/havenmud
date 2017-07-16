/*
 *    /lib/statteacher.c
 *    Coded by Gabriel@Haven 11/15/99
 *    Version 1.0
 */
 
#include <lib.h>
#include <daemons.h>
#include "include/statteacher.h"
 
inherit LIB_SENTIENT;
 
private string array TrainingStats = ({ });
private mapping Students;
 
/**** driver applies ****/
 
static void create() 
{
  sentient::create();
  TrainingStats = ({});   
  Students = ([]);
  SetNoClean(1);
  SetCommandResponses( ([
    ({ "train", "teach" }) : (: eventTrain :),
    "default" : (: eventHelp :),
  ]) );
}
 
static void init() 
{
  string str;
  ::init();
  if( !living(this_player()) ) return;
  str = (string)this_player()->GetKeyName();
  if( Students[str] ) 
  {
    eventForce("speak You will have to start your "             
      "studies anew, "+(string)this_player()->GetName());
    map_delete(Students, str);
  }
}
 
/**** data manipulation ****/
 
mixed AddTrainingStats(string *args...) 
{
  if (!args) return TrainingStats;
  if (!arrayp(args)) args = ({ args });
  return (TrainingStats += args);
}
 
mixed RemoveTrainingStats(string *args...) 
{
  if( !args || !arrayp(args) ) 
    error("Bad argument 1 to RemoveTrainingStats.");
  TrainingStats -= args;
  return TrainingStats;
}
 
string array GetTrainingStats() 
{
  return TrainingStats;
}
 
mapping GetStudents() { return copy(Students); }
 
/**** high-level events ****/
 
int eventHelp(object who, string unused) 
{
  eventForce("speak I am not sure of what you are "
    "asking " + (string)this_player()->GetName() + ".");
  eventForce("speak I mainly teach people "+conjunction(GetTrainingStats())+
    ".");
  eventForce("speak You can \"ask "+GetKeyName()+" to train "
    "<STAT>\" if you have training points.");
  return 1;
}
 
 int eventTrain(object who, string verb, string stat) 
{
  if( !who || environment(who) != environment() ) 
  {
    return 0;
  }
  if( !sizeof(stat) || !sizeof(verb) ) return eventHelp(who, 0);
  if( verb == "train" ) 
  {
    stat = lower_case(stat);
    if( creatorp(who) ) 
    {
      who->eventPrint("Creators do not have stats, get a life.");
      return 1;
    }
    if( Students[ (string)who->GetKeyName() ] ) 
    {
      eventForce("speak I am already training you!");
      return 0;
    }
    if( member_array(stat, TrainingStats) == -1 ) 
    {
      eventForce("speak I know nothing about the art of " + stat + ".");
      return 0;
    }
    if( member_array(stat, 
      (string *)this_player()->GetStats() ) == -1 ) 
    {
      eventForce("speak You do not appear to be the type "
        "who would be skilled in " + stat + "!");
      return 0;
    }
    if( (int)this_player()->GetTrainingPoints() < 200 ) 
    {
      eventForce("speak Fool! You need training points for that!");        
      return 0;
    }
    if( (int)this_player()->GetStatClass(stat) < 2 ) 
    {
      eventForce("speak How far do you think you can train that?");        
      return 0;
    }
    if (GetInCombat()) 
    {
      eventForce("speak I am rather tied up right now.");
      return 0;
    }
    Students[ (string)who->GetKeyName() ] = stat;
    eventStart(who, stat);
    call_out((: ContinueTraining, who, stat, 0 :), TRAINING_WAIT);
    return 1;
  }
}
 
static int ContinueTraining(object who, string stat, int x) 
{
  if( !present(who, environment()) ) return 0;
  if( !Students[(string)who->GetKeyName()] ) return 0;
  if( x > 4 ) 
  {
    map_delete(Students, (string)who->GetKeyName());
    eventComplete(who, stat);
    who->SetStat(stat, (who->GetStatLevel(stat)), ((who->GetStatClass(stat))-1));
    who->AddTrainingPoints(-200);
    return 1;
  } 
  else 
  {
    eventContinue(who, stat, ++x);
    call_out((: ContinueTraining, who, stat, x :), TRAINING_WAIT);
    return 1;
  }
}
 
/**** message handling events ****/
 
/*  The three following events are purely *aesthetic*,
 *  Hopefully prolific coders will override them for  
 *  more interesting training techniques. :) 
 */
 
int eventStart(object who, string stat) 
{
  who->eventPrint(GetName() + " begins teaching you about " + stat + ".");
  environment()->eventPrint(GetName() + " begins teaching " +
    (string)who->GetName() + "...", who);
  return 1;
}
 
int eventContinue(object who, string stat, int x) 
{
  who->eventPrint("You listen intently as " + GetName()
    + " continues " + possessive(this_object())
    + " dissertation on " + stat + ".");
  return 1;
}
 
int eventComplete(object who, string stat) 
{
  who->eventPrint("You feel more adept with your " + stat + ".");
  eventForce("speak I can teach you no more for now, " +
    (string)who->GetName() + ".");
  return 1;
}
