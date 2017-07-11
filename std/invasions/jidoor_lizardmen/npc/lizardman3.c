/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lizardman3.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: December 30th, 1998
// Abstract: Lizardmen Warrior of the raid on Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../lmij.h"

inherit LIB_INVADER;
static void create() {
  invader::create();
  SetReligion("Kuthar");
  SetEnemyTown("Jidoor");  
  SetKeyName("young lizardman soldier");
  SetId( ({ "lizardman", "soldier","invader" }) );
  SetShort("a young lizardman soldier");
  SetAdjectives( ({ "young", "lizardman" }) );
  SetLong(
    "One of the youngest of the lizardman, he is likely here "
    "to partipate in the raid and learn to become better a "
    "warrior.  He looks tough enough to defend himself."
  );
  SetFriends("lizardman");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(5)+5);
  SetRace("lizardman");
  SetCurrency("rupies", random(500)+100);
  SetSkill("pole attack", 20, 1);
  SetAction(5, ({ 
      "!yell kill them all!",
      "!growl",
      "!say Glory to the ancients!",
      "!say Glory to the ancients!",
      "!yell Burn Jidoor, burn!",
      "!yell Burn the city to the ground!",
           }) );
  SetCombatAction(25, ({ 
      "!say foolish one, you think you can defeat me?",
      "!yell Death to you all!",
      "!yell Do not resist us!",
      "!yell Your spirits shall be free!",
      "!yell Glory in death!",
      "!yell Glory in death!",
           }) );
  SetInventory( ([ 
     LMIJ_OBJ "/loincloth" : "wear loincloth",
     LMIJ_OBJ "/chainmail" : "wear chainmail",
     LMIJ_OBJ "/pike" : "wield pike" ]) );
  SetWanderSpeed(10);
  SetWanderPath( ({ "attack third guard", "go north", "go north", 
                    "go north", "go north", "go west", "go west", 
                    "attack first child"}) );
}
