/* the foyer maid in the mansion
   kyla 3-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("maid");
  SetShort("an attractive maid");
  SetLong("This maid is quite attractive although she looks rather strong. "
         "Her household chores must require her to move heavy objects.");
  SetId( ({ "maid"}) );
  SetAdjectives( ({"pretty", "attractive"}) );
  SetGender("female");
  SetRace("human");
  SetClass("rogue");
  SetStat("strength",60,2);
  SetMorality(-85);
  SetLevel(25);
  SetAction(3, ({ "The maid smiles warmly."}) );
  }
