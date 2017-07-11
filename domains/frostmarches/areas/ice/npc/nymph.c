// Written by Vanyel
#include <lib.h>
#include "ice.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("a skating nymph");
  SetShort("a beautiful ice-skating nymph");
  SetId( ({ "nymph", "skater" }) );
  SetAdjectives( ({ "ice-skating", "ice", "skating", "skater", "beautiful" }) );
  SetRace("nymph");
  SetClass("rogue");
  SetLong("Blissfully skating on the frozen lake, this beautiful nymph "
    "happily twirls and dances on the ice.  She gracefully turns and "
    "twists, making skating look very easy.");
  SetGender("female");
  SetInventory( ([
     ICE_OBJ + "/skates" : "wear skates",
     ]) );
  SetLevel(10);
  SetAction( 5, ({ "!emote twirls on the ice happily.", 
    "!emote skates around the lake." }) );
}
