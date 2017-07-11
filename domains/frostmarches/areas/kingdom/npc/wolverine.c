
/* a wolverine
   Elasandria 4/15/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("wolverine");
  SetShort("a burly wolverine");
  SetId( ({"wolverine"}) );
  SetAdjectives( ({"burly","wild","mean"}) );
  SetLong("This burly wolverine has little eyes and long sharp teeth. It "
         "wild and mean looking.");
  SetGender("male");
  SetRace("dog","weasel");
  SetClass("animal");
  SetLevel(4);
  SetAction(5,
         ({"!emote bares his teeth and snarls.",
          "The wolverine bares his teeth and snarls."}) 
         );
  SetInventory( ([
         ]) );
}
