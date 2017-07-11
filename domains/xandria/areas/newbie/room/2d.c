//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("on the eastern edge of the garden");
  SetClimate("arid");
  SetLong(
    "This side of the garden seems to be devoted to growing "
    "the most flexible straws and desert grasses, which are "
    "gathered by the townsfolk for weaving baskets and other "
    "necessities. There seems to be a small body of water to "
    "the west, and the sandy trail leads north and south, as "
    "well."
  );
  SetItems( ([
    "garden" : "This is a public garden, complete with "
    "animals and various plants.",
    ({ "sand", "path" }) : 
    "The sandy path seems to be less used the further you "
    "move from the city.",
    ({ "grass", "grasses", "straw", "straws" }) : 
    "The grasses and straws are sweet smelling and are "
    "quite happy in this climate. ",
  ]) );
  SetItemAdjectives( ([
   "path" : ({"sandy"}),
   "straws" : ({ "flexible" }),
  ]) );
  SetInventory( ([
    NEWBIE_NPC "sandalmaker" : 1,
  ]) );
  SetListen("The wind sussorates the grasses gently.");
  SetSmell("The air is filled with a sweet hay-like scent.");
  SetExits( ([
    "north" : NEWBIE_ROOM "/1d",
    "south" : NEWBIE_ROOM "/3d",
    "west" : NEWBIE_ROOM "/2c",
  ]) );
}
