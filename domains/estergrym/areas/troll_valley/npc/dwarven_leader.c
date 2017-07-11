/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

static void create(){
  npc::create();
  SetKeyName("dwarven leader");
  SetId( ({"leader","dwarf",}) );
  SetAdjectives( ({"dwarven","stern",}) );
  SetShort("a dwarven leader");
  SetLong("The leader stands ready to fight, waiting for his enemy to show "
          "its face.");
  
  SetMorality(random(200) + 50);
  SetRace("dwarf");
  SetClass("fighter");
  SetLevel(random(15) + 15);
  SetGender("male");
  SetAction(8,({
                 "The dwarven leader spends a moment scanning the area for "
                   "trouble.",
                 "!say We'll get them when they come out.",
                 "!say One cannot slay the Duke's family and expect to get "
                   "away with it.",
           }) );
  SetFriends( ({"dwarven soldier"}) );
  SetCurrency("nuggets", random(300) + 50);
  SetInventory(  ([
		VALLEY_OBJ + "/chainmail" : "wear chainmail",
		VALLEY_OBJ + "/battleaxe" : "wield axe",
		VALLEY_OBJ + "/kilt" : "wear kilt",
		VALLEY_OBJ + "/boots" : "wear boots",
		])  );
}
