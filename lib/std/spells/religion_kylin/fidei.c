
/*  Wall of Force defense spell
 *  Does cool stuff to an attacker ;)
 */
#include <lib.h>
#include <daemons.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("fidei defensor");
  SetRules("");
  SetReligions( "Kylin" );
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
     "faith"       : 20,
     "evokation" : 20,
     ]) );
  SetDifficulty(10);
  SetMorality(0);
  SetHelp(
    "This shield spell causes the caster to be surrounded by a field "
    "known as the fidei defensor (literally 'defender of the faith' in "
    "the Old Elven tongue)." 
  );
  SetMessages( ({ 
  	({ "are", "With a calm focus, $agent_name $agent_verb protected by the %^BLUE%^Fidei Defensor%^RESET%^." }),
    ({ "are", "$agent_name $agent_verb%^BLUE%^ protected%^RESET%^ from $target_name by the Fidei Defensor." }),
    ({ "", "The Fidei Defensor around $agent_name slowly %^RED%^disperses%^RESET%^." }),
    }) );
}
