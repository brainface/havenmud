#include <lib.h>
#include "../outpost.h"
#include <domains.h>imm

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("inside a tent");
  SetLong(
    "This large rectangular tent is very spacious but a row of cots lines the "
    "northern and southern walls taking up a lot of pace. With eight cots in "
    "each row, the head of each cot is up against its respective wall. A small "
    "wooden table has been set up near the rear of the tent with a balance "
    "resting on top of it. There are numerous cloth mats arranged in a semi-"
    "circle around the wooden table.");
  SetAmbientLight(20);
  SetClimate("indoors");
  SetItems( ([
    "tent" : ( :GetLong: ),
    ({"row","rows"}) :
    "There are two rows of cots inside this tent. Each row is lined up against "
    "northern and southern walls.",
    ({"wall","walls"}) :
    "The white canvas walls of the tent seems to give off a glow. Placed against "
    "the northern and southern wall is a row of eight cots.",
    ({"cots","cot"}) :
    "Each canvas and wood cot is places against the wall and looks very "
    "comfortable.",
    ({"table","altar"}) :
    "This small wooden table has been set up in the back of the tent to act as "
    "an altar. A white canvas cloth rests on top of the table with a gold "
    "balance with a dragon entwined around it.",
    ({"balance","symbol"}) :
    "Sitting on top of the small altar is the symbol of the Kylin faith, a "
    "balance with a dragon entwined around it.",
    "cloth" :
    "Stitched into this white canvas cloth is the Kylin symbol of faith, a "
    "balance with a dragon entwined around it. The cloth is resting on the "
    "altar.",
    ({"mat","mats","pattern"}) :
    "There are numerous cloth mats arranged around the altar in a semi-circle "
    "pattern.",
    ]) );
  SetItemAdjectives(( [
  	"tent"    : ({"large","rectangular","spacious","white","canvas"}),
  	"cots"    : ({"eight","canvas","wood"}),
  	"table"   : ({"small","wooden"}),
  	"cloth"   : ({"white","canvas"}),
  	"mat"     : ({"cloth","numerous"}),
  	"pattern" : ({"semi-circle"}),
  	"wall"    : ({"north","south","white","canvas"}),
  	"balance" : ({"gold","kylin","faith"}),
    ]) );
  SetExits( ([
    "out" : OP_ROOM + "staging_area2",
    ]) );
  SetSmell( ([
    "default" : 
    "The air has a slight musty odor.",
    ]) );
  SetListen( ([
    "default" : 
    "An eerie silence fills the tent."
    ]) );
  SetInventory( ([
    OP_NPC + "inquisitor_offduty" : random (6) + 1,
    ]) );
}