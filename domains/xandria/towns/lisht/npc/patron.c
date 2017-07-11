
//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
   npc::create();
  SetKeyName("patron");
  SetShort("a patron of the inn");
  SetId( ({ "patron" }) );
  SetAdjectives( ({ "inn" }) );
  SetLong("This is one of the Blue Lotus Inn's many "
      "well-to-do patrons. Unlike the drunks, this person "
       "can probably take care of themself in a brawl. ");
  SetRace("gnoll");
  SetClass("fighter");
  SetGender("female");
  SetLevel(random(5) + 1);
  SetBaseLanguage("Rehshai");
  SetInventory( ([
                   LISHT_OBJ + "honeycake" : 1,
                    LISHT_OBJ + "shenti" : "wear shenti",
               ]) );
  SetMorality(-100);
   AddAlcohol(10);
   SetCombatAction(10, ({ "!yell Help!"}) );
   SetFriends( ({"hathor","drunk","patron","citizen"}) );
}
