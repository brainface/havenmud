#include <lib.h>
inherit LIB_NPC;

void eventColorChange();
string COLOR_CHAMELEON;
string COLOR_ALONE;

static void create() {
   npc::create();
   eventColorChange();
   SetKeyName(COLOR_CHAMELEON);
   SetShort("a " + COLOR_CHAMELEON);
   SetId( ({ "chameleon","lizard" }) );
   SetAdjectives( ({ COLOR_ALONE }) );
   SetLong("This " + COLOR_CHAMELEON + " is about two inches long, "
           "including its wriggling tail.  It stays fairly still, "
           "moving along in a slow, lathargic way, its color chaning "
           "slowly as it goes.");
   SetLevel(1);
   SetRace("lizard");
   SetClass("animal");
}

void eventColorChange() {
   switch(random(4)) {
      
      case 0:
      COLOR_CHAMELEON = "%^RED%^red chameleon%^RESET%^";
      COLOR_ALONE = "red";
      break;

      case 1:
      COLOR_CHAMELEON = "%^BLUE%^blue chameleon%^RESET%^";
      COLOR_ALONE = "blue";
      break;

      case 2:
      COLOR_CHAMELEON = "%^YELLOW%^yellow chameleon%^RESET%^";
      COLOR_ALONE = "yellow";
      break;

      case 3:
      COLOR_CHAMELEON = "%^GREEN%^green chameleon%^RESET%^";
      COLOR_ALONE = "green";
      break;
   }
   return;
}
