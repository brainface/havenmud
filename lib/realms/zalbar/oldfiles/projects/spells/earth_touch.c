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
     "enchantment" : 20,
     "conjuring" : 20,
    ]) );
  SetRules("OBJ");
  SetRequiredMagic(30);
  SetMagicCost(15, 15);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(15);
  SetHelp(
          "Typically cast on an armour, this spell makes the object "
          "considerably heavier and more dense. It also makes the object "
          "offer more protection by a small amount.");
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
  thing->SetProtectionBonus(BLUNT, 
            thing->GetProtectionBonus(BLUNT) + amount);
  thing->SetProtectionBonus(SLASH, 
            thing->GetProtectionBonus(SLASH) + amount);
  thing->SetProtectionBonus(PIERCE, 
            thing->GetProtectionBonus(PIERCE) + amount);
  thing->SetProperty("blessed", 5);
  if(strsrch(thing->GetShort(), "(earthen)") == -1) {
       thing->SetShort(thing->GetShort() + " (earthen)");
        }
  thing->AddMass(level);
  return 1;
  }
