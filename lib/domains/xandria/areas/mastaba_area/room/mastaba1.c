//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../mastaba.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetWarmth(30);
  SetAmbientLight(15);
  SetShort("inside a mastaba");
  SetLong(
    "The inside of this tomb is painted and carved sumptuously with "
    "many designs. Some seem to be wards, glowing with a deep strength "
    "from within. The floor here is dusty. Cobwebs litter the corners, "
    "and the ceiling is very low compared with any buildings in Lisht "
    "itself. A small hole leads downward into an antechamber, and the "
    "exit from this foreboding place is out of the large stone door. "
    );
  SetSmell( ([
    "default" : "The scent of decay here is overwhelming.",
    ]) );
  SetListen( ([
    "default" : "Oddly enough, it is as silent as the grave.",
    ]) );
  SetProperty("no teleport",1);
  SetItems( ([
    ({ "paintings", "design", "designs", "ward", "wards" }) :
      "Most of the paintings are religious or spiritual, but some are "
     "glowing abstract symbols that seem to tell you to leave here.",
    ({ "floor", "dust" }) :
      "The stone floor is thickly covered with the dust of ages. ",
    ({ "cobweb", "cobwebs" })  :
      "They are ugly cobwebs, but there are no spiders here. ",
    ({ "ceiling" }) :
      "The ceiling is low, giving one the impression of smallness "
      "before the face of death and complete obliteration.",
    ({ "hole", "antechamber" }) :
      "The hole leads deeper into the tomb and danger itself.",
     ({ "door" }) :
      "The seal on the door is cracked. ",
    ]) );
  SetItemAdjectives( ([
    "door"    : ({ "stone", "large" }),
    "hole" : ({ "small" }),
    "ceiling"    : ({ "low" }),
    ]) );
   SetInventory( ([
    MASTABA_NPC "graverobber" : 1,
    ]) );
  SetExits( ([
  "out" : XANDRIA_TOWNS "lisht/room/gnoll/graveyard",
    "down" : MASTABA_ROOM "mastaba2",
    ]) );
}
