/*  end of the west passage*/

#include <lib.h>
#include <domains.h>
#include "../glim.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(45);
  SetShort("end of the passage");
  SetLong("The passage comes to an abrupt end here.  The wall "
    "is smoothed and flatened, as if this point was truly meant to "
    "the end of the passage. To the north, embedded in the wall, "
    "lies the greatest armourer of Glistendin. It serves for armour "
    "distribution to both the military "
    "and the general citizenry. To the south is the smithy in all "
    "its glory and splendor. It provides dwarves with the most needed tools "
    "for their unending warfare - weapons.");
  SetItems( ([
    ({"western passage", "passage"})  :
      "The passage ends here.",
    ({"smithy"})  :
     "The smithy is to the south.",
    ({"armoury"})  :
      "The armoury is to the north.",
    ]) );
  SetItemAdjectives( ([
    "passage"  :  ({"westward", "enormous", "immense", "huge"}),
    "armoury"  :  ({"greatest"}),
  ]) );

  SetExits( ([
    "west"   : AVERATH_ISLAND "-8,-3,1",
    ]) );
  SetEnters( ([
    "armoury" : G_ROOM "armoury",
    "smithy"  : G_ROOM "smithy",
    ]) );
  SetSmell( ([
    "default" : "The heavy smell of metal is in the air.",
    ]) );
  SetListen( ([
    "default" : "The clang of metal being pounded into shape reverberates loudly.",
    ]) );
  SetInventory( ([
    G_NPC "citizen" : 2,
    ]) );
}
