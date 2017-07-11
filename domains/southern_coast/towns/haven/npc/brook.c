#include <lib.h>
#include "haven.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
  SetKeyName("Brook");
  SetShort("Brook, the owner of the Divine Chalice");
  SetId( ({ "brook", "owner", "waitress", "barkeep" }) );
  SetLong("Brook is a fine young elf that seems to have found "
          "her place. After the Templars closed down Yrslim's "
          "Tavern, the Groggy Sailor, she stepped in and helped "
          "to convince the Holy Government to allow her to re-open "
          "it if she kept the rogueish scum out that had been "
          "frequenting the tavern before.");
  SetRace("elf");
  SetGender("female");
  SetClass("merchant");
  SetLevel(6);
  SetMenuItems( ([ 
  	"water" : H_OBJ + "water",
    "beer"  : H_OBJ + "beer" 
    ]) );
  SetLocalCurrency("imperials");
  SetMorality(-200);
  SetCurrency("imperials", 200);
  }

mixed eventAsk(object who, string str) {
  if (who->GetTown() != "Haven") {
    eventForce("speak I only deal with loyal Citizens here!");
    return 1;
   }
 ::eventAsk(who, str);
 }
