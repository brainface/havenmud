#include <lib.h>
#include "../path.h"
inherit LIB_SAGE;

static void create() {
	 sage::create();
	 SetKeyName("dorscha");
	 SetShort("Dorscha, Glimmerdin's Minister of Tourism");
	 SetId( ({ "dorscha", "minister", "dwarf", "glim_wander" }) );
	 SetAdjectives( ({ "tourism", }) );
	 SetLong(
	   "Dorscha is one of the rare dwarves that have no facial hair. "
	   "She is here to help adjust people to the language of "
	   "the great city of Glimmerdin."
	   );
	 SetGender("female");
	 SetRace("dwarf");
	 SetLanguage("Eltherian", 100);
	 SetLanguage("Sprith", 100);
	 SetClass("merchant");
	 SetLevel(15);
   SetLocalCurrency("nuggets");
   SetCharge(150);  
	 SetMorality(35);
	 SetAction(8, ({
	 	"!speak You could <ask dorscha to teach> runic, eltherian, or sprith!",
	 	"!speak in eltherian You could <ask dorscha to teach> runic, eltherian, or sprith!",
	 	"!speak in sprith You could <ask dorscha to teach> runic, eltherian, or sprith!",
	 	}) );
}
