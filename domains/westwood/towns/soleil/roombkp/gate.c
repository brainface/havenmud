#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

int PreExit();
int PreEnter();

static void create() {
  room::create();
  SetTown("Soleil");
  SetShort("entrance to Soleil");
  
  SetLong("A gently sloping ramp leads up into the gigantic helmock "
    "trees which tower overhead, shadowing the ground below.  "
    "The ramp leads up farther into Soleil.");
  SetItems( ([
    ({ "shadowed ground","ground" }) :
      "The ground is smooth and beaten along the "
      "road leading north, shadowed by the towering "
      "trees.  Young grass grows near the edges.",
    ({ "gigantic helmock trees","gigantic helmock tree",
      "gigantic tree","gigantic trees","gigantic helmock",
      "gigantic hemlocks","helmock tree","hemlock trees",
      "hemlocks","hemlock","tree","trees","towering trees",
      "towering tree" }) :
      "The trees extend up above, twining together "
      "to create a sky in and of themselves.  Green "
      "needles have fallen from them, dusting the "
      "ramp and ground.",
    ({ "green needles","green needle","needle","needles",
      "tips","tip" }) :
      "These needles, having come from hemlock trees, "
      "are rounded instead of pointy at the tips.  All "
      "are green, and many, instead of clinging where they "
      "belong on the trees, have fallen down onto the "
      "ground and ramp here.",
    ({ "entrance","soleil" }) : (: GetLong :),
    ({ "gently sloping ramp","sloping ramp","ramp",
      "solid boards of wood","solid boards","boards"
      "solid board of wood","solid board","board",
      "board of wood","boards of wood","wood" }) :
      "Solid boards of wood are hammered together "
      "to form the ramp, heading upwards at a slow "
      "pace that is easy to walk.  Needles, fallen from "
      "the trees, have gathered on the ramp.",
  ]) );
  SetSmell( ([ 
    "default" : "Sweet pine smells fill the air.",
  ]) );
  AddExit("down","/domains/westwood/virtual/westwood/18,15",(:PreExit:));
  AddExit("up", S_ROOM + "tree_a",(:PreEnter:));
  SetInventory( ([
    S_NPC + "guard_gate" : 2,
//  S_NPC + "knight" : 2,
//  S_NPC + "priest_dedan_1" : 1,
  ]) );
}

int PreExit() {
  if(this_player()->GetProperty("soleilnoleave")) return 0;
  return 1;
}

int PreEnter() {
if(present("guard")) {
  if((this_player()->GetMorality() < -350) &&
      (this_player()->GetLevel() > 25)) {
    message("system","The guards block your exit.",this_player());
    return 0;
    }
  }
  return 1;
}
