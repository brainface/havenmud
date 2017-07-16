#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetClimate("indoors");
   
   SetAmbientLight(40);
   SetShort("in a small room");
   SetLong("Candles are spread around the room in no particular pattern, "
           "just however it seemed they would best light the room at the "
           "time.  The floor is just like those of the platforms; in "
           "fact, that appears to be just what it is.  A hole in the "
           "center provides space for a wooden ladder to go through; "
           "the ladder heads down.");
   SetItems( ([
                ({ "wooden ladder","ladder" }) :
                   "A ladder goes down through a small hole in the center "
                   "of the room; it is the only exit.",
                ({ "central hole","hole","small hole" }) :
                   "The hole is plain and has no distinguishing marks, "
                   "but it is the only one in the room.  A wooden "
                   "ladder goes down through it, the only exit from this "
                   "room.",
                ({ "room walls","room wall","walls","wall" }) :
                   "The walls go around the floor in a circle.  They "
                   "are completely unbroken.",
                ({ "room floor","floor","platform","platforms" }) :
                   "The floor is like a platform, but the room is "
                   "covered and has walls.  Candles are everywhere on "
                   "it.",
                ({ "lit candles","lit candle","candles","candle" }) :
                   "The candles are lit, their flames dancing in the "
                   "light breeze that wafts through the room.  "
                   "They are all over the place, lighting the "
                   "room.",
                ({ "small room","room" }) :
                   (: GetLong :),
           ]) );
   SetSmell( ([
                "default" : "The odor of smoke hangs in the air.",
           ]) );
   SetExits( ([
                "down" : M_ROOM + "plat_g",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_j" : 3,
               ]) );
}


/* Approved by Ukla on Thu Mar  5 19:00:22 1998. */
