/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lizardman1.c
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
  SetKeyName("lizardman warrior");
  SetId( ({ "lizardman", "warrior","invader" }) );
  SetShort("a lizardman warrior");
  SetAdjectives( ({ "lizardman" }) );
  SetLong(
    "Obviously one of the elite lizardman attacking the "
    "city, this lizardman is strong and agile.  His muscles "
    "are literally buldging through his clothes.  He looks "
    "very dangerous and quite capable of wreaking havoc on "
    "the city of Jidoor."
  );
  SetFriends("lizardman");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(10)+10);
  SetRace("lizardman");
  SetCurrency("rupies", random(500)+500);
  SetSkill("pole attack", 40, 1);
  SetAction(5, ({ 
      "!yell kill them all!",
      "!growl",
      "!say you think you can defeat me you worthless scum!",
      "!say time to die!",
      "!say Poor sprites, they are so defenseless.",
      "!say Glory to the ancients!",
      "!say Glory to the ancients!",
      "!say the worthless jidoormages can't help you!",
      "!say Now I'm gonna kill you!",
      "!yell Burn Jidoor, burn!",
      "!yell Burn the city to the ground!",
           }) );
  SetCombatAction(25, ({ 
      "!say foolish one, you think you can defeat me?",
      "!yell Death to you all!",
      "!yell Do not resist us!",
      "!yell Your spirits shall be free!",
           }) );
  SetInventory( ([ 
     LMIJ_OBJ "/loincloth" : "wear loincloth",
     LMIJ_OBJ "/chainmail" : "wear chainmail",
     LMIJ_OBJ "/pike" : "wield pike" ]) );
  SetWanderSpeed(10);
  SetWanderPath( ({ "attack first guard", "go north", "go north", 
                    "go north", "go north", "go west", "go west", 
                    "attack navan"}) );
}
