#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("pillar of fire");
  SetId( ({ "pillar", "fire" }) );
  SetAdjectives( ({ "pillar", "of", "swirling" }) );
  SetSmell("The pillar reeks of brimstone and burnt ash.");
  SetListen("The pillar crackles and burns.");
  SetLong(
    "This swirling pillar of fire appears to be a magical rift "
    "of some kind. Looking into the pillar seems like looking "
    "at another dimension."
    );
  SetPreventGet("");
  SetShort("a swirling pillar of fire");
}
