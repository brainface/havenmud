/*  Rath Khan, Emperor of the World
 */
#include <lib.h>
#include "../rath.h"
inherit LIB_SENTIENT;
inherit LIB_FEAR;

int RathEncounter(object who);

static void create() {
  sentient::create();
  SetKeyName("Rath Khan");
  SetFriends( ({ "guard", "elite guard" }) );
  SetShort("Rath Khan, Emperor of Kailie");
  SetId( ({ "rath", "khan", "emperor" }) );
  SetAdjectives( ({ "rath", "emperor" }) );
  SetRace("elf");
  SetUndead(1);
  SetUndeadType("skeleton");
  SetGender("male");
  RemoveLanguage("Eltherian");
  SetLanguage("Archaic", 100, 1);
  SetLong("Rath Khan stands a towering 7' tall.  His grim visage is one "
          "that could bring fear to most anyone. The flesh that was once "
          "young with life has grown old and decayed, the what was once "
          "the face of a proud warrior is now the terrible mask of "
          "eternal doom.");
  SetClass("evoker");
  SetSkill("pole combat", 1, 1);
  SetSkill("necromancy", 1, 1);
  SetSkill("faith", 1, 1);
  SetLevel(240);
  SetResistLevel(99);
  SetFearLength(100);
  SetFearType("aura of evil around Rath Khan");
  SetMorality(-800);
  SetInventory( ([
     TOWER_O + "/rath_armour" : "wear breastplate",
     TOWER_O + "/rath_staff"  : "wield staff",
    ]) );
  SetSpellBook( ([
    "enhanced energy wall" : 100,
    "mesmer barrier"       : 100,
    "death"                : 100,
    "touch of death"       : 100,
    ]) );
  SetCombatAction(5, ({ 
    "!cast enhanced energy wall",
    "!cast mesmer barrier",
    "!cast death",
    "!cast touch of death",
     }) );
  SetAction(5, ({
  	"!cast enhanced energy wall",
    "!cast mesmer barrier",
  	"!cackle",
  	"!yell I shall have my revenge, ElfLord!",
    }) );
  SetCurrency("imperials", random(25000)+25000);
  SetEncounter( (: RathEncounter :) );
  
  SetFirstCommands( ({  "cast enhanced energy wall", 
                        "cast enhanced energy wall", 
                        "cast mesmer barrier" }) );
}

void init() {
  sentient::init();
  fear::init();
}

varargs int CheckResistFear(object who, int Level, string Type){
  if (!userp(who) && who->GetUndead()) { return 0; }
  return ::CheckResistFear(who, Level, Type);
}

int RathEncounter(object who) {
  if (who->GetProperty("rath_guard")) return 0;
  AddEnemy(who);
  return 1;
}
