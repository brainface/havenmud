//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetShort("in a small pasture on the banks of Lake Rantera");
  SetClimate("arid");
  SetLong(
    "The wall of a low, mud-brick building stands to the east of here, "
    "where sheep graze happily by the idyllic shores. The grass is "
    "cropped close to the ground from constant munching, and piles of "
    "sheep dung lie interspersed through the clearing. The lake lies "
    "just west of here, and there seems to be a dock of some sort "
    "to the south."
  );
  SetItems( ([
    ({ "wall", "building" }) :
    "The mud-brick building is not enterable from this side. ",
    ({ "grass", "ground", "clearing", "shores", "shores" }) :
    "The emeraldine grass is shorter here, because of the sheep. ",
    ({ "pile", "piles", "dung" }) : 
    "The sheep dung smells sweetly rank and is hardly worth a "
    "closer look.",
    "dock" : "The dock is south of this place.",
    "lake" : "Lake Rantera stands on the entire western horizon.",
  ]) );
  SetItemAdjectives( ([
  "building" : ({ "mud-brick", "low" }),
  "shore" : ({ "idyllic" }),
  "grass" : ({ "cropped" }),
  "dung" : ({ "sheep" }),
  ]) );
  SetListen("Occasionally, a sheep bleats.");
  SetSmell("The air smells a little like sheep manure.");
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/shark" : 10,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
  SetExits( ([
    "west"  : LAKE_ROOM "/2f",
    "south"  : LAKE_ROOM "/3g",
    "north" : LAKE_ROOM "/1g",
  ]) );
  SetInventory( ([
    LAKE_NPC "sheep" : 3,
  ]) );
}
