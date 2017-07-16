/*  Earth Touch Spell
 *  
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("earth touch");
  SetSkills( ([
     "enchantment" : 4,
     "conjuring" : 4,
    ]) );
  SetRules("OBJ");
  SetRequiredMagic(30);
  SetMagicCost(15, 15);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(15);
  SetHelp(
          "Typically cast on an armour, this spell makes the object "
          "considerably heavier and more dense.");
  }

int CanCast(object who, int level, mixed useless, object *targets) {
  object target = targets[0];
  if(target->GetProperty("magic")) {
    message("system", "That object is already magical.", who);
    return 0;
  }
  return spell::CanCast(who, level, useless, targets);
}

varargs int eventCast(object who, int level, mixed useless, object *targets) {
    object thing = targets[0];
    int amount = level / 5;

  send_messages( ({ "open", "touch" }),
    "$agent_name $agent_verb a rift to the plane of earth to " +
    "$agent_verb $target_name.",
     who, thing, environment(who) );
  thing->SetProtection(BLUNT, 
            thing->GetProtection(BLUNT) + amount);
  thing->SetProtection(SLASH, 
            thing->GetProtection(SLASH) + amount);
  thing->SetProtection(PIERCE, 
            thing->GetProtection(PIERCE) + amount);
  thing->SetProperty("magic", 
            "This object has been hardened by the plane of earth.");
  thing->SetProperty("blessed", 2);
  if(strsrch(thing->GetShort(), "(earthen)") == -1) {
       thing->SetShort(thing->GetShort() + " (earthen)");
        }
  thing->AddMass(level);
  return 1;
  }
