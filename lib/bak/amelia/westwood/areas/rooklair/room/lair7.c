#include <lib.h>
inherit LIB_ROOM;
#include "../rook.h"
 
static void create() {
  room::create();
  SetDomain("WestWood");
  SetShort("a twisted tunnel");
  SetLong("Inside this section of tunnel is a huge chasm leading down."
    "  Small tufts of fur laying about on the ground as though some "
    "small rodent has been fighting here.  The walls are untouched by "
    "any living person and are still naturally rough looking.  A small "
    "rope dangles down into the depths of the chasm and a tunnel leads "
    "to the southeast.");
  SetItems( ([
    ({"tunnel"}) : (:GetLong:),
    ({"chasm"}) : "The chasm is large in size and leads deep into the "
      "earth.",
    ({"fur","ground","rodent"}) : "Small tufts of fur lay about on the "
      "ground.  They appear to be rodent fur.",
    ({"wall","walls"}) : "The wall are naturally rough looking and "
      "dont appear to be have ever been touched by a living being.",
    ({"rope"}) : "This rope appears to be made of a silk.  It is smooth "
     "and just dangles down through the opening of the chasm.",
  ]) );
  SetItemAdjectives( ([
    "tunnel" : ({"section","of"}),
    "chasm" : ({"huge"}),
    "fur" : ({"tuft","tufts","of"}),
    "wall" : ({"untouched","rough","natural","naturally","looking"}),
    "rope" : ({"chasm","smooth","silk","dangling"}),
  ]) );
  SetExits( ([
    "southeast" : R_ROOM + "lair6",
  ]) );
  SetInventory( ([
    R_NPC + "rat" : 10,
    R_OBJ + "rope3" : 1,
  ]) );
  SetAmbientLight(0);
  SetClimate("indoors");
  SetSmell( ([
    "default" : "The room smells of moisture and mold.",
  ]) );
  SetListen( ([
    "default" : "Small echos of squeaks fill the room.",
  ]) );
}
