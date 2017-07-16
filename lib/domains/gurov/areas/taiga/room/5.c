//Illura@haven
//Room 5
//August 2009
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../taiga.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("temperate");
  SetShort("Deep within the taiga");
  SetLong(
    "The thick conifer forest here is littered with burrows "
    "and tiny tunnels through the undergrowth, strewn with tiny "
    "mouldering bones bearing a multitude of teethmarks from "
    "the many past meals of small tundra carnivores. The taiga "
    "extends in all directions from here."
  );
  SetExits( ([
    "south" : TAIGA_ROOM "2",
    "east" : TAIGA_ROOM "6",
    "north" : TAIGA_ROOM "8",
    "west" : TAIGA_ROOM "4",
  ]) );
  SetItems( ([
    ({"burrow", "tunnel", "tunnels"}) : "The homes of small forest creatures, warmer than in the open.",
    ({"bones", "teethmarks", "marks"}) : "The old bones are covered in chew marks.",
    "undergrowth" : "The needles have fallen for generations.",
  ]) );
  SetItemAdjectives( ([
    "tunnels" : "tiny",
    "bones" : "mouldering",
  ]) );
  SetInventory( ([
    TAIGA_NPC + "weasel" : 3,
  ]) );
  SetListen( ([
    "default" : "Chittering sounds come from the burrows.",
  ]) );
  SetSmell( ([
    "default" : "The scent of pine and decay lingers here.",
  ]) );
}
