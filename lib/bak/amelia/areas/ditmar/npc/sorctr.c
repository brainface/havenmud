#include <lib.h>
#include "ditmar.h"
inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("Tesche");
   SetShort("Tesche, the sorcerer trainer");
   SetId( ({ "tesche","sorcerer","trainer" }) );
   SetAdjectives( ({ "tesche","sorcerer","trainer" }) );
   SetLong("Tesche is a mar that has dedicated his life to training others in the skills "
           "of fighting and enchantment.  He is a mar of average height and build, and "
           "stoops over the ground as if he was carrying a large burden on his back, but "
           "he seems awake and cheerily ready to do his job.");
   SetGender("male");
   SetRace("mar");
   SetClass("enchanter");
   SetClass("fighter");
   SetLevel(35);
   AddTrainingSkills("slash attack");
   AddTrainingSkills("hack attack");
   AddTrainingSkills("multi-weapon");
   AddTrainingSkills("slash defense");
   AddTrainingSkills("melee attack");
   AddTrainingSkills("melee defense");
   AddTrainingSkills("enchantment");
   AddTrainingSkills("conjuring");
   AddTrainingSkills("pole attack");
   AddTrainingSkills("evokation");
   AddTrainingSkills("healing");
   AddTrainingSkills("divination");
   SetInventory( ([
                    D_OBJ + "/robe" : "wear robe",
               ]) );
   SetSpellBook( ([
                    "aura" : 100,
                    "fireball" : 100,
                    "terra" : 100,
               ]) );
   SetCombatAction(40, ({ "!cast aura","!cast fireball",
                          "!cast terra" }) );
}