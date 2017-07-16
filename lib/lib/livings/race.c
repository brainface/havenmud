/*    /lib/race.c
 *    from the Dead Souls LPC Library
 *    handles all race specific management
 *    created by Descartes of Borg 950122
 *    Version: @(#) race.c 1.8@(#)
 *    Last modified: 96/11/11
 */

#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <armour_types.h>
#include <damage_types.h>
#include <meal_types.h>
#include <size.h>
#include "include/race.h"

inherit LIB_BODY;
inherit LIB_GENETICS;
inherit LIB_LANGUAGE;
inherit LIB_TALK;

private string Town, Race, Gender, Nationality;
private int Size;

// abstract methods
int GetParalyzed();
void eventForce(string);
// end abstract methods

static void create() {
    body::create();
    talk::create();
    genetics::create();
    Race = "essence";
    Gender = "neuter";
    Town = "Wilderness";
    Nationality = 0;
    Size = SIZE_MEDIUM;
}

mixed CanDrink(object ob) {
    int strength, type;

    if( !ob ) return 0;
    strength = (int)ob->GetStrength();
    type = (int)ob->GetMealType();
    if( (type & MEAL_ALCOHOL) && (GetStatLevel("durability") < GetAlcohol()) )
      return "That drink is too strong for your feeble durability right now.";
    if( (type & MEAL_CAFFEINE) && (GetStatLevel("durability") < GetCaffeine()))
      return "Any more caffeine and your heart will burst.";
    if( (type & MEAL_DRINK) && (GetDrink() > 500) )
      return "You are too bloated to drink any more!";
    return 1;
}

mixed CanSmoke(object ob) {
    int strength, type;

    if( !ob ) return 0;
    strength = (int)ob->GetStrength();
    type = (int)ob->GetMealType();
    if( (type & MEAL_ALCOHOL) && (GetStatLevel("durability") < GetAlcohol()) )
      return "You are way too stoned to handle another smoke.";
    if( (type & MEAL_CAFFEINE) && (GetStatLevel("durability") < GetCaffeine()))
      return "Any more caffeine and your heart will burst.";
    if (GetSmoke() > 100) 
      return "Your lungs rebel at the idea of smoking more.";
    return 1;
}

mixed CanEat(object ob) {
    int type;
    if (!ob) return 0;
    type = ob->GetMealType();
    if(GetFood() > 500 )
      return "One more bite, and you would explode!";
    if( (type & MEAL_ALCOHOL) && (GetStatLevel("durability") < GetAlcohol()) )
      return "You are way too stoned to handle another smoke.";
    if( (type & MEAL_CAFFEINE) && (GetStatLevel("durability") < GetCaffeine()))
      return "Any more caffeine and your heart will burst.";
    return 1;
}

varargs int eventDie(object agent) {
    int x;
    if (agent) { if (GetTown() != "Wilderness" && GetTown() != "all") agent->AddReputation(GetTown(), -2); }
    if( (x = body::eventDie(agent)) != 1 ) return x;
    return 1;
}

mixed eventDrink(object ob) {
    int type, strength;

    type = (int)ob->GetMealType();
    strength = (int)ob->GetStrength();
    if( type & MEAL_POISON ) AddPoison(strength);
    if( type & MEAL_DRINK ) AddDrink(strength);
    if( type & MEAL_ALCOHOL ) {
    	AddAlcohol(strength);
    	AddMagicPoints(strength);
    	}
    if( type & MEAL_CAFFEINE ) { AddCaffeine(strength); AddRecoveryTime(-strength); }
    return 1;
}

mixed eventSmoke(object ob) {
    int type, strength;

    type = (int)ob->GetMealType();
    strength = (int)ob->GetStrength();
    if( type & MEAL_POISON ) AddPoison(strength);
    if( type & MEAL_ALCOHOL ) AddAlcohol(strength);
   	if( type & MEAL_CAFFEINE ) { AddCaffeine(strength); AddRecoveryTime(-strength); }
   	AddMagicPoints(strength);
   	AddStaminaPoints(strength);
    AddSmoke(strength);
    return 1;
}

mixed eventEat(object ob) {
    int type, strength;

    type = (int)ob->GetMealType();
    strength = (int)ob->GetStrength();
    if( type & MEAL_POISON ) AddPoison(strength);
    if( type & MEAL_FOOD ) AddFood(strength);
    if( type & MEAL_ALCOHOL ) {
    	AddAlcohol(strength);
    	AddMagicPoints(strength);
    	}
    if( type & MEAL_CAFFEINE ) { AddCaffeine(strength); AddRecoveryTime(-strength); }
    eventHealDamage(strength/2);
    return 1;
}

int SetSize(int x) { return Size = x; }

int GetSize() { return Size; }

varargs string SetRace(string race, mixed extra) {
    mixed array args = ({ ({}), ({}), ({}), ({}), ({}) });
    mixed array tmp;
    
    if (member_array(race, RACES_D->GetRaces()) == -1 && extra != 1) {
       CHAT_D->eventSendChannel("RACES_D", "error",
          "Bad Race: " + race + " in object " + base_name(this_object()) );
       race = "rodent";
    }
    RACES_D->SetCharacterRace(race, args);
    foreach(tmp in args[0]) SetResistance(tmp...);
    foreach(tmp in args[1]) AddStat(tmp...);
    if( stringp(args[2]) ) SetLanguage(args[2], 100, 1);
    if( sizeof(args[3]) == 2 ) SetLightSensitivity(args[3]...);
    if (sizeof(args[4]) == 1) SetSize(args[4][0]);
    if( extra != 1 ) NewBody(race);
    if( stringp(extra) ) return (Race = extra), race; 
    else return (Race = race);
}

