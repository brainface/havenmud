/*  Vine Wall v 1.0 for Haven
    balanced by Dylanthalus@haven Dec 11 1998
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("vine wall");
  SetRules("", "LIV");
  SetSpellType(SPELL_DEFENSE);
  SetSkills( ([
    "evokation"     : 80,
    "natural magic" : 80, 
  ]) );
  SetDifficulty(5);
  SetProtectionTypes(ALL_EXTERNAL);
  SetShieldType(SHIELD_TIMED); 
  SetMessages( ({
    ({ "", "A thick %^GREEN%^wall of vines%^RESET%^ appears around "
           "$target_name." }),
    ({ "strike", "The %^GREEN%^wall of vines%^RESET%^ "
           "around $agent_name wavers "
           "as $target_name $target_verb it." }),
    ({ "", "The %^RED%^wall of vines%^RESET%^ around $agent_name "
           "crumbles into dust." }),
    }) );
  
  SetHelp(
    "This natural magic spell causes a thick wall of "
    "vines to envelope the target and protect them from "
    "some physical damage for a short period of time."
    );    
 }
