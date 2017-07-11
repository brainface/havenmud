#include <lib.h>
inherit LIB_NPC;
#include "../castle.h"

static void create() {
   npc::create();
   SetKeyName("talented musician");
   SetShort("a talented musician");
   SetId( ({ "musician" }) );
   SetAdjectives( ({ "talented","tall","stringy" }) );
   SetLong("Tall and stringy, compared to most dwarves, the musician "
           "seems drawn into his own world, staring off into space.");
   SetRace("dwarf");
   SetClass("rogue");
   SetLevel(14);
   SetGender("male");
   SetAction(8, ({ "!emote strums his instrument gently.",
                   "!emote hums a few bars of his latest piece.",
                   "!sings quietly.",
              }) );
   SetCombatAction(2, ({ "!emote drifts off for a moment, unconnected "
                         "with the world, and snaps back suddenly as "
                         "he realizes that he is being attacked.",
                    }) );
   SetInventory( ([
                    VC_OBJ + "/guitar" : 1,
               ]) );
   SetCurrency("nuggets",2+random(3));
   SetMorality(75);
}