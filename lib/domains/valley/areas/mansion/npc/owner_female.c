/* the mistress of the mansion
   kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("Alexis Roman");
  SetShort("Alexis Roman");
  SetId( ({"alexis", "roman", "alexis roman", "woman" }) );
  SetLong("This well-dressed woman is very well poised and very proper. "
        "It is apparent that she comes from a rich family. Her demeanor "
       "suggests she is the mistress of the household and will not tolerte "
       "any disruptions during her party.");
  SetRace("human");
  SetClass("fighter");
  SetClass("rogue");
  SetLevel(20);
  SetMorality(-150);
  SetGender("female");
  SetCurrency( ([
        "imperials" : 300,
               ]) );
  SetInventory( ([
      MANSION_OBJ + "dagger2" : "wield dagger",
           ]) );
  SetAction(4,
        ({ "Alexis looks around for her husband." }) );
  }
