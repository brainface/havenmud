#include <lib.h>
#include <std.h>
#include "../rome.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("narrin");
  SetShort("Narrin the Decayer, Trainer of the Faithful");
  SetReligion("Thorian");
  SetId( ({ "narrin", "decayer" }) );
  SetRace("human");
  SetClass("priest");
  RemoveLanguage("Enlan");
  SetLanguage("Imperial", 100, 1);
  SetLong("Narrin the Decayer is the man responsible for teaching young "
          "priests of the Thorian faith the spells of their death religion. "
          "His knowledge can be considered valuable yet oddly morbid.");
  SetGender("male");
  SetTown("Sanctum");
  SetSkill("enchantment", 1, 1);
  SetSkill("evokation", 1, 1);
  SetSkill("poison magic", 1, 1);
  SetSkill("necromancy", 1, 1);
  SetSkill("knife combat", 1, 1);
  SetSkill("faith", 1, 1);
  SetLevel(150);
  SetTrainingSkills( ({
    "knife combat","skinning",
    }) );
  SetAction(5, ({
    "!speak Would you like me to convert you?",
    "!speak If you are a Thorian Priest, I can teach you spells.",
    }) );
  SetSpellBook( ([
    "wall of souls"    : 100,
    "pious obstructions"   :  100,
    "persistent bane"  :  100,
    "major venomous touch" : 100,
    "gangrene" : 100,
    ]) );
  SetCombatAction(80, ({
    "!cast major venomous touch",
    "!cast persistent bane",
    "!cast gangrene",
    }) );
  SetLimit(1);
  SetInventory ( ([
    ROME_OBJ "bknife" : "wield knife",
    ROME_OBJ "boots" : "wear boots",
    ROME_OBJ "helmet" : "wear helmet",
    ROME_OBJ "greaves" : "wear greaves",
    ROME_OBJ "breastplate" : "wear breastplate",
    ROME_OBJ "gauntlet" : "wear first gauntlet on left hand",
    ROME_OBJ "gauntlet2" : "wear first gauntlet on right hand",
  	]) ); 
  SetFirstCommands( ({ 
    "cast pious obstructions",
    "cast pious obstructions",
    "cast pious obstructions",
    "cast pious obstructions",
    "cast pious obstructions",
  	}) );
  SetFriends( ({ 
  	"garric",
    }) );
}

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast pious obtructions");
  }
}
