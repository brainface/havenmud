//
// The Desert Banishment Spell
// Banishes someone to a random spot in the Yozrath Desert
// Created by Zaxan@Haven
// made to work by vivake gupta (dunedain@haven)
// Altered by Morgoth@Haven to fix several balance issues
//

#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <domains.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("desert walk");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(200);
  SetMagicCost(100,100);
  SetSkills( ([
    "faith"       : 50,
    "evokation" : 50,
  ]) );
  SetReligions("Kylin");
  SetRequiredStamina(100);
  SetStaminaCost(50,50);
  SetDifficulty(70);
  SetMorality(-30);
  SetHelp(
   "Used by the most powerful Desert Kylin clerics, this "
   "spell allows them to channel powerful energy from "
   "Duuktsaryth to move themselves to the City of Yozrath.");
}

int CanCast(object who, int level, string limb, object *targets) {
  object target = targets[0];
  object env = environment(who);
  int distance;
  if( environment(who)->GetProperty("no teleport") ||
      environment(who)->GetProperty("no attack") ) {
	  who->eventPrint("You can not do that here.");
	  return 0;
	}
	if(who->GetTestChar()) debug("Diff: " + GetDifficulty() + " dist: " + distance);
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  string location = YOZRATH_TOWNS "yozrath/room/oasis3";
  
  who->eventMoveLiving(location, 
    "$N disappears in a whirl of sand and dust.",
    "$N appears from a whirl of sand and dust.");
  
  return 1;
}

/* Difficulty for normal teleporting removed due to existance of desert rose. 
 * This spell is essentially a free version.
 */
