/*  The wrath spell
 */
#include <damage_types.h>
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("superior wrath");
  SetDifficulty(40);
  SetSpellType(SPELL_COMBAT);
  SetReligions("Kylin");
  SetRules("", "LIV");
  SetSkills( ([
    "faith"       : 120,
    "evokation" : 120,
    ]) );
  SetAutoDamage(0);
  SetDamageType(HEAT);
  SetEnhanceSkills( ({ "fire magic" }) );
  SetHelp(
          "This spell showers a target with even more of Duuktsaryth's divine wrath."
          );
  SetMessages( ({
    ({ "harm",   "$agent_name%^BLUE%^ $agent_verb%^RESET%^ $target_name with divine wrath.", }),
    ({ "cause",  "$agent_name $agent_verb %^RED%^severe damage%^RESET%^ to $target_name with divine wrath." }),
    ({ "unleash","$agent_name $agent_verb%^YELLOW%^ the supreme vengeance of Duuktsaryth %^RESET%^on $target_name.", })
    }) );
}
