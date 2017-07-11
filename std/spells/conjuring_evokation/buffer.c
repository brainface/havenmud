/*  Buffer v 2.0 for Haven
 *  Coded by Duuktsaryth
 *  Rebalanced: Jan 26, 1999 - Dylanthalus@Haven
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("buffer");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_DAMAGE);
  SetSkills( ([
    "conjuring" : 1,
    "evokation" : 1,
    ]) );
  SetDifficulty(10);
  SetMessages( ({
    ({ "", "A thin %^YELLOW%^magical shield%^RESET%^ appears around $target_name." }),
    ({ "strike", "The %^YELLOW%^shield %^RESET%^around $agent_name wavers as $target_name $target_verb it." }),
    ({ "", "The %^RED%^shield%^RESET%^ around $agent_name vanishes." }),
    }) );
  SetHelp(
   "This is the first shield spell taught to most new evokers. It is a very "
   "basic shield that protects against a given amount of damage (how much it "
   "'absorbs') before it shatters and is defends no more."
   );
 }
