//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a flowered pasture");
  SetClimate("arid");
  SetLong(
    "The wall of a low, mud-brick building stands to the north of here, "
    "where a scattering of tiny rose and violet desert flowers bloom "
    "within the grass. Animal tracks run through here, and a dock "
    "appears to be just to the west. "

  );
  SetItems( ([
    ({ "wall", "building" }) :
    "The mud-brick building is not enterable from this side. ",
    ({ "grass", "flower", "flowers" }) :
    "The delicate blooms poke their faces through the grass. ",
    ({ "tracks" }) : 
    "The tracks belong to small birds. ",
    "dock" : "The dock is south of this place.",
  ]) );
  SetItemAdjectives( ([
  "building" : ({ "mud-brick", "low" }),
  "flowers" : ({ "tiny", "rose", "violet", "desert", "scattering", "scattered" }),
  "tracks" : ({ "animal" }),
  ]) );
  SetListen("Birds chirp excitedly.");
  SetSmell("The flowers exude a heavenly scent.");
  SetExits( ([
    "west"  : LAKE_ROOM "/3g",
    "south"  : LAKE_ROOM "/4h",
  ]) );
  SetInventory( ([
    LAKE_NPC "ibis" : 3,
  ]) );
}
