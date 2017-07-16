#include <lib.h>
#include "../path.h"

inherit LIB_ROOM;

static void create()
{
  ::create();
  SetShort("southern end of laboratory");
  SetLong("Although less used than the northern end of the laboratory, this "
          "room, too, is characterized by a disorderly jumble of chemicals "
          "and herbs. Bookcases in the corners of the room house a number of "
          "weighty tomes. Here, too, the spilled reagents seem to have "
          "discoloured the wooden floorboards. A very small storage room sits "
          "to the east. A passage to the south opens up into what looks like "
          "a bedroom from here. A hallway leads out of the laboratory to the "
          "west.");
  SetSmell( ([
    "default" : "A pungent odor floats in from the north."
  ]) );
  SetListen( ([
    "default" :
      "The scurry of little critters is very obvious in the otherwise "
      "dead silence of the room."
  ]) );
  SetClimate("indoors");
  SetItems( ([
    ({"disorderly jumble","jumble","various items","items","item",
      "spilled chemicals","spilled chemical","chemicals","chemical",
      "spilled reagents","spilled reagent","reagents","reagent","herbs",
      "herb","clutter"}) :
      "Various items that Teras uses in her experiments lie scattered "
      "across the floor.",
    ({"southern end of laboratory","southern laboratory","southern lab",
      "southern end of lab","end of laboratory","end of lab","laboratory",
      "lab","room"}) :
      (: GetLong() :),
    ({"weighty tomes","tomes","weighty tome","tome","diagrams",
      "diagram"}) :
      "The shelved books are written in a foreign tongue.  From the "
      "diagrams, it seems they elaborate upon some scientific procedure.",
    ({"corners of the room","corner of the room","corners","corner",
      "bookcases","bookcase"}) :
      "The corners of the room are occupied by bookshelves.",
    ({"discoloured wooden floorboards","discoloured wooden floorboards",
      "discoloured floorboards","discoloured floorboard",
      "wooden floorboards","wooden floorboard","floorboards",
      "floorboard", "floor","handsome veneer","veneer","radiance"}) :
      "The floorboards may at one time have been made gilded with a "
      "handsome veneer, but spilled chemicals have long since destroyed "
      "any touch of radiance that could have emanated from these "
      "now discoloured floorboards.",
    ({"east","very small storage room","small storage room","storage room"
      "small room"}) :
      "The storage room to the east is not very clearly visible from here.",
    ({"bedroom","passage to the south","passage","south"}) :
      "The bedroom to the south is not very clearly visible from here.",
    ({"hallway","west"}) :
      "The hallway to the west is not very clearly visible from here.",
    ({"northern end of the laboratory","northern end of the lab",
      "northern end","north"}) :
      "The northern end of the laboratory is not very clearly visible from "
      "here."
  ]) );
  SetAmbientLight(43);
  SetExits( ([
    "north" : L_ROOM "/main_lab",
    "east" : L_ROOM "/annex",
    "south"  : L_ROOM "/bedroom",
    "west" : L_ROOM "/hallway",
  ]) );
  SetInventory( ([
    L_NPC "/rat" : random(2) + 1,
    L_NPC "/roach" : random(1) + 1,
    L_OBJ "/shard" : 1,
  ]) );
}
