//
// The 'lunar blast' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("lunar blast");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
      "natural magic" : 200,
      "evokation"     : 200,
   ]) );
   SetDamageType(COLD);
   SetEnhanceSkills( ({ "ice magic" }) );
   SetAutoDamage(0);
   SetDifficulty(25);
   SetHelp(
           "Natural magic users are able to focus the moon on their "
           "targets, causing their limbs to freeze. If no target is specified in combat, your "
           "current enemy will be targetted.");
   SetMessages( ({
      ({ ({ "aim", "miss" }), "$agent_name $agent_verb the "
                              "energies of the moon at $target_name "
                              "but $agent_nominative $agent_verb "
                              "completely." }),
      ({ ({ "aim" }), "$agent_name $agent_verb the energies "
                      "of the moon at $target_name, freezing "
                      "$target_objective a bit." }),
      ({ ({ "direct" }), "$agent_name $agent_verb the moon on "
                         "$target_name, severely %^BLUE%^freezing%^RESET%^ "
                         "$target_possessive skin!" }),
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
