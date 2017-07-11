#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("arid");
  SetShort("the path along the spiral minaret");
  SetLong(
    "The uppermost level of the minaret continues "
    "with a gradual incline, following the path up "
    "to a structure of some kind.  The minaret itself "
    "is painted white.  A channel of water flows "
    "beside the path."
    "  There is quite a view from here."
  );
  SetItems( ([
   ({ "desert", "sand", "sands" }) : "The immense desert expands "
        "out as far as they eye can see",
    "monestary" : "Vague outlines of a building break the sleak "
        "horizon to the north.",
    "yozrath" : "The city to the southwest appears only as a line of "
        "shadowy buildings, breaking the sleak horizon to the "
        "southwest.",
    "horizon" : "t is quite difficult to destinguish the horizon "
        "from the desert expanse.",
    ({ "border", "river", "river bjorn", "land" }) : "Far to the north the River "
        "Bjorn flows swiftly forming a natural border between the "
        "immense desert and the rest of the land.",
    ({ "structure", "roof" })  : "The large brownish structure is at "
      "the top of the minaret.  Something sticks out "
      "from its roof.",
    ({ "path", "ground", "stone" }) : 
        "The path is lined with stone and winds its way up the minaret.",
    "pool" : "The water from above lands inside this bowl-shaped "
        "pool before continuing on its path down the channel.",
    "minaret" : (: GetLong :),
    "level" : (: GetLong :),
    "water" : "The water flows down from the top of the "
      "minaret, providing sustenance to the array of flora.",
    "flora" : "The various flora growing upon the minaret "
      "are lush and beautiful.",
    ]) );
  SetItemAdjectives( ([
    "desert" : ({ "yozrath", "immense", "vast" }),
    "border" : ({ "northern" }),
    "path" : ({ "lined" }),
    "water" : ({ "flowing" }),
    "minaret" : ({ "white" }),
  ]) );
  if(query_night()) {
    SetInventory( ([
      MIN_NPC "/l_bug" : random(2) +1,
      MIN_OBJ "/grass" :1,
      MIN_OBJ "/view_t9" : 1,
      MIN_NPC "/worker" : random(2),
      MIN_OBJ "/channel" : 1,
    ]) );
  } else {
    SetInventory( ([
      MIN_OBJ "/grass" :1,
      MIN_OBJ "/view_t9" : 1,
      MIN_NPC "/worker" : random(2),
      MIN_OBJ "/channel" : 1,
    ]) );
  }
  SetListen( ([
    "default" : "The babbling sound of water trickles down the minaret.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
    ]) );
  SetExits( ([
    "west" : MIN_ROOMS "/path4t9",
    "north" : MIN_ROOMS "/path2t9",
  ]) );
}
