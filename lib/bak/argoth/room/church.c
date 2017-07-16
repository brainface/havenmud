#include <lib.h>
#include <vendor_types.h>
#include "../argoth.h"
inherit LIB_CHAPEL;
static void create() {
  chapel::create();
  SetAmbientLight(45);
  SetShort("the Church of Saahagoth");
  SetLong(
    "Upon entering the church, it is revealed that it is not several "
    "separate stories but one enormous chamber reaching hundreds of feet into "
    "the air.  Engravings in black marble run all the way up a set of pillars "
    "and a large altar is set in the middle of the room."
  );
  SetItems( ([
    ({ "church" }) :
    (: GetLong :),
    ({ "engravings" }) :
    "The engravings go into great detail, and appear to tell the story of the "
    "rise of Saahagoth.",
    ({ "black marble", "marble" }) :
    "Everything in the building seems to be made of a shiny black marble.",
    ({ "pillars"}) :
    "The pillars reach hundreds of feet and keep the building from caving in.",
    ({ "large altar", "altar" }) :
    "The altar is of a tall robed figure, holding out a bowl in one hand and "
    "a sphere of blue light in the other.",
    ({ "bowl" }) :
    "The bowl is carved from black marble and has a faint coating of deepest "
    "red.",
  ]) );
  SetClimate("indoors");
  SetListen( ([
    "default" : "Light chanting can be heard.",
  ]) );
  SetSmell( ([
    "default" : "The tang of old blood is faint in the air.",
  ]) );
  SetInventory( ([
    ARGOTH_NPC + "monk" : 2,
    ARGOTH_NPC + "diviner_leader" : 1,
    ARGOTH_NPC + "priest" : 1,
    ARGOTH_NPC + "cleric_trainer" : 1,
  ]) );
  SetExits( ([
    "out" : ARGOTH_ROOM + "rd7.c",
  ]) );
}
