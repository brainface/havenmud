#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("indoors");
     SetShort("a large bedroom");
      SetLong("This large, fairly open room seems to be in slightly better repair "
        "than the rest of the keep. A large four-poster bed takes up most of "
        "the far-left wall, and a large carpet obscures the stone floor. At the foot "
        "of the bed, a large fireplace is carved out of the wall, above it rests "
      "the Duke's coat of arms.");
     SetItems( ([
        ({ "room", "bedroom"}) :
                 "This room appears to serve as the Duke’s bedroom.",
        ({ "carpet" }) :
                 "The rat eaten carpet that covers the floor was once grand, "
                   "but alas, it is grand no longer.",
      ({ "bed" }) : "This large bed appears to have once been comfortable."
      " Now, however, it is heavily discolored and missing a bed post. ",
        ({ "fireplace" }) : "The fireplace seems to be hiding something.",
        ({ "coat-of-arms", "coat of arms" }) : "The large shield bearing the Duke's "
      "coat-of-arms has been rusted over completely.",
           ]) );
    SetSmell( ([
                "default" : "The horrible smell of rust, soiled carpet, and" 
                       "sweat fills the air."
                       ]) );
    SetListen( ([
                "default" :  "The scratching of rodents can be heard.. "
             ]) );
  SetInventory( ([
    AVERATH_NPC "duke" : 1,
    ]) );
  SetEnters( (["fireplace" : AVERATH_UNDERGROUND "1,1,-1" ]) );
     SetExits( ([
          "south" : AVERATH_CITY + "keep3",
                   ]) );
}
