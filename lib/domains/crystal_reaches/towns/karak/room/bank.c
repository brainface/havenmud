// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include "../karak.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("the Karak Bank");
  SetLong(
    "A plain wooden table sits in the center of a simple wooden room. Rough "
    "wooden beams are worked sufficiently to be well-fitted but not to be "
    "decorative or attractive. Shelves line the west wall of the room, bolted "
    "in to the wall and holding some of the implements of the moneylender's "
    "trade, including a balance. A strongbox, banded with iron, is bolted to "
    "the floor in the center of the room, beneath the table. An exit to the "
    "east leads back to the main road through town."
  );
  SetItems( ([
    ({ "room", "bank" }) : (: GetLong :),
    ({ "table" }) : "This plain wooden table sits in the center of the room, "
    "located above a strongbox which is bolted to the floor.",
    ({ "beams", "beam", "wall", "walls" }) : "Rough wooden beams form the "
    "walls of this room, worked so that they fit tightly together, but not "
    "decorated or well-finished.",
    ({ "shelf", "shelves", "items", "item" }) : "Simple wooden shelves built "
    "of the same wood used to form the walls are bolted to the west wall of "
    "the room. They hold some of the items of the moneylender's trade, "
    "including a balance and chemicals to help test the authenticity of "
    "submitted coins.",
    ({ "balance", "scales", "scale" }) : "A metal balance, sometimes called "
    "scales, with bowls on either side to hold coins or gems. A moneylender "
    "could use this to compare the value of currency by weight or as part of "
    "an effort to evaluate fakes.",
    ({ "chemical", "chemicals", "jar", "jars" }) : "Several small glass jars "
    "contain chemicals that moneylenders can use to evaluate if coins or gems "
    "are fakes.",
    ({ "strongbox", "box" }) : "An iron-bound strongbox is bolted to the "
    "floor of the room, underneath the plain wooden table.",
    ({ "exit" }) : "An exit to the east leads to the main road of Karak.",
  ]) );
  SetItemAdjectives( ([
      "table" : ({ "plain", "wooden", }),
      "room" : ({ "simple", "wooden" }),
      "beams" : ({ "rough", "wooden", "worked", "fitted", "wall", "walls" }),
      "shelf" : ({ "simple", "wooden", "wood", "bolted", "west", "wall" }),
      "strongbox" : ({ "strong", "wood", "iron", "banded", "bolted" }),
      "exit" : ({ "east" }),
  ]) );
  SetSmell( ([
    "default" : "The smell of freshly-cut wood drifts from the boards.",
  ]) );
  SetListen( ([
    "default" : "It is quiet here, but faint noises can be heard outside.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "teller" : 1,
    KARAK_NPC + "leader_merchant" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd6",
  ]) );
}

// An add action to satisfy people who will try to pick the strongbox
void init() {
  ::init();
  add_action("pick", "pick");
}

int pick() {
  this_player()->EventPrint("Despite your best efforts, this lock cannot "
  "be picked");
  return 1;
}
