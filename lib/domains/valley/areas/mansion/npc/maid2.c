/* the other maid for the mansion
   kyla 3-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("maid");
  SetShort("a short maid");
  SetLong("This maid is quite small in stature but appears quite wise. "
          "Her physical appearance is petite, yet she radiates a certain "
           "knowledge.");
  SetId( ({"maid", "woman" }) );
  SetAdjectives( ({"short" }) );
  SetRace("human");
  SetClass("evoker");
  SetLevel(30);
  SetGender("female");
  SetMorality(150);
  SetInventory( ([
               ]) );
  SetSpellBook( ([
           "sphere"   : 100,
           "fireball" : 50,
           "shock"    : 100, 
               ]) );
  SetCombatAction(5, ({
            "!cast sphere",
            "!cast shock",
            "!cast fireball",
            }) );
   }
