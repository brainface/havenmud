#include <lib.h>
inherit LIB_ROOM;
#include "ditmar.h"

static void create() {
   room::create();
   SetTown("Ditmar");
   SetClimate("indoors");
   SetAmbientLight(15);
   SetShort("Ditmar Barracks");
   SetLong("The large cave set aside for the Ditmar Barracks is smoothed "
           "in some areas, but for the most part, stalagmites and "
           "stalactites of various sizes and shapes create obstacles "
           "for training beings.  A small opening leads out to the east.  "
           "Near the opening is some furniture.");
   SetItems( ([
                ({ "ditmar barracks","barracks","ditmar","cave",
                   "large cave" }) :
                   (: GetLong :),
                ({ "stone obstacles","obstacles","obstacle","stalagmite",
                   "stalagmites","stalactites","stalactite" }) :
                   "The stalgmites and stactites are beautiful, "
                   "colored in shades of all the rainbow.  Some were "
                   "allowed free reign as they formed, but others have "
                   "been rubbed back to make some space for people to "
                   "train.",
                ({ "small opening","opening" }) :
                   "To the east is a small opening leading out into the "
                   "rest of Ditmar.",
                ({ "stone furniture","furniture","benches","bench" }) :
                   "The furniture is stone, in the form of a few "
                   "benches.  It is plain but looks like it would be a "
                   "good rest for a sore and tired body.",
           ]) );
   SetItemAdjectives( ([
                         "obstacles" : ({ "stone" }),
                         "furniture" : ({ "stone" }),
                    ]) );
   SetSmell( ([
                "default" : "The barracks, more enclosed than the "
                   "rest of Ditmar, smells of darker, deeper, and more "
                   "hidden air.",
           ]) );
   SetExits( ([
                "east" : D_ROOM + "/cave_a",
           ]) );
   SetInventory( ([
                    D_NPC + "/fighter" : 1,
                    D_NPC + "/sorctr" : 1,
               ]) );
}