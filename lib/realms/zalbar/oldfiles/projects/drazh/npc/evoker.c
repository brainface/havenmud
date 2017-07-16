// by Dahaka
// Aug 2004

#include <lib.h>
#include "../drazh.h"

inherit LIB_LEADER;
void DoCombatSomething();


static void create() {
  ::create();
  SetKeyName("skirdrakl");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"skirdrakl","seer"}) );
  SetAdjectives( ({"seer","grey","master"}) );
  SetShort("Skirdrakl, Master of the Grey Seer Initiates");
  SetLong(
     "Skirdrakl is a skaven with light grey fur which is covered in grime and "
	   "matted to his small frame. A large scar cuts across his face going "
	   "through is left eye. Skirdrakl keeps to himself unless a young rogue "
	   "needs to be lesson in the mystic arts.");
  SetGender("male");
  SetRace("skaven");
  SetClass("evoker");
  SetSkill("dodge",1,1);
  SetLevel(55);
  SetMorality(-1800);
  SetSpellBook( ([
    "mesmer barrier" : 100,
    "distinergrate"  : 100,
	 ]) );
  SetAction(8, ({
     "!say do you need a lesson in the mystic arts.",
     "!sneer",
     "!mumble",
	 }) );
  SetCombatAction(50, (: DoCombatSomething() :) ); 
  SetInventory( ([ 
     V_OBJ + "a_knife"   : "wield knife",
     V_OBJ + "vest"      : "wear vest",
	   V_OBJ + "lpants"    : "wear pants",
	   V_OBJ + "grey_robe" : 
	     "wear robe on torso and left arm and left leg and right arm and right leg",
	   ]) );
}




void DoCombatSomething(){

	if (!random(10)) {
		int randnum = random(2);
		if (randnum == 0) { eventForce("speak Melchezidek will protect me.");}
		else { eventForce("yell Die!.");}
	}

	if ((sizeof(GetMagicProtection())) < 2) {
		eventForce("cast mesmer barrier");
		return;
    }

	if (GetMagicPoints() > (GetMaxMagicPoints()/6)) {
		eventForce("cast disintergrate");
	}
	
	return;
}

void eventJoin(object who, string args) {
  if (!(who->GetClass("rogue"))) { 
          eventForce("speak I only teach the ways of the evoker "
            "to those who have already begun their careers as "
            "a rogue.");
  return;
  }
  return leader::eventJoin(who, args);
}