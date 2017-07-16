
#include <lib.h>
inherit LIB_NPC;

string COLOR_CHAMELEON;
string COLOR_ALONE;

static void create() {
   npc::create();
   SetProperty("jidnewbinoleave",1);
   switch(random(4)) {
      
      case 0:
      COLOR_CHAMELEON = "red chameleon";
      COLOR_ALONE = "red";
      break;

      case 1:
      COLOR_CHAMELEON = "blue chameleon";
      COLOR_ALONE = "blue";
      break;

      case 2:
      COLOR_CHAMELEON = "yellow chameleon";
      COLOR_ALONE = "yellow";
      break;

      case 3:
      COLOR_CHAMELEON = "green chameleon";
      COLOR_ALONE = "green";
      break;
   }
   SetKeyName("chameleon");
   SetShort("a " + COLOR_ALONE + " chameleon");
   SetId( ({ "chameleon","lizard" }) );
   SetAdjectives( ({ COLOR_ALONE }) );
   SetLong("This " + COLOR_CHAMELEON + " is about two inches long, "
           "including his wriggling tail.  He stays fairly still, "
           "moving along in a slow, lathargic way, his color changing "
           "slowly as he goes.");
   SetGender("male");
   SetRace("lizard");
   SetClass("animal");
   SetLevel(1);
}

