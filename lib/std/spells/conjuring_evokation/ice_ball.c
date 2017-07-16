/* Attack spell which creates a magical ice ball. 
 * Created by Amelia@Haven.
 * Balanced to spell system 7 Sept 1997
 * Duuktsaryth@Haven
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <std.h>
 
inherit LIB_SPELL;
 
static void create() {
   spell::create();
   SetSpell("ice ball");
   SetRules("", "LIV");
   SetSpellType(SPELL_COMBAT);
   SetRequiredMagic(40);
   SetSkills( ([
      "conjuring" : 10,
      "evokation" : 10,
      ]) );
   SetEnhanceSkills( ({ "ice magic" }) );
   SetDifficulty(15);
   SetMorality(0);
   SetAutoDamage(0);
   SetDamageType(COLD);
   SetMessages( ({
                   ({ "are", "$target_name $target_verb "
                      "unharmed by $agent_possessive_noun "
                      "slushy ice ball." }),
                   ({ "", "$agent_possessive_noun cold ice ball "
                      "bruises $target_name." }),
                   ({ "", "$agent_possessive_noun rock hard ice ball "
                      "chills $target_name." })
              }) );
  SetHelp(
           "Casting this spell creates an ice ball that races "
           "at your target (or opponent). Whatever is left remains on the ground, "
           "melting."
           );
}

varargs int eventCast(object who, int level, mixed limb, object array targets) {
  object ob;
 
  ob = new(STD_SPELLS "obj/ice_ball_obj");
  ob->eventMove(environment(this_player())); 
  return ::eventCast(who,level,limb,targets);
}


/* Approved by Duuktsaryth on Sun Sep  7 21:21:39 1997. */
