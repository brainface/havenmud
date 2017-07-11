/* This is a booth where one might find unusual odds and ends to buy. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a trinket booth");
  SetLong("This is another small booth that is covered by a "
     "canopy. There are all sorts of unusual odds and ends sitting "
     "on the table in the center of the booth. Most of the items "
     "are cheap trinkets and baubles that one might purchase "
     "as a gift. More shopping booths are to the east and west.");
  SetItems( ([
   ({ "booth" }) : "The booth is fashioned from a plaid canvas canopy supported by four wooden poles in the ground.",
   ({ "canopy" }) : "It is made of a thin, plaid canvas.",
   ({ "table" }) : "It is a simple wooden table with some cryptic figures etched into the wood.",
   ({ "trinket", "trinkets" }) : "There are small jewelry boxes, figurines, and polished stones.",
   ({ "bauble", "baubles" }) : "There are small jewelry boxes, figurines, and polished stones.",
   ({ "odds and ends" }) : "There are small jewelry boxes, figurines, and polished stones.",
   ({ "canvas" }) : "The canvas has a faded plaid pattern on it.",
   ({ "figure", "figures" }) : "These etchings seem to have been made with a knife.",
   ({ "box", "boxes" }) : "Some of the wooden jewelry boxes have little beads glued to the top while others have pictures carved into the surface.",
   ({ "figurine", "figurines" }) : "These are hand-carved dolls in the shapes of animals.",
   ({ "stone", "stones" }) : "There are stones of every color in the rainbow that have been polished smooth.",
  ]) );
  SetItemAdjectives( ([
     "booth" : ({ "small" }),
     "canopy" : ({ "canvas" }),
     "canvas" : ({ "thin", "plain" }),
     "odds and ends" : ({ "unusual" }),
     "trinkets" : ({ "cheap" }),
     "baubles" : ({ "cheap" }),
     "box" : ({ "jewelry", "small" }),
     "stone" : ({ "polished" }),
  ]) );
  SetExits( ([
     "west" : BAZAAR_ROOM "carpet",
     "northwest" : BAZAAR_ROOM "tree",
     "north" : BAZAAR_ROOM "juggle",
     "east" : BAZAAR_ROOM "acc",
  ]) );
  SetInventory( ([ BAZAAR_NPC + "cainwyn" : 1, ]) );
  SetSmell( ([
     "default" : "The smell of food drifts in from the west.",
  ]) );
  SetListen( ([
     "default" : "You hear laughter and people haggling over prices.",
  ]) );
}
