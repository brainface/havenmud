/*    /lib/classes.c
 *    from the Nightmare IV LPC Library
 *    classes and guild handling object
 *    created by Descartes of Borg 950123
 *    Version: @(#) classes.c 1.3@(#)
 *    Last modified: 96/10/17
 */

#include <lib.h>
#include <daemons.h>
#include "include/classes.h"

inherit LIB_ABILITIES;

private int Morality;
private int CanMulti;
private string Class, Guild, Clan;
private mapping SkillModifiers;
private string *Religion = ({ "agnostic", "agnostic" });

static void create() {
    abilities::create();
    SkillModifiers = ([]);
    Class = 0;
    Guild = 0;
    Clan = 0;
    Morality = 0;
    CanMulti = 1;
}

int eventMoralAct(int degree) {
    if (Morality >  500 && degree >  50) degree =  50;
    if (Morality < -500 && degree < -50) degree = -50;  
    if (degree >  100) degree =  100;
    if (degree < -100) degree = -100;
    Morality += degree;
    if( Morality >  2500 ) Morality =  2500;
    if( Morality < -2500 ) Morality = -2500;
    return Morality;
}


static string SetSkillModifier(string skill, string stat) {
    if(!GetSkill(skill)) return 0;
    else return (SkillModifiers[skill] = stat);
}

string GetSkillModifier(string skill) { return SkillModifiers[skill]; }

string RemoveClass() {
  foreach(string skill in GetSkills()) {
     RemoveSkill(skill);
    }
  foreach(string title in GetTitles() ) {
     RemoveTitle(title);
    }
  foreach(string spell in keys(GetSpellBook())) {
      eventForgetSpell(spell);
    }
  AddDevelopmentPoints(-GetDevelopmentPoints());
  return (Class = 0);
  }

string SetClass(string class_name) {
    mixed array args = allocate(3);
    mixed array tmp;
    
    CLASSES_D->SetClass(class_name, args);
    if( Class ) {
	string multi;

	if( !args[0] ) { // No such secondary class
	    return Class;
        }
        multi = args[0][Class];
	if( !multi ) { // Can't multi-class in this combo
	    return Class;
	}
	class_name = multi;
    }
	if( !args[0] ) { // No such class
	    return Class;
	}
	if (userp(this_object())) {
	foreach(tmp in args[2]) { // Other Skills
	    if (GetSkillLevel(tmp[0])) continue;
	    SetSkill(tmp...);
	}
    foreach(tmp in args[1]) { // Primes
    string sk; int b;
    sk = tmp[0]; 
    if (b = GetSkillLevel(sk)) {
    	SetSkill(sk, b, 1); 
    	} else { SetSkill(tmp...); }
    }
  }
  if (!userp(this_object())) {
    foreach(tmp in args[2]) { // Other Skills
	    SetSkill(tmp...);
	    }
    foreach(tmp in args[1]) { // Primes
     SetSkill(tmp...); 
     }
  }
    return (Class = class_name);
}

string GetClass() { return Class; }

int ClassMember(mixed class_name) {
  if (!arrayp(class_name)) class_name = ({ class_name });
  foreach(string c in class_name) {
    if (CLASSES_D->ClassMember(Class, c)) return 1;
  }
  return 0;
}

string SetGuild(string guild) { return (Guild = guild); }

string GetGuild() { return Guild; }

string SetClan(string clan) {
  return (Clan = clan);
  }

string GetClan() { return (Clan); }
int GetBaseStatLevel(string stat) { return 0; }

int SetMorality(int x) { return (Morality = x); }

int GetMorality() { return Morality; }

varargs string GetMoralityDescription(int modifier) {
    string str;
    int x;

    x = GetMorality();
    x += modifier;
    if( x > 2000 ) str = "saintly";
    else if( x > 1500 ) str = "pious";
    else if( x > 1000 ) str = "benevolent";
    else if( x > 700 ) str = "good";
    else if( x > 450 ) str = "friendly";
    else if( x >= 200 ) str = "nice";
    else if( x > -200 ) str = "neutral";
    else if( x > -450 ) str = "mean";
    else if( x > -700 ) str = "cruel";
    else if( x > -1000 ) str = "wicked";
    else if( x > -1500 ) str = "vicious";
    else if( x > -2000 ) str = "malevolent";
    else str = "demonic";
    return str;
}

varargs string *SetReligion(mixed str...) {
  if (stringp(str)) {
    Religion[0] = str;
    Religion[1] = str;
    }
  if (arrayp(str)) {
   if (stringp(str[0])) {
      Religion[0] = str[0];
      Religion[1] = str[0];
    }
  else {
    Religion = str[0];
    }
  }
  return Religion;
}

varargs string GetReligion(int flag) {
  if (sizeof(Religion) < flag + 1) return Religion[0];
  else return Religion[flag];
  }

int SetNoMulti(int x) {
   return (CanMulti = !x);
   }

int GetMultiAllowed() {
   return (CanMulti);
  }
