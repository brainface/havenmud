#include <lib.h>
#include "../outpost.h"
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside the command tent");
  SetLong(
    "This large rectangular tent is very spacious.  It has high sloping ceiling "
    "with three orbs of light hanging from the ceilings highest point. Sitting "
    "right under the orbs, a large oval table stands in the middle of this white "
    "tent. Along the north wall is a large tapestry hanging from a horizontal "
    "wooden pole, which is one of the supporting beams for the tent walls. "
    "Placed in the rear of the tent, three cots are set up which look unused.");
  SetAmbientLight(40);
  SetClimate("indoors");
  SetItems( ([
    "tent" : ( :GetLong: ),
    "ceiling" :
    "The sloping ceiling is high enough by the entrance for very tall elves and "
    "humans to enter without ducking.",
    ({"orbs","orb"}) :
    "Three bright orbs hanging from the center of the tent light up the "
    "confines of the tent. The white canvas of the tent makes it seem "
    "brighter than it actually is.",
    ({"table","middle"}) :
    "In the middle of the tent, a large wooden oval table stands. Nailed to the "
    "table is map. There are documents scattered on top of the map.",
    ({"map","drawing","sketch"}) :
    "There seems to be a rough sketch of the ruins which lies north of the "
    "outpost nailed to the wooden table.",
    ({"document","documents"}) :
    "The documents seems to list the daily business of the inquisitors.",
    "north wall" :
    "A large tapestry hanging from the horizontal supporting beam.",
    ({"beam", "pole","walls","beams","poles"}):
    "There are four tall wooden vertical beams holding the tent up with "
    "horizontal wooden poles supporting the walls of the tent.",
    ({"tapestry","hanging","symbol"}) :
    "This wall hanging is that of the Kylin symbol of faith, a golden "
    "balance with a red dragon entwined around it.",
    ({"rear","back"}) :
    "In the rear of the tent has been placed three cots.",
    ({"cots","cot"}) :
    "Three unused cots rest in the back of the tent.",
    ]) );
  SetItemAdjectives(( [
    "tent"     : ({"large","rectangular","spacious","white","canvas"}),
    "ceiling"  : ({"high","sloping"}),
    "orbs"     : ({"bright","three","light","hanging"}),
    "table"    : ({"large","wooden","oval"}),
    "tapestry" : ({"large","wall"}),
    "beam"     : ({"wooden","vertical","horizontal","supporting","tall"}),
    "cots"     : ({"unused","three"}),
    ]) );
  SetExits( ([
    "out" : OP_ROOM + "staging_area4",
    ]) );
  SetSmell( ([
    "default" : 
    "There is a slighty musty odor in the air.",
    ]) );
  SetListen( ([
    "default" : 
    "The sound of hammering can be softly heard."
    ]) );
  SetInventory( ([
    OP_NPC + "archdeacon_monk" : 1,
    OP_NPC + "dwarf_commander" : 1,
    OP_NPC + "gm_inquisitor"   : 1,
    ]) );
}