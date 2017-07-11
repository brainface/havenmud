/*  Level #2 - Chasm - Section #3  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(20);
  SetShort("an enormous chasm");

  SetLong("Here a tunnel exits from the chasm leading off to the northwest.  "
          "The enormously, large chasm extends up and out of sight and below "
          "opens up like a huge maw daring light to try and escape.  The "
          "walls to the side of you seem to sparkle in the dim light.  The "
          "ledge you stand upon continues to the north and south running "
          "along the chasm and out of sight into the darkness.");

  SetSmell( ([
    "default"  :  "The smell of water lazily drifts by.",
  ]) );

  SetListen( ([
    "default"  :  "A loud thundering comes from far below and to the northern "
                  "end of the chasm.",
  ]) );

  SetExits( ([
   "northwest"  :  ROOMLV2 + "/tunnel2c",
   "north"      :  ROOMLV2 + "/chasm2b",
   "south"      :  ROOMLV2 + "/chasm2d",
  ]) );
  SetObviousExits("north, northwest, south");

  SetSearch( ([
    ({ "walls", "wall" })  :  "The walls around you have already been cleared "
       "of anything that is valuable.",
  ]) );

  SetItems( ([
    ({ "chasm", "large chasm", "enormous chasm" })  :  (: GetLong :),
    ({ "tunnel" })  :
       "A tunnel leads out and away from the chasm to the northwest.  It is "
       "soon out of your line of sight.",
    ({ "up", "ceiling" })  :
       "Far above you, you can make out very little detail in the ceiling, "
       "as it rests in a veil of shadows and darkness.",
    ({ "down", "below", "huge maw", "maw" })  :
       "As you peer down over the ledge's edge you see a huge maw of darkness "
       "that is more than ready and willing to swallow any light that may be "
       "shed into it's domain.",
    ({ "walls", "wall" })  :
       "As you look closer at the walls to the side of you you notice various "
       "gems and metals weaving their random patterns "
       "across the chasm walls.",
    ({ "ledge" })  :
       "The ledge you are standing on continues along the chasm to the north "
       "and to the south into the darkness that is plentiful around you.",
    ({ "darkness" })  :
       "It's very dark!",
    ({ "shadows", "shadow" })  :
       "They are dark and mysterious.",
    ({ "light", "faint light" })  :
       "Light! What light?! It's been swallowed up by the darkness.",
    ({ "gems", "gem", "metals", "metal", "various gems", "various metals" })  :
       "The various gems sparkle slightly in the faint light to provide a "
       "multicolored wonder.  The various metals weave their random patterns "
       "across the chasm walls.  All in all, it leaves a very stunning view.",
  ]) );
}
