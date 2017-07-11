/*a shepherd
  kyla
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("shepherd");
  SetShort("a strong young man");
  SetLong("This young man looks very responsible and seems to take great pride "
         "in his goats.");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "young", "strong"}) );
  SetFriends( ({"goat"}) );
  SetGender("male");
  
  SetRace("human");
  SetClass("evoker");
  SetLevel(9);
  SetSpellBook( ([
  		"buffer"  : 90,
  		"missile" : 90,
  	  ]) );
  SetAction(6, ({"The young man looks at you warily."}) );
  SetCombatAction(40, ({
  		"!cast buffer",
  		"!cast missile",
  	  }) );
  SetMorality (250);
  	
  SetCurrency( (["imperials" : random(10) + 5]) );
  SetInventory( ([
      MANSION_OBJ + "cotton_shirt" : "wear shirt",
      MANSION_OBJ + "sstaff" : "wield staff",
      ]) );
  }
