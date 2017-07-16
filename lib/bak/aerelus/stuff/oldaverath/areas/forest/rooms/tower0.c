#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a tower");
  SetLong("Small torches spaced evenly along the walls of the tower light the "
          "room with an eerie mystique. The smooth, stone floor is spotlessly "
          "clean, as are the walls.");
  SetAmbientLight(40);
  SetClimate("indoors");
  SetItems( ([
    ({ "torch", "torches" }) : "The torches provide eerie illumination.",
    ({ "floor", "wall", "walls" }) : "The walls and floor almost shine with "
      "cleanliness."
  ]) );
  SetItemAdjectives( ([
    "torch" : "small",
    "floor" : ({ "smooth", "stone" })
  ]) );
  SetInventory( ([
    AVERATH_NPC + "mage_leader" : 1
  ]) );
  SetExits( ([ "out" : AVERATH_ISLAND + "8,-3,0" ]) );
}
