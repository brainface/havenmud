/*  Temporal Explosion
 *  Updated by the Duuk of Death
 *  31/03/2007
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("temporal explosion");
   SetRules("");
   SetSkills( ([ 
      "conjuring" : 200,
      "evokation" : 200,
      ]) );
   SetAreaSpell(1);
   SetUniqueSpell(1);
   SetSpellType(SPELL_COMBAT);
   SetDifficulty(180);
   SetHelp(
           "This extremely powerful magic spell allows the mage to use temporal "
           "energies to create a powerful explosion causing destruction in the "
           "area surrounding the caster. The spell is rumored to have been created "
           "by a very powerful mage who once lived on the Southern Coast. Though "
           "he is long dead, his knowledge has been hidden away in a scroll.");
}

int eventCast(object who, int level, string limb, object array targets) {
  int damage = GetDamage(level);
    
  if (level <= 33) {
    send_messages( ({"irradiate"}), 
     "$agent_name slightly%^RED%^ $agent_verb%^RESET%^ "+ conjunction(targets->GetName())+ " with %^CYAN%^temporal engeries%^RESET%^.",
     who, targets, environment(who));
    }
  if (level > 33 && level <= 67) {
    send_messages( ({ "create" }),
      "$agent_name $agent_verb a massive rift of %^BLUE%^temporal energies%^RESET%^, devastating " + conjunction(targets->GetName()) + 
      " with a dreadful explosion.",
      who, targets, environment(who));
    }
  if(level > 67) {
    send_messages( ({ "unleash" }) , 
      "$agent_name $agent_verb a cataclysmic explosion of %^BOLD%^%^CYAN%^temporal energies%^RESET%^ %^RED%^annihilating%^RESET%^ " + 
      conjunction(targets->GetName())+ ".",
      who, targets, environment(who));
    }
  targets->eventReceiveDamage(who, HEAT, damage, 0, limb);
  return 1;   
}
