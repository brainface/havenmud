#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("the Eclat Tavern");
   SetLong("A wooden ladder goes down to the world below through a "
           "hole in the floor.  Nearby is a mat used for wiping off "
           "feet; it is clogged with mud and similar debris from the "
           "forest.  The walls are circular, and this tavern seems larger "
           "than the one below; it also doesn't have a flat wall on the "
           "northeast.  Instead, the counter curves to match the way the "
           "wall is shaped.");
   SetItems( ([
                ({ "curving counter","counter" }) :
                   "The counter turns with the wall as it forms a circle, "
                   "proving lots of space to sit at and set things on.  "
                   "It is up against about one fourth of the wall.",
                ({ "circular walls","circular wall","walls","wall" }) :
                   "The walls form a perfect circle.  There is a counter "
                   "that curves with it exactly on the northeast side.",
                ({ "eclat tavern","tavern","room","world" }) :
                   (: GetLong :),
                ({ "wooden ladder","ladder" }) :
                   "The ladder leads down to another tavern that is "
                   "below.  It has access through a simple hole in the "
                   "floor.  The ladder itself is plain and simple, with "
                   "no adornments.",
                ({ "simple hole","hole" }) :
                   "A simple hole surrounds the ladder as it goes down "
                   "to the other tavern.  It was carefull cut in to "
                   "allow passage between the two areas.",
                ({ "tavern floor","floor" }) :
                   "The floor is mostly clean; a plain mat is used to "
                   "wipe off feet, and it is placed near the ladder.  "
                   "The ladder is the only access to this room.",
                ({ "plain mat","mat","mud","debris" }) :
                   "The mat is pretty dirty, as it is obviously used "
                   "frequently to remove mud and similar such from ones "
                   "feet or boots.",
                ({ "other tavern","tavern" }) :
                   "The other tavern is below, through the hole and down "
                   "the ladder.",
           ]) );
   SetListen( ([
                 "default" : "Laughter is everywhere.",
            ]) );
   SetExits( ([
                "down" : M_ROOM + "tavern",
           ]) );
   SetInventory( ([
                    M_NPC + "bar_k" : 1,
                    M_NPC + "monk_j" : 1+random(3),
                    M_NPC + "monk_h" : 1+random(2),
               ]) );
}

int CanRecieve() {
   if(immortalp(this_player())) return 1;
   if(this_player()->GetReligion()=="Eclat") {
      message("system","%^BLUE%^Welcome.%^RESET%^",this_player());
      return 1;
   }
   message("system","I'm sorry, only those of the Eclat faith may "
           "enter.",this_player());
   return 0;
}