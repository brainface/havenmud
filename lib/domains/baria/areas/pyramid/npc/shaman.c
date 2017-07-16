/*                                                                 */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: shaman.c
// Area: the dark pyramid
//

#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("old shaman");
  SetShort("an old shaman");
  SetId( ({ "shaman","old shaman","human" }) );
  SetRace("human");
  SetClass("shaman");
  SetGender("male");
  SetMorality(-150);
  SetLevel(16 + random(5));
  SetLong("This old person was once wandering the jungle but he got "
          "lost and ended up in the pyramid, where he decided to "
          "stay and guard it from attackers. "
          "He is strong and knows the arts of magic."
         );
  
  SetReligion("Kuthar","Kuthar");
  SetLanguage("Barian", 100);
  SetSpellBook( ([
			"acid blast"		: 100,
		  "bone shell"    : 100,
		  "mangle"        : 100,
		  "asphyxiation"  : 100,
		  "crush"         : 100, 
			]) );
 SetCombatAction(80, ({
      "!cast acid blast",
      "!cast bone shell",
			"!cast mangle",
			"!cast asphyxiation",
			"!cast crush",	
                 }) );
  SetCurrency("crystals", 25 + random(11));
  SetInventory( ([
     P_OBJ + "/black_robe" : "wear robe"
     ]) );
}
