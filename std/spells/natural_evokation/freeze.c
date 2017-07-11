//
// The 'freeze' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("freeze");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([ 
     "natural magic" : 45,
     "evokation"     : 45,
      ]) );
   SetMorality(0);
   SetDifficulty(20);
   SetAutoDamage(0);
   SetDamageType(COLD);
   SetEnhanceSkills( ({ "ice magic" }) );
   SetHelp(
           "This attack spell forms a cone of frost which focuses on the "
           "target. Like many natural spells, this spell may only be used "
           "outside or while under the influence of a natural charge."
           );
   SetMessages( ({
    ({ "aim", "$agent_name $agent_verb a cone of cold at $target_name but it has little effect." }),
    ({ "chill", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with a cone of cold." }),
    ({ "freeze", "$agent_name $agent_verb $target_name with a huge %^BOLD%^BLUE%^cone of cold%^RESET%^." }),
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
