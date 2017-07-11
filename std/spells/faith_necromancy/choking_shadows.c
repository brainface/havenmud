/*  TelgoCoded 1998.10.26  **  Updated 1998.10.28     */
/*  Religion: Khaoric  **  Name:  Choking Shadows     */
/*  Low Level Evokation Attack Spell, No Special FX   */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("choking shadows");
  SetRules("", "LIV");
  SetSpellType(SPELL_COMBAT);
  SetSkills( ([
     "faith"      : 10,
     "necromancy" : 10,
  ]) );
  SetDifficulty(15);
  SetMorality(0);
  SetAutoDamage(1);
  SetDamageType(POISON);
  SetEnhanceSkills( ({ "poison magic" }) );
  SetMessages( ({
    ({ ({"attempt", "are"}), "$agent_name $agent_verb to make the shadows do $agent_objective bidding, but $agent_nominative $agent_verb not strong enough to control them." }),
    ({ ({"concentrate", "cause"}), "$agent_name $agent_verb deeply and $agent_verb $target_name to choke and gag." }),
    ({ "throttle", "$agent_name $agent_verb $target_name hard with several shadowy tendrils." }),
    ({ "create", "$agent_name $agent_verb several shadowy tendrils that raise from the ground choaking $target_name, causing incredible pain." }),
  }) );
  SetHelp(
          "This spell allows those of the necromantic arts to shape the "
          "shadows around themself into a physical form to attack their "
          "enemy.");
}


/* Approved by Dylanthalus on Thu Nov  5 00:51:33 1998. */
