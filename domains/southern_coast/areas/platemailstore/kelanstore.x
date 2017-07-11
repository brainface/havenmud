#include <lib.h>
#include <damage_types.h>
#include "store.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   set_heart_beat(3);
   SetShort("Kelan's Quality Armour");
   SetClimate("indoors");
   SetAmbientLight(50);
   SetExits( ([
      "out" : OUT_DIR,
   ]) );
   SetLong(
     "This small building serves not only as a smithy, but as a point of "
     "sale for the articles produced here. It is owned by Kelan, a smith "
     "of near-legendary fame in this area of the world. His armour is "
     "considered the best by many great soldiers, as reflected by his "
     "prices. A small desk near the door serves as a place to carry out "
     "sales, while to the back of the building lies a large stone structure, "
     "which is obviously the forge itself."
   );   
   SetItems( ([
     ({ "building", "smithy" }) : (: GetLong :),
     ({ "armour" }) : "Various suits of armour line the walls, waiting to be "
       "purchased.",
     ({ "desk" }) : "This small desk is where Kelan conducts his business "
       "with customers.",
     ({ "door" }) : "The door leads outside, exiting the smithy.",
     ({ "forge", "back", "structure" }) : "At the back of the building lies "
       "the large forge, where Kelan creates his armour products.",      
   ]) );
   SetItemAdjectives( ([
      "building" : ({ "small" }),
      "armour" : ({ "suits of" }),
      "desk" : ({ "small" }),
      "forge" : ({ "large" }),
      "structure" : ({ "large", "stone" }),      
   ]) );   
   SetInventory( ([ 
      STORE_DIR + "kelan" : 1,
   ]) );
   SetProperties( ([
      "metal working" : 1,
      "natural working" : 1,
      "wood working" : 1,
      "leather working" : 1,
      "textile working" : 1,
      "mithril working" : 1,
   ]) );
}

void heart_beat() {
   object *inv;
   ::heart_beat();
   inv = filter(all_inventory(this_object()), (: living :));
   if(sizeof(inv)) 
   {
     foreach(object target in inv)
     {
       message("system", "%^YELLOW%^BOLD%^The heat from the "
         "forge makes the smithy uncomfortably warm.%^RESET%^", target);
     }
   }
   if(!sizeof(inv)) set_heart_beat(0);
}

void init() {
   ::init();
   set_heart_beat(90);
   heart_beat();
}
