#include <lib.h>
#include "../haven.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("Alpacha's Stable");
   SetClimate("indoors");
   SetAmbientLight(50);
   SetExits( ([
      "out" : "../galleons_passage/gp1",
   ]) );
   SetLong(
     "This small stable is home to the local mule seller. Stabled along the outside "
     "walls of this large wooden barn are several mules which look ready and able "
     "to carry belongings both far and wide. Mule feed is strewn across the floor and "
     "other, less desirable, lumps dot the view."
   );
   SetItems( ([
      ({ "lump", "lumps" }) : "These lumps are small, wet, and brown.",
      ({ "feed" }) : "The feed is strewn on the floor without rhyme or reason.",
      ({ "stable", "stables" }) : "The stables are small and appear uncomfortable.",
      ({ "mule", "mules" }) : "The mules look thoroughly bored with life.",
   ]) );
   SetInventory( ([ 
      H_NPC + "mule_seller" : 1,
   ]) );
 SetSmell( ([
   "default" : "The stable smells like... a stable.  And not a nice one, either.",
   "lump"    : "The lumps smell foul... and brown.",
   ]) );
}


/* Approved by Haun on Tue Apr 27 21:17:22 1999. */
