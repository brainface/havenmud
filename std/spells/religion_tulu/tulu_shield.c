/* General faith spell.  Amelia@Haven Dec '98
 * Rebalanced by Dylanthalus April 11, 1999
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("protection of tulu");
   SetRules("","LIV");
   SetSpellType(SPELL_DEFENSE);
   SetProtectionTypes(ALL_EXTERNAL);
   SetShieldType(SHIELD_DAMAGE);
   SetDifficulty(60);
   SetSkills( ([
     "faith"       : 400,
     "evokation"   : 400,
            ]) );
   SetMessages( ({
     ({ "","A %^BLACK%^BOLD%^field of dark mist%^RESET%^ forms around $target_name." }),
     ({ "","$target_possessive_noun attack is absorbed into the %^BLACK%^BOLD%^mist%^RESET%^ surrounding $agent_name." }),
     ({ "","The %^RED%^mist %^RESET%^around $agent_name fades into nothingness." }),
     }) );
  SetHelp(
      "The protection of Tulu defends the cultists of Tulu from harm while the Master dreams."
    );
  SetReligions("Tulu Cult");
}
