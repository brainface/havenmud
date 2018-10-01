/*  Detect Magic
 *  Returns any SetProperty("magic", val) item.
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("detect magic");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "enchantment" : 1,
  ]) );
  SetRequiredMagic(20);
  SetMagicCost(10, 5);
  SetDifficulty(11);
  SetHelp(
         "Checks an item to see if it is magical."
       );
  }

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  send_messages("stare",
      "$agent_name $agent_verb blankly at $target_name.",
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
