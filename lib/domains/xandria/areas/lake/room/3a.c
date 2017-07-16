//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a storeroom");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetLong(
    "This is a tiny storeroom, with each wall lined with overfilled "
    "shelves that bow under such an enormous weight of goods. Near "
    "one corner of the room is a small beadworker's station that "
    "is thankfully out of the heat and bedlam of the rest of the "
    "workshop. A doorway leads north into the mastercraftsman's "
    "office."
  );
  SetItems( ([
    ({ "storeroom" }) : (: GetLong :),
    ({ "wall", "walls", "shelves", "shelf" }) :
    "The walls are lined with shelves, which are covered in goods. ",
    ({ "weight", "goods" }) :
    "The goods range from elaborate bits of pottery to sheaves of "
    "the simplest linen cloth. ",
    ({ "workstation", "station" }) :
    "The workstation consists of a low table, covered in beads and "
    "bits of things that could someday be beads.",
    ({ "doorway" }) :
    "The doorway leads north.",
  ]) );
  SetItemAdjectives( ([
  "shelves" : ({ "overfilled" }),
  "storeroom" : ({ "tiny" }),
  "weight" : ({ "enormous" }),
  "doorway" : ({ "open" }),
  "station" : ({ "beadworker's", "small" }),
  ]) );
  SetListen("It is exceedingly quiet here.");
  SetSmell("The air smells fresh.");
  SetExits( ([
    "north" : LAKE_ROOM "/2a",
  ]) );
  SetInventory( ([
    LAKE_NPC "beadmaker" : 2,
  ]) );
}
