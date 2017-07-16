/*
 *    /lib/styleteacher.c
 *    Coded by Gabriel@Haven 12/01/99
 *    Version 1.0
 */
 
#include <lib.h>
#include <daemons.h>
#include "include/styleteacher.h"
 
inherit LIB_SENTIENT;
 
private string array TrainingStyles = ({ });
private mapping Students;
int Charge = 5000;
int Tp = 2;
string LocalCurrency = "imperials";
 
/**** driver applies ****/
 
static void create() 
{
  sentient::create();
  TrainingStyles = ({});   
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
 
int SetCharge(int amount) {
  return (Charge = amount);
  }

int GetCharge() {
  return Charge;
  }

int SetTp(int amount) {
  return (Tp = amount);
  }

int GetTp() {
  return Tp;
  }

string SetLocalCurrency(string cur) {
  return (LocalCurrency = cur);
  }

string GetLocalCurrency() {
  return (LocalCurrency);
  }

mixed AddTrainingStyles(string *args...) 
{
  if (!args) return TrainingStyles;
  if (!arrayp(args)) args = ({ args });
  return (TrainingStyles += args);
}
 
mixed RemoveTrainingStyles(string *args...) 
{
  if( !args || !arrayp(args) ) 
    error("Bad argument 1 to RemoveTrainingStyles.");
  TrainingStyles -= args;
  return TrainingStyles;
}
 
string array GetTrainingStyles() 
{
  return TrainingStyles;
}
 
mapping GetStudents() { return copy(Students); }
 
/**** high-level events ****/
 
int eventHelp(object who, string unused) 
{
  eventForce("speak I am not sure of what you are "
    "asking " + (string)this_player()->GetName() + ".");
  eventForce("speak I mainly teach people "+conjunction(GetTrainingStyles())+
    ".");
  eventForce("speak You can \"ask "+GetKeyName()+" to train "
    "<STYLE>\" if you have training points and money.");
  return 1;
}
 
int eventTrain(object who, string verb, string style) 
{
  if( !who || environment(who) != environment() ) 
  {
    return 0;
  }
  if( !sizeof(style) || !sizeof(verb) ) return eventHelp(who, 0);
  if( verb == "train" ) 
  {
    style = lower_case(style);
    if( creatorp(who) ) 
    {
      who->eventPrint("Creators do not get styles, get a life.");
      return 0;
    }
    if( Students[ (string)who->GetKeyName() ] ) 
    {
      eventForce("speak I am already training you!");
      return 0;
    }
    if( member_array(style, TrainingStyles) == -1 ) 
    {
      eventForce("speak I know nothing about the art of " + style + ".");
      return 0;
    }
    if( member_array(style, 
      (string *)this_player()->GetCombatStyles() ) == -1 ) 
    {
      eventForce("speak You do not appear to be the type "
        "who would be skilled in " + style + "!");
      return 0;
    }
    if (who->GetCurrency(GetLocalCurrency()) < GetCharge()) 
    {
      eventForce("speak You don't have enough money.");
      eventForce("speak I charge " + GetCharge() + 
        " " + GetLocalCurrency() + " per class.");
      return 0;
    }
    if( (int)this_player()->GetTrainingPoints() < 2 ) 
    {
      eventForce("speak Fool! You need training points for that!");        
      return 0;
    }
    if( (int)this_player()->GetCombatStyleLevel(style) > 100 ) 
    {
      eventForce("speak How far do you think you can train that?");        
      return 0;
    }
    if (GetInCombat()) 
    {
      eventForce("speak I am rather tied up right now.");
      return 0;
    }
    Students[ (string)who->GetKeyName() ] = style;
    eventStart(who, style);
    call_out((: ContinueTraining, who, style, 0 :), TRAINING_WAIT);
    return 1;
  }
}
 
static int ContinueTraining(object who, string style, int x) 
{
  if( !present(who, environment()) ) return 0;
  if( !Students[(string)who->GetKeyName()] ) return 0;
  if( x > 4 ) 
  {
    map_delete(Students, (string)who->GetKeyName());
    eventComplete(who, style);
    who->SetCombatStyle(style, ((who->GetCombatStyleLevel(style))) + 1);
    who->AddCurrency(GetLocalCurrency(), -(GetCharge()));
    who->AddTrainingPoints(-(GetTp()));
    return 1;
  } 
  else 
  {
    eventContinue(who, style, ++x);
    call_out((: ContinueTraining, who, style, x :), TRAINING_WAIT);
    return 1;
  }
}
 
/**** message handling events ****/
 
/*  The three following events are purely *aesthetic*,
 *  Hopefully prolific coders will override them for  
 *  more interesting training techniques. :) 
 */
 
int eventStart(object who, string style) 
{
  who->eventPrint(GetName() + " begins teaching you about " + style + ".");
  environment()->eventPrint(GetName() + " begins teaching " +
    (string)who->GetName() + "...", who);
  return 1;
}
 
int eventContinue(object who, string style, int x) 
{
  who->eventPrint("You listen intently as " + GetName()
    + " continues " + possessive(this_object())
    + " dissertation on " + style + ".");
  return 1;
}
 
int eventComplete(object who, string style) 
{
  who->eventPrint("You feel more adept with your " + style + ".");
  eventForce("speak I can teach you no more for now, " +
    (string)who->GetName() + ".");
  return 1;
}

