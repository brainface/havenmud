/* Clone of animate dead
 *  That makes mummies.
 *
 * Mummies have "low/medium" physical resistance,
 * are fire vulnerable regardless of race,
 * and have a low frequency curse attack
 *
 */

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

void CrumbleCorpse(object corpse);

static void create() {
  ::create();
  SetSpell("mummify");
  SetSpellType(SPELL_OTHER);
  SetUniqueSpell(1);
  SetRules("OBJ");
  SetSkills( ([
    "necromancy" : 50,
  ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetAnimate(DIR_SPELLS "/obj/animate_mummy");
  SetMessages( ({
    ({ ({"wrap","coax"}),
      "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
      "in perfumed bandages and $agent_verb $target_objective "
      "back to a semblance of life."}),
    }) );

  SetHelp(
    "This spell allows the caster to perform a necromantic ritual to "
    "preserve and animate a corpse to serve him. Xandrian necromancers "
    "prefer such servants, as the ritual leaves the corpse resistant to "
    "most weapons, if very vulnerable to fire. \n"
    "%^BLACK%^%^B_RED%^DO NOT animate a second corpse of any type if "
    "one is already active!%^RESET%^");
}

object *GetTargets(object who, mixed args...) {
  object *targets = ::GetTargets(who, args...);
  if (!targets) targets = ({ });
  filter(targets, (: $1->GetCorpseState() :) );
  return targets;
}
