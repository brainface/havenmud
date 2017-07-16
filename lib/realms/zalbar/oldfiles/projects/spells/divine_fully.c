/*  Detect Magic
 *  Returns any SetProperty("magic", val) item.
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("detect magic fully");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "enchantment" : 40,
  ]) );
  SetMagicCost(20, 20);
  SetDifficulty(15);
  SetHelp(
        "This spell allows the caster to detect if an object is magical and "
        "then finds out more information about its magical properties. This "
        "spell will also give the user historical information about the "
        "item."
       );
  }

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  send_messages("stare",
      "$agent_name $agent_verb blankly at $target_name.",
       who, thing, environment(who) );
  if ((thing->GetProperty("magic")) || (thing->GetProperty("history"))){
    message("system",
      thing->GetProperty("magic") + " " + thing->GetProperty("history"),
        who);
     }
  else {
    message("system",
       capitalize(thing->GetShort()) + " is not magical and does not have "
       "any significant history.",    who);
      }

   return 1;
  }


/* Approved by Duuktsaryth on Sun Oct 12 21:54:09 1997. */
