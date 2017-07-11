#include <lib.h>
inherit LIB_NPC;
#include "../jidnewbi.h"

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   SetKeyName("sprite child");
   SetShort("a sprite child");
   SetId( ({ "sprite","child" }) );
   SetAdjectives( ({ "sprite" }) );
   SetLong("The child grins impishly, innocent of all the world and "
           "intent on playing.");
   switch(random(2)) {

      case 0:
      SetGender("male");
      break;

      case 1:
      SetGender("female");
      break;
   }
   SetRace("sprite");
   SetClass("rogue");
   SetLevel(1);
   SetInventory( ([
       JD_OBJ + "/stick_fresh" : "wield stick in right hand",
       ]) );
}


/* Approved by Zaxan on Sat Jan 17 02:17:04 1998. */
