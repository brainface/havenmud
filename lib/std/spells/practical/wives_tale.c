/*  Wives' Tail
 *  A bad detect magic that returns only the
 *  SetProperty("history", val)
 */
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("wives' tale");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "practical magic" : 1,
  ]) );
  SetMagicCost(10,10);
  SetDifficulty(45);
  SetHelp(
    "This spell allows a hedge-wizard to discover the legends and stories an "
    "item has earned in the world. Be warned that it reveals oft-repeated "
    "rumors and beliefs about the item, and not any precise magical working."
  );
}

int eventCast(object who, int level, mixed useless, object *targets) {
  object thing = targets[0];
  send_messages("stare",
    "$agent_name $agent_verb blankly at $target_name.",
     who, thing, environment(who) );
  if ((( thing->GetProperty("history") ))){
    message("system", thing->GetProperty("history"), who);
  } else {
    message("system",
      capitalize(thing->GetShort()) + " is unknown to gossips and tale-tellers.",
      who);
  }
  return 1;
}

