#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("erase great circle");
  SetRules("OBJ");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(100, 150);
  SetDifficulty(195);
  SetSkills( ([
    "faith"   : 350,
    "healing" : 350,
    ]) );
  SetHelp(
    "This spell allows the caster to remove a great circle from the room. To use "
    "this spell simply cast it at the circle. This spell can also target a "
    "black circle if the need arises."
    );
}

varargs object *GetTargets(object who, mixed args...) {
  object *t = ::GetTargets(who, args...);
  t = filter(t, (: $1->GetProperty("gcircle") :) );
  return t;
}

varargs int eventCast(object who, int level, mixed f, object *t) {
  object circle = t[0];
    
  send_messages( ({ "attempt", }),
    "$agent_name $agent_verb to erase $target_name!",
    who, circle, environment(circle) );
  if (level < random(75)) {
    send_messages( ({ "wave", "are" }),
      "$agent_name $agent_verb $agent_possessive hand at "
      "$target_name, $target_nominative flickers slightly but remains!", 
      who, circle, environment(who) );
    return 1;
    }
  send_messages( ({ "wave", "are", "are", }),
    "$agent_name $agent_verb $agent_possessive hand at "
    "$target_name, $target_nominative flickers %^BOLD%^%^YELLOW%^brightly%^RESET%^ "
    "and fades into oblivion.", who, circle, environment(who) );
  environment(circle)->RemoveProperty("great_circle");
  circle->eventDestruct();
  return 1;
}

