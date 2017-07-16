/* Support Guards for the help function
   in guard2.c. Will self dest when enemy
   dies and when they're not in combat for
   a certain amount of time (ie: if the enemy
   flees.)
   -Melchezidek Oct 2009
*/

#include <lib.h>
#include "../mal.h"
inherit LIB_NPC;

int fight_count = 0;

static void create() {
  npc::create();
  SetShort("a tough-looking guard");
  SetKeyName("guard");
  SetId( ({"guard"}) );
  SetAdjectives( ({"tough", "tough-looking"}) );
  SetLong("This tough guard looks very menacing. His demeanor "
          "suggests he takes his job very seriously and will not "
          "let anyone get away with breaking the laws of Malveillant.");
  SetRace("dark-elf"); 
  SetMorality(-200);
  SetGender("male");
  SetClass("fighter");
  SetLevel(30 + random(15));
  SetCurrency("roni",random(10) + 20);
  SetFriends("prince marikian");
  SetFriends("guard");
  SetSkill("disarm", 200, 1);
  SetInventory( ([
      MAL_OBJ + "/clothing/g_breastplate" : "wear plate",
      MAL_OBJ + "/clothing/g_boots"       : "wear boots",
      MAL_OBJ + "/clothing/g_medallion"   : "wear medallion",
      MAL_OBJ + "/clothing/g_pants"       : "wear pants",
      MAL_OBJ + "/weapons/g_sword"        : "wield sword",
     ]) );
  SetCombatAction(10, ({
          "!disarm",
          "!disorient",
        }) );
  }

  
void heart_beat() {
	::heart_beat();
	if (GetInCombat() != 1) fight_count++;
	if (fight_count > 10) {
//		debug("Test Time Dest: OKAY" + " fight_count = " + fight_count + "");
    message("system",
     "%^WHITE%^The guard returns to his normal duties.%^RESET%^",
     environment() );
  this_object()->eventDestruct();
  }
}
