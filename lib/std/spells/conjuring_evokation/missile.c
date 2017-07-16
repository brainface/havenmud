/*  Missile Spell
 * Recoded to Balance 3 Sept 1997
 * Duuktsaryth @ Haven
 */
/*    /spells/missile.c
 *    From Nightmare LPMud
 *    Created by Descartes of Borg 961028
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("missile");
   SetRules("", "LIV");
   SetSpellType(SPELL_COMBAT);
   SetSkills( ([
     "conjuring" : 1,
     "evokation" : 1,
   ]) );
   SetEnhanceSkills( ({ "shock magic" }) );
   SetDifficulty(10);
   SetMorality(0);
   SetAutoDamage(0);
   SetDamageType(SHOCK);
   SetEnhanceSkills( ({ "shock magic" }) );
   SetMessages(({
     ({ "are", "$target_name $target_verb unharmed by $agent_possessive_noun magic missile." }),
     ({ "", "$agent_possessive_noun magic missile%^YELLOW%^ stings%^RESET%^ $target_name." }),
     ({ "", "$agent_possessive_noun missile%^BOLD%^YELLOW%^ slams%^RESET%^ $target_name." })
   }) );
  SetHelp(
    "This spell conjures a magic missile of energy and sends it flying at an unsuspecting enemy.\n"
    "If cast without specifying a target while in combat, the missile is targetted at your current enemy."
  );
}


/* Approved by Duuktsaryth on Wed Sep  3 13:57:31 1997. */

