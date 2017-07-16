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
  SetShort("the Rock barracks");
  SetLong(
    "Simple grey stones form the walls and floor of this building, appearing "
    "to have been worked so that they slot together tightly. On the north "
    "and south walls a larger, rougher rock the color of dried blood is "
    "embedded, standing out starkly against the plain grey stone of the rest "
    "of the walls. Beneath each red rock there are multiple weapon racks set "
    "up against the walls. A plain and unadorned door is cut from the east "
    "wall and appears to lead back to the Karak Road. No other exits are "
    "visible."
  );
  SetItems( ([
    ({ "building", "barracks" }) : (: GetLong :),
    ({ "wall", "walls" }) : "The walls are made of a simple grey stones, "
    "fitted tightly together. On the north and south walls are embedded "
    "a single rock the color of dried blood.",
    ({ "rock", "rocks" }) : "A large red rock is embedded in both the north "
    "and south wall of the building.",
    ({ "floor" }) : "The floor remains flat and solid, made of the same "
    "stone as the walls, but a darker color in some places due to repetitive "
    "usage.",
    ({ "rack", "racks" }) : "These are sturdy racks, designed to hold training "
    "weapons when they are not in use.",
    ({ "door" }) : "This is a plain door set in to the east wall, leading "
    "back to the Karak Road.",
  ]) );
  SetItemAdjectives( ([
    "building" : ({ "axe", "stone", "simple" }),
    "wall" : ({ "simple", "grey", "stone", "barrack", "north", "south" }),
    "rock" : ({ "dried", "blood", "red", "large", "embedded" }),
    "floor" : ({ "plain", "grey", "stone", "darkened", "darker", "barracks" }),
    "rack" : ({ "sturdy", "weapon", "training", "barrack" }),
    "door" : ({ "plain", "east", "wall" }),
  ]) );
  SetSmell( ([
    "default" : "The pungent reek of sweat has been absorbed in to the "
    "very walls.",
  ]) );
  SetListen( ([
    "default" : "The eerie silence before battle hangs in the air.",
  ]) );
  SetInventory( ([
    KARAK_NPC + "leader_evoker" : 1,
    KARAK_NPC + "lieut" : 1,
  ]) );
  SetExits( ([
    "out" : KARAK_ROOM + "rd2",
  ]) );
}
