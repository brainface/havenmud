/*   Portia  10-21-98
    A language teacher for Malveillant.
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Tonian Pariad");
  SetShort("Tonian Pariad, the Royal Tutor");
  SetId( ({"tonian", "tonian pariad", "pariad", 
             "tutor"}) );
  SetAdjectives( ({"royal"}) );
  SetLong("Tonian is a tall dark-elf with eyes as black as night."
          "There is an aura of knowledge around him and he seems to "
          "know more than anyone.");
  SetGender("male");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetClass("enchanter");
  SetLevel(50);
  SetCurrency("roni",random(50) + 30);
 
  SetSpellBook( ([
     "bolt"			       : 100,
     "fireball"        : 100,
     "energy field"    : 100,
     "chain lightning" : 100,
       ]) );
  SetCombatAction(75, ({ 
     "!cast fireball",
     "!cast bolt",
     "!cast energy field",
     "!cast chain lightning",
     }) );
  SetTaughtLanguages( ({"Eltherian","Skavish"}) );
  SetLocalCurrency("roni");
  SetCharge(500);
  SetInventory( ([
       MAL_OBJ + "/clothing/roy_leg" : "wear leggings",
       MAL_OBJ + "/clothing/roy_shirt" : "wear shirt",
       MAL_OBJ + "/clothing/elf_medallion" : "wear medallion",
       MAL_OBJ + "/weapons/staff" : "wield staff",
       ]) );
  SetAction(5, "!emote looks at you imperiously.");
  }
