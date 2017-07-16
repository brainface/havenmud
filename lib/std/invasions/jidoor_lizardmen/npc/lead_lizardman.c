/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lead_lizardman.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: December 20th, 1998
// Abstract: Leader of the Lizardmen Raid on Jidoor
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../lmij.h"

inherit LIB_INVADER;
static void create() {
  invader::create();
  SetReligion("Kuthar");
  SetEnemyTown("Jidoor");  
  SetKeyName("lizardman leader");
  SetId( ({ "lizardman", "leader","invader" }) );
  SetShort("a cunning lizardman leader");
  SetAdjectives( ({ "cunning", "lizardman","lead" }) );
  SetLong(
    "Young and obviously strong, the leader of the raiding "
    "party looks mean and dangerous.  It is obvious that "
    "he cares nothing about the lives of the citizens of "
    "Jidoor and the only thing on his mind is disrupting "
    "peacefulness of the city.  He looks like a religious "
    "warrior of some sort and looks very tough."
  );
  SetFriends("lizardman");
  SetGender("male");
  SetClass("fighter");
  SetClass("cleric");
  SetLevel(random(15)+15);
  SetRace("lizardman");
  SetCurrency("rupies", random(500)+1000);
  SetSkill("evokation", 55, 1);
  SetSkill("necromancy", 55, 1);
  SetSkill("pole attack", 55, 1);
  SetAction(5, ({ 
      "!cast ancestral protection",
      "!cast ancestral protection",
      "!cast ancestral protection",
      "!cast ancestral protection",
      "!cast ancestral protection",
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
  SetSpellBook( ([
     "ancestral protection" : 100,
     "spiritual force" : 100,
     "will of old" : 100,
     "ancient power" : 100,
     "spiritual aid" : 100,
    ]) );
  SetCombatAction(25, ({ 
      "!cast ancestral protection",
      "!cast ancestral protection",
      "!cast will of old",
      "!cast will of old",
      "!cast spiritual force",
      "!cast spiritual force",
      "!cast ancient power",
      "!cast ancient power",
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
                    "attack teller"}) );
}
