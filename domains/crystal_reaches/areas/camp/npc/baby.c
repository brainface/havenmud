#include <lib.h>
#include "../camp.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("baby");
  SetId( ({ "baby"}) );
  SetAdjectives( ({"screaming", "crying"}) );
  SetShort("a screaming baby");
  SetLong(
    "The baby is small and thin. He does "
    "not look well cared for and smells like he "
    "hasn't been changed in days."
    );
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(1);
  
  SetMorality(1000);
  SetAction(5, ({ "The baby screams uncontrollably.",
             "The baby cries loudly." }));
  SetParalyzed(1000);
  SetStat("durability", 4, 1);
}
