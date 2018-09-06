/*  A spell to enhance armour
 *  For the clerics
 */
// mahk 2018: fixed indefinite stacking bug
// made it refuse to cast at all on illegal targets
#include <magic.h>
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("fortify");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetMagicCost(15, 15);
  SetSkills( ([
     "faith" : 10,
     "enchantment" : 10,
     ]) );
  SetDifficulty(20);
  SetHelp(
     "Fortifies a given piece of armour with the power of the casters faith "
     "increasing the protection it offers."
  );
}

int CanCast(object who, int level, mixed limb, object *targets) {

  foreach(object armour in targets) {
    if(!armour->GetArmourType() || armour->GetArmourType() == A_WEAPON) {
      who->eventPrint("That is not any sort of armour!");
      return 0;
    }
    if(strsrch(armour->GetShort(), "(fortified)") !=-1 ) {
      who->eventPrint("That armour is already fortified.");
      return 0;
    }
  }
  return spell::CanCast(who, level, limb, targets);
}


varargs int eventCast(object who, int level, mixed a, object *tars) {
  object armour = tars[0];

  int amt = (level + who->GetSkillLevel("enchantment")) / 5;

  if (amt > 100) {amt = 100;}

  armour->SetProtectionBonus(BLUNT,
            armour->GetProtectionBonus(BLUNT) + amt);
  armour->SetProtectionBonus(SLASH,
            armour->GetProtectionBonus(SLASH) + amt);
  armour->SetProtectionBonus(PIERCE,
            armour->GetProtectionBonus(PIERCE) + amt);
  if(strsrch(armour->GetShort(), "(fortified)") == -1) {
        armour->SetShort(armour->GetShort() + " (fortified)");
        }
  send_messages( ({ "touch" }),
   "$agent_name $agent_verb $target_name causing it to %^YELLOW%^glow%^RESET%^.",
      who, armour, environment(who));
  return 1;
}

