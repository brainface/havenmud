#include <lib.h>
#include "../minaret.h"

inherit LIB_ROOM;



int PreventLeaveMinaret();
static void create() {
  room::create();
  SetClimate("arid");
  SetShort("before an observatory");
  SetLong(
    "The path along the minaret is lined with stone and has a "
    "small channel running along side of it, flowing with water "
    "from inside the obeservatory.  The minaret itself has been "
    "painted white.  The observatory is a simple sructure made "
    "from some form of brownish resin."
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

    ({ "path", "ground", "stone" }) : 
        "The path is lined with stone and winds its way up the minaret.",
    "minaret" : (: GetLong :),
    ({ "observatory", "resin", "structure", "opening", "roof"  }) : 
      "The observatory is a large "
      "brownish structure made from some form of "
      "resin.  A telescope sticks out of the opening in "
      "the roof.  A small opening at the bottom allows "
      "for the channel of water to flow down the minaret.",
    "telescope" : "The telescope sticks out from an "
      "opening in the roof.",
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
  SetListen( ([
    "default" : "The babbling sound of water "
      "trickles down the minaret.",
    ]) );
  SetSmell( ([
    "default" : "The arid air carries the scent of the sand.",
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
  SetExits( ([
    "east" : MIN_ROOMS "/path3t9",
  ]) );
  AddEnter("observatory", MIN_ROOMS "/observatory", 
    (: PreventLeaveMinaret :) );
}

int PreventLeaveMinaret() {
    if (this_player()->id("minaret_wander")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
    if (this_player()->GetProperty("minaretnoleave")) {
      if (this_player()->GetOwner() == "")
        return 0;
      }
  return 1;
}
