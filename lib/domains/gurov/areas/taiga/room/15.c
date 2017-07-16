//Illura@haven
//Room 15
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("sub-arctic");
  SetShort("Northern reaches of the taiga");
  SetLong(
    "The towering conifers are less dense here than they are "
    "to the south, needles on the trees almost so dark as to be "
    "black among the deepening snowdrifts. Sparkling icicles "
    "hang like  heavy daggers from the boughs, giving the place "
    "a forboding presence."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "13",
    "north" : TAIGA_ROOM "18",
    "east" : TAIGA_ROOM "16",
    "west" : TAIGA_ROOM "14",
  ]) );
  SetItems( ([
    ({"conifer", "conifers"}) : "Tall spruce and pine trees seem denser to the south.",
    "needles" : "The needles are very dark green in color.",
    ({"snowdrifts", "drifts", "drift"}) : "The snow is deep and packed.",
    "icicles" : "Long spindly icicles hang from the trees.",
    "boughs" : "The boughs are encased in ice.",
  ]) );
  SetItemAdjectives( ([
    "conifers" : "towering",
    "snowdrifts" : "deepening",
    "icicles" : "sparkling",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "leopard" : 3,
  ]) );
  SetListen( ([
    "default" : "The icicles clatter together like wind chimes.",
  ]) );
  SetSmell( ([
    "default" : "The air is full of the scent of snow.",
  ]) );
}
