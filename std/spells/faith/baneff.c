#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("banish lesser effigy");
  SetRules("LIV");
  SetMagicCost(50, 450);
  SetSkills( ([
    "faith"       : 150,
    ]) );
  SetHelp(
   "This spell can be used in two ways.  The first and most benign way "
   "is to use it on your own lesser effigy that you have summoned, thereby "
   "sending it back to the plane it was summoned from.  The second, and less "
   "friendly, way to use it is by casting it upon someone else's lesser effigy. "
   "This is not seen in a friendly manner by the target effigy."
   );
}

varargs object *GetTargets(object who, mixed args...) {
  object *t = ::GetTargets(who, args...);
  t = filter(t, (: $1->GetProperty("lesser_effigy") :) );
  return t;
}

varargs int eventCast(object who, int level, mixed f, object *effs) {
  object eff = effs[0];
  object summ; int summlevel;
  int success = 0;
    
  send_messages( ({ "attempt", }),
    "$agent_name $agent_verb to banish $target_name!",
    who, eff, environment(eff) );
  summ = find_living(eff->GetSummoner());
  if (!summ) success = 1;
  if (summ == who) success = 1;
  summlevel = summ->GetSpellLevel("summon lesser effigy");
  if (summlevel + 5 < level) success = 1;
  if (!success) {
    send_messages( ({ "chant", "are", "are" }),
      "$agent_name $agent_verb softly, and when $agent_nominative $agent_verb "
      "finished, $target_name $target_verb %^YELLOW%^still here%^RESET%^!", 
      who, eff, environment(who) );
    eff->AddEnemy(who);
    eff->SetAttack(who);
    return 1;
    }
 send_messages( ({ "chant", "are", "are", }),
   "$agent_name $agent_verb softly, and when $agent_nominative $agent_verb "
   "finished, $target_name $target_verb no more!", who, eff, environment(who) );
 eff->eventDestruct();
 return 1;
}
