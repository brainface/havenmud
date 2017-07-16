/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lizardman2.c
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
  SetKeyName("lizardman soldier");
  SetId( ({ "lizardman", "soldier","invader" }) );
  SetShort("a lizardman soldier");
  SetAdjectives( ({ "lizardman" }) );
  SetLong(
    "One of the grunts of the lizardman invasion is this "
    "lizardman soldier.  She is somewhat smaller then her "
    "counterparts but she is obviously to be feared.  She "
    "has a look of utter destruction in her eyes."
  );
  SetFriends("lizardman");
  SetGender("female");
  SetClass("fighter");
  SetLevel(random(5)+10);
  SetRace("lizardman");
  SetCurrency("rupies", random(500)+250);
  SetSkill("pole attack", 30, 1);
  SetAction(5, ({ 
      "!yell kill them all!",
      "!growl",
      "!say you think you can defeat me you worthless scum!",
      "!say time to die!",
      "!say Poor sprites, they are so defenseless.",
      "!say Glory to the ancients!",
      "!say Glory to the ancients!",
      "!say the worthless jidoormages can't help you!",
      "!yell Burn Jidoor, burn!",
      "!yell Burn Jidoor, burn!"
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
  SetWanderPath( ({ "attack second guard", "go north", "go north", 
                    "go north", "go north", "go west", "go west", 
                    "attack first child"}) );
}
