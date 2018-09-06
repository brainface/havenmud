// fire whirl
// midbie drood area effect spell
// mahkefel 2011
//   if this spell causes random runtimes, remove the last function block.
// hidden effect, knocks enemies down randomly
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("fire whirl");
  SetRules("");

  SetEnhanceSkills( ({ "fire magic" }) );
  SetSkills( ([
    "natural magic" : 125,
    "evokation" : 125,
  ]) );
  SetDamageType(HEAT);
  SetStaminaCost(50, 25);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetMessages( ({
    ({"", "$agent_possessive_noun %^RED%^fire whirl%^RESET%^ "
      "hops over $target_name." }),
    ({"", "$agent_possessive_noun %^RED%^%^YELLOW%^fire whirl%^RESET%^ "
      "spins into $target_name, scorching "
      "$target_objective." }),
    ({"", "$agent_possessive_noun %^BOLD%^RED%^fire whirl%^RESET%^ "
      "cyclones into $target_name, incinerating "
      "$target_objective. " }),
    }) );
  SetHelp(
    "This spell creates a horrible flaming tornado to incinerate "
    "the enemies of nature, scorching all creatures in the area "
    "except the caster and her faithful animal "
    "companions. "
    "Like many natural spells, this spell may only be used "
    "outside or while under the influence of a natural charge."
  );
}

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
   send_messages( "",
     "%^BOLD%^RED%^Suddenly, a roiling cyclone of flame descends from the heavens.%^RESET%^",
     who, who, environment(who));
   return spell::eventCast(who, level, limb, targets);
}

int eventAfterEffect(object who, int level, string limb, object target) {
  if (!target) return 0;
  if (who->GetFriends() == target->GetKeyName()) return 0;
  if (random(target->GetStatLevel("coordination")+target->GetStatLevel("luck")) <
    random(who->GetSkillLevel("evokation")/2+who->GetSkillLevel("fire magic")/2)) {
    target->eventCollapse();
  } 
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


