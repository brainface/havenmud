/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("dwarven soldier");
  SetId( ({"dwarf","soldier","warrior",}) );
  SetAdjectives( ({"dwarven","stern",}) );
  SetShort("a dwarven soldier");
  SetLong("The soldier looks very stern as he inspects his equipment.");
  
  
  SetMorality(random(100) + 100);
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(15 + random(10));
  SetGender("male");
  SetAction(12,({
                 "The soldier carefully hones his weapon.",
                 "The soldier scans the ridge surrounding the valley.",
                 "The soldier searches the surrounding mountains, watching "
                   "for movement.",
            }) );
  SetFriends( ({ "dwarven leader" }) );
  SetCurrency("nuggets", random(25)+1);
  SetInventory(  ([
		VALLEY_OBJ + "/chainmail" : "wear chainmail",
		VALLEY_OBJ + "/axe" : "wield axe",
		VALLEY_OBJ + "/kilt" : "wear kilt",
		VALLEY_OBJ + "/boots" : "wear boots",
		])  );
}
