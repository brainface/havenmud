/* a guest for the guest bedroom.
   kyla 7-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetShort("a large man");
  SetKeyName("man");
  SetId( ({"man"}) );
  SetAdjectives( ({"large"}) );
  SetRace("human");
  SetClass("rogue");
  SetLong("This man is very large and appears to be highly trained "
          "in several areas. His broad shoulders and strong arms indicate "
         "that he is used to physical work.");
  SetLevel(20);
  SetAction(5, "The man looks you over with a skillful eye.");
  SetInventory( ([
       ]) );
  SetMorality(100);
  }
