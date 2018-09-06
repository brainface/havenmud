/* Figment Spell
 *
 * Makes a minor image.
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
inherit LIB_SPELL;

static void create() {
spell::create();
  SetSpell("figment");
  SetRules("STR");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(15);
  SetSkills( ([
    "illusion" : 1,
  ]) );
  SetMagicCost(10, 5);
  SetDifficulty(10);
  SetMorality(0);
  // dynamically set
  // SetConjure( DIR_SPELLS "/obj/create_light_ob");
  // SetMessages( ({
  //    ({ "create", "$agent_name $agent_verb a magical globe of light." }),
  // }) );
  SetHelp(
    "The first illusion most learn, this spell forms a small, pseudo-real "
    "representation of what the caster desires. [Options are coins, lantern, "
    "parasol, or energy mine. i.e. \"Cast figment on lantern\"].");
}

varargs object *GetTargets(object who, mixed args...) {
  string target;
 
  if(sizeof(args) != 1) {
     message("system", "Cast figment on what? Choices are coins, lantern, "
       "parasol, or energy mine", who);
     return 0;
  }
       
  target = args[0];   
  
  if (target == "coin" || target == "coins") {
    SetConjure( DIR_SPELLS "/obj/illusion/coin_pile"); 
  } else if (target == "mine") {
    SetConjure( DIR_SPELLS "/obj/illusion/fake_mine");  
  } else if (target == "lantern") {
    SetConjure( DIR_SPELLS "/obj/illusion/lantern");  
  } else if (target == "parasol") {
    SetConjure( DIR_SPELLS "/obj/illusion/parasol");
  } else {
     message("system", "Cast figment on what? Choices are coins, lantern, "
       "parasol, or energy mine", who);
     return 0;
  }
          
  SetMessages( ({
     ({ "pull", "$agent_name $agent_verb a " + target + " from thin air." }),
  }) );  

  // um... this is dumb, but i think making it target the caster works?
  return ({who});
}

