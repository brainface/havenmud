/*  Detect Magic
 *  Returns any SetProperty("magic", val) item.
 *
 * Modified to have default values if item is missing
 * either magic or history properties instead of
 * returning '0'
 * -- Melchezidek 2013-03-22
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
        "then finds out more information about its magical properties."
        /*This "
        "spell will also give the user historical information about the "
        "item."*/
       );
  }

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  string msg = "";
  string name = capitalize(thing->GetShort());
  if (!thing) {
    who->eventPrint("You stare blankly around.");
    return 1;
   }
  send_messages("stare",
      "$agent_name $agent_verb blankly at $target_name.",
       who, thing, environment(who) );

  if (thing->GetProperty("magic")) {
        msg+= thing->GetProperty("magic");
   } else {
        msg+= name +" is not magical.";
  }
        msg+="\n";
   // mahkefel, blaming it on alli of course.
   /*if(thing->GetProperty("history")){
        msg+=thing->GetProperty("history");
   } else {
       msg+= name + " has no significant history.";
  }*/

    message("system", msg, who);
   return 1;
}


/* Approved by Duuktsaryth on Sun Oct 12 21:54:09 1997. */

