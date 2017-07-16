// again, parts stolen from zaxan@haven <lunar blast>
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("undead moon");
  SetSpellType(SPELL_COMBAT);
  SetRules("", "LIV");
  SetSkills( ([
    "necromancy" : 40,
    "faith" : 40,
  ]) );
  SetDamageType(MAGIC|COLD);
  SetReligions( ({ "Aberach" }) );
  SetMaximumMorality(-200);
  SetAutoDamage(0);
  SetDifficulty(25);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetHelp(
    "This Aberach spell takes the evil aura "
    "of the moon and harnesses it into energy, "
    "striking your opponent.");
   SetMessages( ({
     ({ ({ "force", "dodge" }), "$agent_name $agent_verb the "
       "%^BOLD%^BLACK%^evil energy of the moon%^RESET%^ at "
       "$target_name but $target_nominative $target_verb "
       "it completely." }),
     ({ ({ "force" }), "$agent_name $agent_verb the "
       "%^BOLD%^BLACK%^energies of the moon%^RESET%^ at "
       "$target_name, chilling $target_objective a bit." }),
     ({ ({ "direct" }), "$agent_name $agent_verb %^BOLD%^BLACK%^"
       "the moon%^RESET%^ on $target_name, severely freezing "
       "$target_possessive skin!" }),
   }) );
}
int CanCast(object who, int level, mixed limb, object *targets) {
   if( (environment(who)->GetClimate() == "indoors") ||
       (!query_night()) ){
      message("system","Your spell fizzles and refuses to work "
              "in these types of environmental settings.",who);
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

