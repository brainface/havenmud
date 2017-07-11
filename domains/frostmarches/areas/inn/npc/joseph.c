#include "../inn.h"
#include <lib.h>
inherit LIB_NPC;

static void create()
{
  npc::create();
  SetKeyName("Joseph");
  SetShort("Joseph the magician");
  SetId( ({ "joseph", "magician" }) );
  SetLong("Joseph the magician stands about six feet, six inches tall and sports "
          "a trimmed, black beard.  The veins swelling through his bald head "
          "look quite strange.");
  SetRace("human");
  SetGender("male");
  SetClass("evoker"); 
  SetLevel(14);
  SetCurrency("senones", random(100)+25 );
  SetMorality(475);
 
  SetInventory( ([
                 "/std/weapon/pole/baton" : "wield baton",
                 I_OBJ + "/robe" : "wear robe" 
                 ]) );
  SetSpellBook( ([
                 "missile" : 100,
                 "buffer" : 100,
                 ]) );
  SetAction(8,
    ({
     "!speak I fixed up the room as a gift for my good friend, Jord.  He "
     "should be very happy when he sees it.",
     "!cast buffer",
     }) );
  SetCombatAction(65,
    ({ 
     "!cast missile",
     "!cast buffer"
     }) );

}
