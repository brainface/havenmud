/* ----------------------------------------------------------------------- */
// Area Title: None
// Filename: enerymine.c
// Author: Brian Roney
// Immortal: vanyel@haven
// Creation Date: May 28rd, 1999
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <dirs.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("create energy mine");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetMagicCost(75, 75);
  SetStaminaCost(10, 5);
  SetRecoveryTime(10);
  SetSkills( ([
     "conjuring" : 125,
     "evokation" : 125,
     ]) );
  SetDifficulty(100);
  SetMorality(-5);
  SetMessages( ({ 
       ({ "create", "$agent_name $agent_verb an energy mine." }),
       }) );
  SetHelp(
          "This spell creates an energy mine that will last for a "
          "certain amount of time and then explode, damaging all "
          "beings in the room.  This spell takes intense "
          "concentration and forces the caster to take a moment "
          "or two to regenerate their energies." );
}


int eventCast(object who, int level, string limb, object array targets) {
        object ward;
        
        if(!(ward = new(DIR_SPELLS "/obj/energy_mine_obj"))) return 0;
        ward->SetCountDown(10);
        ward->eventMove(environment(who));
        send_messages("create", 
          "$agent_name $agent_verb an energy mine.", 
          who, 0, environment(who));
        return 1;
}