string GetRace() { return Race; }

string SetGender(string gender) { return (Gender = gender); }

string GetGender() { return Gender; }

varargs void SetStat(string stat, int level, int classes) {
    int healthPoints;

    genetics::SetStat(stat, level, classes);
    switch(stat) {
        case "durability":
            eventCompleteHeal(healthPoints = GetMaxHealthPoints());
            eventHealDamage(healthPoints);
            break;
        case "intelligence":
            AddMagicPoints(GetMaxMagicPoints());
            break;
        case "agility":
            AddStaminaPoints(GetMaxStaminaPoints());
            break;
    }
}

varargs int GetMaxHealthPoints(string limb) {
    if(!limb) return ( 50 + (GetStatLevel("durability") * 10) );
    else {
        int x;

        x = GetLimbClass(limb);
        if(!x) x = 5;
        return ( (1 + GetStatLevel("durability")/x) * 10 );
    }
}

int GetMaxMagicPoints() {
   int divider = 0;
   int MP = 0;
   int bonus;
   foreach(object eq in GetUniqueWorn()) {
      bonus += eq->GetMagicBonus();
      }
   if (GetSkillLevel("faith")) {
    MP += (50 + GetStatLevel("wisdom") * 10);
    divider++;
    }
   if (GetSkillLevel("natural magic")) {
    MP += (50 + GetStatLevel("wisdom") * 10);
    divider++;
    }
   if (GetSkillLevel("vocal music") || GetSkillLevel("instrumental music") ) {
    MP += (50 + GetStatLevel("charisma") * 10);
    divider++;
    }
   if (GetSkillLevel("conjuring")) {
    MP += ( 50 + (GetStatLevel("intelligence") * 10) );
    divider++;
   }
   if (!divider) return 50;
   return (MP/divider) + bonus;
}

float GetMaxStaminaPoints() {
    return (50.0 + (GetStatLevel("strength") * 10.0) );
}

void NewBody(string race) {
    mixed array args = allocate(2);
    mixed array tmp;
    
    body::NewBody(race);
    if(!race) return;
    RACES_D->SetCharacterLimbs(race, args);
    foreach(tmp in args[0]) AddLimb(tmp...);
    foreach(tmp in args[1]) AddFingers(tmp...);
}

string SetTown(string str) { return (Town = str); }

string GetTown() { return Town; }

string SetNationality(string n) { return Nationality = n; }

string GetNationality() { return Nationality; }

string GetResistance(int type) { return genetics::GetResistance(type); }

int GetLuck() {
    int x;

    x = random(GetStatLevel("luck")) / 10;
    x = ((x > 10) ? 10 : x);
   return (x + random(4));
}

int GetMobility() {
   int max = GetMaxCarry();
   int encum, mob;

   if( GetParalyzed() ) {
       return 0;
   }
   if( max < 1 ) {
       max = 1;
   }
   encum = (GetCarriedMass() * 100)/max;
   encum -= (encum * GetStatLevel("agility"))/200;
   mob = 100 - encum;
   if( mob > 100 ) {
       mob = 100;
   }
   else if( mob < 1 ) {
       mob = 0;
   }
   return mob;
}

int GetCarriedMass() { return 0; }

int GetMaxCarry() { return ((2 + GetStatLevel("strength")) * 100); }

int GetHeartRate() {
    int x, y;

    x = body::GetHeartRate();
    y = GetStatLevel("agility");
    if( y > 80 ) x -= 2;
    else if( y > 60 ) x -= 1;
    else if( y > 40 ) x = x;
    else if( y > 20 ) x += 1;
    else x += 2;
    if( x > 6 ) x = 6;
    else if( x < 2 ) x = 2;
    return x;
}


int GetWarmth() {
  int x = ::GetWarmth();
  if (Race == "goden") x += 10;
  if (Race == "muezzin") x +=10;
  return x;
}
int GetStatLevel(string stat) { return genetics::GetStatLevel(stat); }

int GetAlcohol() { return body::GetAlcohol(); }

static void heart_beat() {
    body::heart_beat();
    language::heart_beat();
    genetics::heart_beat();
    if (GetWarmth() < 30 && !GetUndead()) {
    	eventPrint("You shiver with cold.");
        if (!newbiep())
    	eventReceiveDamage(load_object(STD_DUMMY "temperature"), COLD, random(30 - GetWarmth()), 1);
    }
    if (GetWarmth() > 180  && !GetUndead()) {
    	eventForce("pant");
    	eventPrint("You are extremely hot.");
        if (!newbiep())
    	eventReceiveDamage(load_object(STD_DUMMY "temperature"), HEAT, random(GetWarmth() - 180), 1);
    	AddDrink(-5);
    	}
}

mixed *AddSave(mixed *vars) { 
  return talk::AddSave(vars);
}
