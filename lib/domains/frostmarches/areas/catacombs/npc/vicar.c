#include <lib.h>
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include "../cata.h"
inherit LIB_NPC;
 
static void create() {
string weap;

  ::create();
  SetKeyName("Armagh");
  SetShort("Vicar Armagh Clogher the Pestilence Overseer");
  SetAdjectives( ({ "vicar" }) );
  SetId( ({ "lich","cata_npc","vicar" }) );
  SetLong("Dedicated to his studies and the advancement"
          " of his religious practices, Armagh Clogher has"
          " lead his priests into a life of eternal servitude"
          " to their Lord. His face shows small signs of decay,"
          " a small testiment to the years of service he has"
          " put in. While obviously ancient, he looks to be"
          " formidable, and if his rank is any indication"
          " his magical powers are probably unmatched by"
          " any he oversees.");
  SetRace("human");
  SetClass("priest");
  SetSkill("poison magic",1,1);
  SetSkill("pole combat",1,1);
  SetSkill("melee combat",1,1);
  SetStat("wisdom",50,1);
  SetLevel(140);
  SetGender("male");
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
    "!speak Holy is He the Decayed One",
    "!speak May pestilence be upon you",
    "!speak Hail the Decayed One!",
    "!speak Death and disease are our cup of tea",
    "!emote fixes his hat.",
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
  SetLimit(1);
  SetInventory( ([
        CATA_OBJ "cappa" : "wear cappa",
        CATA_OBJ "cassock" : "wear cassock",
        CATA_OBJ "mitre" : "wear mitre",
        CATA_OBJ "staff" : "wield staff",
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
    "Cast wall of souls",
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
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast wall of souls");

  }
}
