/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 *  Minor editing by Laoise@Haven
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("a gothic stables");
  SetDomain("Planes");
  SetLong(
    "Cobweb filled haylofts loom ominiously casting shadows on the floor of "
    "this gothic stables. The stalls are locked with iron chains wrapped "
    "around the doors, and bats flutter about the ceiling." 

  );
  SetItems( ([
     ({"mirror"}) : "There is no god damned mirror here.",
     "bats" : "They look lost. Occasionally one thumps against a support post.",
     "stables" : "What FELL BEAST could dwell here?!",
     "doors" : "Many are cracked and warped, as if something were "
       "attempting to get out.",
     "ceiling" : "Far above looms a... barn ceiling. Very creepy.",
     ({"spiders","cobwebs"}) : "Huge fucking spiders nest in the cobwebs",
     
     ]) );
   SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",

  ]) );
  SetInventory( ([
         "/realms/mahkefel/npc/gammit" : 1,
              "/realms/mahkefel/verbs/loom" : 1,
       "/realms/mahkefel/verbs/spinny_wheel" : 1,
  ]) );
  SetListen("default", "Odd. You don't /see/ a pipe organ anywhere.");
  SetSmell("default", "Gothic. Yes, a very gothic smell.");
  //SetDoor("south" , MAHK_OBJ "pentagram.c");
}

