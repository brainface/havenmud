// cave in
// legendary druid area effect spell that works only indoors/underground
//  the purpose of this spell is mostly just to allow druids to run in the
//  catacombs and fight pestilence golems.
// mahkefel 2010

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("cave in");
  SetRules("");

  //SetEnhanceSkills( ({ "shock magic" }) );
  SetSkills( ([
    "natural magic" : 150,
    "evokation" : 150,
  ]) );
  SetDamageType(BLUNT);
  SetStaminaCost(20, 10);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetMessages( ({
    ({"", "plan failed" }),
    ({"", "plan failed" }),
    ({"", "plan failed" }),
    }) );
  SetHelp(
    "This spell causes siesmic instability in the area, causing an avalanche "
    "of stalactites or collapsing a buiding's support structures."
    "Unlike most natural spells, this spell may not be used outdoors."
  );
}

// broadcast a message to the room
int eventCast(object who, int level, mixed limb, object array targets) {
   send_messages( "",
     "%^BOLD%^BLACK%^A deep rumbling resounds through the area and the "
     "ground starts to shake.%^RESET%^",
     who, who, environment(who));

  if (environment(who)->GetClimate() == "indoors") {
    SetMessages( ({
      ({"", "Dust falls from the ceiling, minorly inconveniencing everyone!" }),
      ({"", "Loose bits of mortar and timber break loose from above, showering $target_name!" }),
      ({"", "A support beam falls from the ceiling, landing squarely on $target_name!" }),
    }) );
  } else if (environment(who)->GetClimate() == "underground") {
    SetMessages( ({
      ({"", "The ground shudders ominously, then quiets." }),
      ({"", "A solitary rock drops from above, hitting $target_name with a thump!" }),
      ({"", "The earth rumbles and stalactites fall from the ceiling, spearing $target_name!" }),
    }) );
  }

  return spell::eventCast(who, level, limb, targets);
}

// prevent casting indoors without a natural charge
int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() != "indoors") && (environment(who)->GetClimate() != "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      who->eventPrint("You must be underground or inside a building to cause a cave in!");
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
      //debug("removed a target from thunderstorm: " + target->GetKeyName());
    }
  }
  return targets;
}

