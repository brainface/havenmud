/*  The ultimate Kylin attack spell */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("hand of judgement");
  SetReligions("Kylin");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
   "faith"       : 200,
   "evokation" : 200,
   ]) );
  SetDifficulty(100);
  SetHelp(
         "Hand of Judgement is the ultimate Kylin attack spell. "
         "Calling down all of the divine wrath that only the powerful "
         "of the faithful can summon, the caster makes an attempt "
         "to utterly annihilate the target.");
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetAutoDamage(0);
  SetMessages( ({
    ({ "warm", "$agent_name%^BLUE%^BOLD%^ $agent_verb%^RESET%^ $target_name with a massive flame of divine power." }),
    ({ ({ "summon", "blast" }), "$agent_name $agent_verb a massive pillar of divine flame and%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ $target_name with it!" }),
    ({ "annihilate", "$agent_name utterly%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ $target_name with the cleansing fires of Duuktsaryth's Judgement!" })
    }) );
 }
