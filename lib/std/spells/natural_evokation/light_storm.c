// thunderstorm               
// lowbie drood area effect spell
// mahkefel 2010                 
//   if this spell causes random runtimes, remove the last function block.                              

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();   
  SetSpell("lightning storm");
  SetRules("");

  SetEnhanceSkills( ({ "shock magic" }) );
  SetSkills( ([
    "natural magic" : 50,
    "evokation" : 50,
  ]) );
  SetDamageType(SHOCK);
  SetStaminaCost(20, 10);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetMessages( ({
    ({"", "$agent_possessive_noun %^BLUE%^drenching rain%^RESET%^ "
      "soaks $target_name." }),
    ({"", "$agent_possessive_noun %^YELLOW%^lightning%^RESET%^ "
      "crashes near $target_name, shocking "
      "$target_objective." }),
    ({"", "$agent_possessive_noun %^YELLOW%^lightning bolt%^RESET%^ "
      "crashes into $target_name, severely electrocuting "
      "$target_objective. " }),
    }) );
  SetHelp(
    "This spell creates a sudden thunderstorm to rain down lightning "
    "on all creatures in the area except the caster and her faithful animal "
    "companions. "
    "Like many natural spells, this spell may only be used "
    "outside or while under the influence of a natural charge."
  );
}

// broadcast a message to the room
int eventCast(object who, int level, mixed limb, object array targets) {
   send_messages( "",
     "%^BOLD%^BLACK%^Suddenly, dark clouds form above and ominous thunder rolls.%^RESET%^",
     who, who, environment(who));
  return spell::eventCast(who, level, limb, targets);
}

// prevent casting indoors without a natural charge
int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

// override GetTargets to remove summoned animals from the list
// god, i do not know if this will work or randomly throw errors.
varargs object *GetTargets(object who, mixed args...) {
  object array targets = ({ });

  foreach(mixed arg in args) {
    debug(arg);
  }

  // damned spell shouldn't have args anyway
  targets = spell::GetTargets(who);
  if (!sizeof(targets)) return targets;

  // let's go ahead and not rain lightning down on the druid's pets?
  foreach(object target in targets) {
    if (!target) continue;
    if (target->GetOwner() == who->GetKeyName()) {
      targets = targets - ({target});
    }
  }
  return targets; 
}
