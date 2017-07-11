#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("inside the moneylenders");
  SetExits( ([
    "out" : "path9",
  ]) );
  SetLong("The small home of the moneylender is spartan in accomidation and "
          "has little to suggest the owner is anything but frugal. "
          "The only decoration is a small floral arrangement of "
          "chrysanthemums near the west wall.");
  SetAmbientLight(40);
  SetItems( ([
    "home" : (: GetLong :),
    "wall" : "An arrangement of chrysanthemums grow near the "
    				"west wall.",
    ({ "flowers", "flower", "chrysanthemum", "arrangement" }) :
       "This small arrangement of flowers brightens the room.",
    ]) );
  SetItemAdjectives( ([
    "home"    : "small",  
    "flowers" : "floral",
    ]) );
  SetSmell( ([
    "default" : "The scent of the flowers fills the room.",
    ]) );
  SetListen( ([
    "default" : "The home is very quiet.",
    ]) );
  SetInventory( ([
    TAI_RI_NPC "banker" : 1,
    ]) );
}
