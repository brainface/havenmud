#include <lib.h>
#include "../lodge.h"
inherit LIB_ROOM;

 static void create() {
   room::create();
  SetShort("a hidden pit");
  SetDayLong("This pit is lightly lit with burning torches. A throne has been "
         "gently placed in the corner, showing some sort of high authority. "
         "This room has a rank smell of decay shown by the small piles of "
         "bones that lie around.");
  SetNightLong("This pit is lightly lit with burning torches. A throne has been "
         "gently placed in the corner, showing some sort of high authority. "
         "Old, rusty chalices have been carelessly thrown around. "
         "This room has a rank smell of decay shown by the small piles of "
         "bones that lie around.");
   SetAmbientLight(15);
   SetClimate("underground");
   SetItems( ([
        "pit" : (:GetLong:),
         ({"torches", "torch"}) : "These torches look like they have been "
         "burning for sometime.  They are made out of decaying bones "
         "and dimly light the room.",
         ({"throne", "chair"}) : "This throne seems to be made for someone "
         "of high authority.  Like most things in the room, it seems to be "
         "made out of bones and skin.  It looks awfully uncomfortable to "
         "sit in.",
         ({"chalice","chalices","cup"}) : "These chalices are old and rusty.  No "
       "being with common sense would dare put their mouth on these.  ",
         ({"bones", "pile"}) : "These bones belong to some animal that has "
         "been turned into a meal. They give off a raunchy smell.  The sight "
       "of this is not pretty.",
   ]) );
   SetItemAdjectives( ([
         "throne" : ({"uncomfortable"}),
         "chalice" : ({"old","rusty"}),
   ]) );
   SetExits( ([
         "north" : L_ROOM + "guardroom.c",
   ]) );
   SetInventory( ([
   L_NPC + "lord" : 1,
   ]) );
   SetSmell( ([
         "default" : "It smells like sweat and careless hygeine.  It is quite gross.",
   ]) );
   SetListen( ([
         "default" : "Shifting armour and slight mumbling can he heard.",
   ]) );
 }
