#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include "../cata.h"
inherit LIB_NPC;
 
static void create() {
string weap;

  ::create();
  SetKeyName("lich");
  SetShort("a plague-bearing lich");
  SetAdjectives( ({ "plague-bearing" }) );
  SetId( ({ "lich","cata_npc","plague-bearer" }) );
  SetLong("Years ago a fanatical sect of Thorian"
          " priests set out to prolong their stay on"
          " Kailie. Their experimentation resulted in"
          " the ability to transform themselves into"
          " liches, dramatically increasing their"
          " lifespan. The result is what you see"
          " before you: a walking, talking, conscious"
          " undead being.");
  switch(random(3)) {
    case 0:
     SetRace("half-elf");
     break;
    case 1:
     SetRace("lamrani");
     break;
    case 2:
     SetRace("human");
     break;
    }
  SetClass("priest");
  SetSkill("poison magic",1,1);
  SetSkill("knife combat",1,1);
  SetSkill("slash combat",1,1);
  SetSkill("pole combat",1,1);
  SetSkill("melee combat",1,1);
  SetStat("wisdom",50,1);
  SetLevel(120);
   
   switch(random(2)) {
     case 0:
      SetGender("male");
      break;
     case 1:
      SetGender("female");
      break;
      }
  SetBaseLanguage("Archaic");    
  SetSpellBook( ([
    "major venomous touch"  : 100,
    "gangrene"              : 100,
    "major infection"       : 100,
    "touch of death"        : 100,
    "pain touch"            : 100,
    "wall of souls"         : 100,
    "curse"                 : 100,
    "purify"                : 100,
     ]) );
  SetAction(10, ({
    "!speak If only.... yes... if only we could increase the values... yes",
    "!speak May pestilence be upon you",
    "!speak Hail the Decayed One!",
    "!speak My... oh my, isn't that precious?",
    "!emote straightens his garments.",
    }) );
  SetCombatAction(50, ({
    "!cast curse",
    "!cast major venomous touch",
    "!cast gangrene",

    "!cast major infection",
    "!cast touch of death",
    "!cast pain touch",
    "!cast purify",
    }) );
  SetReligion("Thorian","Thorian");
  SetMorality(-500);
  


  switch(random(4)) {
  case 0:
    weap = "zweihander";
    break;
  case 1:
    weap = "knife";
    break;
  case 2:
    weap = "staff";
    break;
  case 3:
    weap = "flail";
    break;
    }

  SetInventory( ([
        CATA_OBJ "cappa" : "wear cappa",
        CATA_OBJ "cassock" : "wear cassock",
        CATA_OBJ "mitre" : "wear mitre",
        CATA_OBJ + weap : "wield " + weap,
     ]) );
  SetUndead(1);
  SetUndeadType("lich");
  SetResistance(GAS, "immune");
  SetResistance(HUNGER, "immune");
  SetResistance(POISON, "immune");
  SetResistance(DISEASE, "immune");
  SetFirstCommands( ({ 
    "cast wall of souls",
    "cast wall of souls",
    "cast wall of souls",
     }) );
  }

varargs int eventDie(object who) {
  object germ;

  if(random(10) == 1) {
   germ = new(CATA_OBJ "pestilence");
   germ->eventMove(who);
   who->eventForce("cough");
   this_object()->eventForce("!emote screams out an unintelligible curse.");
  }
  return npc::eventDie(who);
 }


void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
    eventForce("cast wall of souls");

  }
}
