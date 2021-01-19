/* Animate dead */
// Summary: animate dead spell for necros
// Date: ???
// Created by: Judging for the balance, Duuk ;)
// Minor fixes by: Rhakz@Haven
// Fixed to have zombie follow and assist caster
// Laoise, August 2004
// Fixed to not allow cast/train on non-corpse objects
// Mahkefel, January 2011
// Added default animate behavior to spells.c to allow easy creation of more
// undead spells - mahk 2021

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("animate dead");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");  
  SetSkills( ([
    "necromancy" : 1,
  ]) );
  SetAnimate(DIR_SPELLS "/obj/animate_zombie");	    
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetMessages( ({
    ({ ({ "summon", "force" }), "$agent_name $agent_verb%^RED%^BOLD%^ "
      "power%^RESET%^ from $agent_reflexive and $agent_verb "
      "$target_name back into the world of the living."}),
  }) );
     
  SetHelp("This spell summons the power of the caster into "
          "one mystical force to reinstall motion to an "
          "undead form. This is not a resurrection spell, "
          "but actually restores a mindless life to a corpse "
          "that then becomes the caster's tool. \n"
          "%^BLACK%^%^B_RED%^DO NOT animate a second corpse "
	  "if one is already active!%^RESET%^");
}

// if corpse is boney, make the animate a skeleton instead!
varargs int eventCast(object who, int level, mixed x, object *targets) {
  // okaaay so setting SetAnimate doesn't set it for the cast,
  // it sets it for the spell object so long as its loaded
  // so it MUST be reset to default or the first time something's a
  // skeleton everything's a skeleton.
  foreach(object corpse in targets) {
    if (corpse->GetCorpseState() == "skeleton") {
      SetAnimate(DIR_SPELLS "/obj/animate_skeleton"); 
    } else {
      SetAnimate(DIR_SPELLS "/obj/animate_zombie"); 
    }
  }
  return ::eventCast(who,level,x, targets);
}
