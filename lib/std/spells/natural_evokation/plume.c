// The 'plume' spell
//
// The 'plume' spell
// Created by Mahkefel@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("plume");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
     "natural magic" : 10,
     "evokation"     : 10,
      ]) );
   SetMorality(0);
   SetDifficulty(20);
   SetAutoDamage(0);
   SetDamageType(HEAT);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
           "This spell allows a novice druid, lacking full control "
           "of the elements, to unleash a hot plume of smoke at their "
           "opponent. This spell may only be used outdoors or while "
           "under the influence of a natural charge.");
   SetMessages( ({
    ({ "irritate", 
       "$agent_name%^BOLD%^WHITE%^ $agent_verb%^RESET%^ $target_name "
       "with a %^BOLD%^BLACK%^small cloud of smoke%^RESET%^ "
       "from $agent_possessive open palm." }),
    ({ "scald", "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ $target_name "
       "with a %^BOLD%^BLACK%^plume of smoke%^RESET%^ from $agent_possessive "
       "open palm." }),
    ({ "scour", "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with "
        "a %^BOLD%^BLACK%^plume of smoke and ash%^RESET%^ from $agent_possessive "
        "open palm." }),
    }) );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

