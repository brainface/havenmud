/*  Detect Magic
 *  Returns any SetProperty("magic", val) item.
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("find magic");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "enchantment" : 1,
    "natural magic" : 1,
  ]) );
  SetMagicCost(10, 10);
  SetDifficulty(15);
  SetHelp(
         "Checks an item to see if it is magical."
       );
  }

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  send_messages("wave",
      "$agent_name $agent_verb $agent_possessive hand at $target_name.",
       who, thing, environment(who) );
  if (thing->GetProperty("magic")) {
    message("system",
       capitalize(thing->GetShort()) + " is magical.",
        who);
     }
  else {
    message("system",
       capitalize(thing->GetShort()) + " is not magical.",
         who);
      }
   return 1;
  }


/* Approved by Duuktsaryth on Sun Oct 12 21:54:09 1997. */
