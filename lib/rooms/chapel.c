/*    /lib/chapel.c
 *    from the Nightmare IVr3 Object Library
 *    allows people to marry
 *    created by Descartes of Borg 951210
 *    Version: @(#) chapel.c 1.2@(#)
 *    Last modified: 96/10/09
 */

#include <lib.h>
#include <daemons.h>
#include "include/chapel.h"

inherit LIB_ROOM;

private int AllowSacrifice, SacrificeType;
private string array Classes, Deities, DeityIds;
private string *Religion;

/*     **********  /lib/chapel.c apply methods  **********     */
static void create() {
    room::create();
    Classes = ({});
    Religion = ({ });
    Deities = ({});
    DeityIds = ({});
    AllowSacrifice = 0;
    SacrificeType = 0;
    set_heart_beat(30);
}

/*     **********  /lib/chapel.c modal methods  **********     */
mixed CanMarry(object who, object spouse1, object spouse2) {
    mixed tmp;
    string cls;

    if( (tmp = spouse1->CanMarry(who, spouse2)) != 1 ) {
	if( tmp ) return tmp;
	else return (string)spouse1->GetName() + " cannot be married.";
    }
    if( (tmp = spouse2->CanMarry(who, spouse1)) != 1 ) {
	if( tmp ) return tmp;
	else return (string)spouse2->GetName() + " cannot be married.";
    }
  if( immortalp(who) ) return 1;
  if (member_array(who->GetReligion(1), GetReligion()) != -1) 
	   return 1;
	return "You are not allowed to perform marriages here.";
}

mixed CanSacrifice(object who, object what, string deus) {
    if( (string)who->GetReligion(1) != Religion[1] )
      return "You must hold the beliefs of " + Religion[1] + " to do that.";
    if( !((int)what->GetVendorType() & SacrificeType) )
      return "You cannot sacrifice that here.";
    if( member_array(deus, DeityIds) == -1 )
      return "You do not worship anything called \"" + deus + "\".";
    return AllowSacrifice;
}

mixed eventMarry(object who, object spouse1, object spouse2) {
    mixed tmp;

    if( (tmp = spouse1->eventMarry(who, spouse2)) != 1 ) return tmp;
    if( (tmp = spouse2->eventMarry(who, spouse1)) != 1 ) {
	spouse1->SetMarried(0);
	return tmp;
    }
   spouse1->eventPrint((string)who->GetName() + " weds you to " +
		       (string)spouse2->GetName() + ".");
   spouse2->eventPrint((string)who->GetName() + " weds you to " +
		       (string)spouse1->GetName() + ".");
   who->eventPrint("You join " + (string)spouse1->GetName() + " to " +
		   (string)spouse2->GetName() + " in marriage.");
   this_object()->eventPrint((string)who->GetName() + " joins " +
			     (string)spouse1->GetName() + " and " +
			     (string)spouse2->GetName() + ".",
			     ({ spouse1, spouse2, who }));
   who->AddSkillPoints("faith", random(100));
   return 1;
}

mixed eventSacrifice(object who, object what, string deus) {
    who->eventPrint("You attempt to make a sacrifice, but nothing happens.");
    return 1;
}

/*     **********  /lib/chapel.c event methods  **********     */
int SetAllowSacrifice(int x) { return (AllowSacrifice = x); }

int GetAllowSacrifice() { return AllowSacrifice; }

string *SetClasses(string *rc) { return (Classes = rc); }

string *GetClasses() { return Classes; }

string *SetDeities(string *deities) {
    string *ids = ({});
    
    Deities = deities;
    foreach(string deus in deities)
      ids += explode(lower_case(deus), " ");
    DeityIds = ids;
    return Deities;
}

string *GetDeities() { return Deities; }

string *SetReligion(string *args...) {
  if (arrayp(args)) Religion = args;
    else Religion += args;
  return Religion = distinct_array(Religion);
}

varargs string *GetReligion(int flag) { return Religion; }

int SetSacrificeType(int x) { return (SacrificeType = x); }

int AddSacrificeType(int x) { return (SacrificeType |= x); }

int GetSacrificeType() { return SacrificeType; }

void heart_beat(int reset) {
  string religion;
  string religion_morality;
  int directional;
  object *players = ({ });

  foreach(string rel in Religion) {
  religion_morality = MORALITY_D->GetReligionAlignment(rel);
  if (religion_morality == "good") directional = 1;
  if (religion_morality == "evil") directional = -1;
  if (religion_morality == "neutral") directional = 0;
  players = all_inventory(this_object());
  players = filter( players, (: playerp :) );
  foreach(object p in players) {
    if (p->GetReligion() == rel) {
      if (directional == 1) {
        p->eventMoralAct(100);
        }
      if (directional == -1) {
        p->eventMoralAct(-100);
        }
      if (directional == 0) {
        if (p->GetMorality() > 0) p->eventMoralAct(-100);
        if (p->GetMorality() < 0) p->eventMoralAct(100);
        if (abs(p->GetMorality()) < 100) p->eventMoralAct( -1 * p->GetMorality() );
        }
      }
    }
  }
  ::heart_beat(reset);
}
