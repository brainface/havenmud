/* the dining room
      kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a large dining room");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This huge dining room has an enormous table in the center which "
          "is surrounded by tall chairs. The room looks as though the family "
          "that lives in the mansion eats here everyday. A large centerpiece "
          "sits in the middle of the table. To the west lies the kitchen and "
          "to the east lies the ballroom.");
  SetItems( ([
    ({ "dining room", "room" }) : (:GetLong:),
       "table" : "The enormous table looks to be made of oak.",
    ({ "chairs", "chair" }) : "The chairs match the table and are quite tall.",
    ({ "large centerpiece", "centerpiece" }) : "The centerpiece is quite pretty.",
    ]) );
  SetItemAdjectives( ([
      "table" : ({"enormous", "oak" }),
      "chairs" : ({ "tall" }),
      "large centerpiece" : ({ "pretty"}),
           ]) );
  SetExits( ([
        "west" : MANSION_ROOMS + "5a",
        "east" : MANSION_ROOMS + "7a",
       ]) );
  SetInventory( ([
        MANSION_NPC + "maid2" : 1,
         ]) );
  SetSmell( ([
      "default" : "The scent of food drifts in from the kitchen.",
           ]) );
  SetListen( ([
      "default" : "The sounds of the party come from the ballroom.",
           ]) );
  }
