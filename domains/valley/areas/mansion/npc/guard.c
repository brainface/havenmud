/* a guard for the mansion
    kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("guard");
  SetShort("a tough looking guard");
  SetId( ({"guard"}) );
  SetAdjectives( ({"tough", "tough looking" }) );
  SetLong("This guard is quite tall and looks very strong. He appears "
          "to be quite adept with his chosen weapon and will defend the "
          "mansion at any cost.");
 
  SetInventory( ([
         MANSION_OBJ + "guard_sword" : "wield sword",
            ]) );
  SetRace("human");
  SetClass("fighter");
  SetLevel(35);
  SetMorality(25);
  SetAction(6,
       ({ "The guard places his hand on his sword as a warning to all." 
          }) );
  SetCombatAction(5,
         ({ "!slice" }) );
  SetFriends( ({ "guard"}) );
  }
