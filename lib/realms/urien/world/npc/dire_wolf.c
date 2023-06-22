// Kudos to Mahkefel for the help 
// Kudos to Melchezidek for this edited file for the include
// Strictly quest NPC - Only spawned for questing
// Made level 20 goal. But can be copypasta'd into bigger threats
// Urien@Haven 21JUN2023

#include <lib.h>
#include <std.h>
#include "../rand_gender.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("wolf");
  SetId( ({ "wolf"}) );
  SetAdjectives( ({ "dire" }) );
  SetRace("wolf","dire wolf");
  SetClass("animal");
  SetGender(GetRandomGender());
  SetLevel(random(5) + 20);
// 46 was chosen as it is default dura,speed at level 21
// Added more for variety. A 'harder' animal to kill for quest
  SetStat("durability", random(15) + 46, 1);
  SetStat("speed", random(10) + 46, 1);
  SetShort("a dire wolf");
  SetLong("At a glance this massive dire wolf seems covered in "
          "wet and dry blood. The piercing yellow eyes stand out "
          "among the large muscled cranium and body. In-between the "
          "soaked bloody pelt clumps, a dark gray pelt colour with "
          "some compliment of black hair is exposed to reveal a soft "
          "white skin. It looks to be at a prime peak in the adult "
          "life of this species. Two large and alerted ears twitch "
          "and turn toward anything nearby that makes sudden noise "
          "or to anything deemed a viable cautionary threat.");
  SetAction(2, ({
     "The dire wolf digs at something on the ground.",
     "A dire wolf releases a yawn, then stops to focus on listening.",
     "Dire wolf briefly shakes and releases some dust."
     }) );
}
