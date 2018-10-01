/*  Enchant Armour Spell
 *  Thoin@Haven 11/29/05
 */
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("enchant armour");
  SetRules("OBJ");
  SetMagicCost(150, 300);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(200);
  SetSkills( ([
      "conjuring" : 400,
      "enchantment" : 400,
    ]) );
  SetHelp(
          "Allows a powerful mage to enchant a piece of armour, "
          "non-metal only, "
          "increasing the protection it would offer. However "
          "because of the large amount of magical energies "
          "required in the spell there is a chance that the "
          "spell will fail. The magics used in this spell "
          "put a large strain on the object.");
  }

int CanCast(object who, int level, mixed blah, object *targets){
    object thing;
    thing = targets[0];    

    if(!sizeof(targets)){
        message("", "Cast enchant armour on what?", who);
        return 0;
    }

    if (thing->GetProperty("enchant_armour") || thing->GetProperty("magic")){
        message("", "This has already been enchanted with magical energies."
        , who);
        return 0;
    }
    
    if (member_array("metal", thing->GetMaterials()) == 0) {
        message("system", "You cannot cast this on something that has metal in it.", who);
        return 0;
    }

    if (!(thing->GetVendorType() & VT_ARMOUR) && !(thing->GetVendorType() & VT_CLOTHING)){
        message("", "You cannot enchant something that isn't armour!", who);
        return 0;
    }
  
    return spell::CanCast(who, level, blah, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
  int time, dmg, type;
  object thing = targets[0];
  object *hurt = filter(all_inventory(environment(who)), (: living :) );
  dmg = to_int(level/10 + ((who->GetSkillLevel("enchantment") - 400)/10));

  if (dmg > 20) {dmg = 20;}
  

// FUMBLE

  if (!(random(to_int(100)))) {
     send_messages( "scream",
      "$agent_name $agent_verb as $target_name %^BOLD%^%^RED%^EXPLODES%^RESET%^ "
      "causing the magical energies to spread chaotically through the room "
      "harming all.",
        who, thing, environment(who)
  );
    thing->eventDestruct();
    hurt->AddHealthPoints(-400);
  return 1;
  }
 else{

// SUCCESS

  send_messages( ({ "create", "pull", "wrap" }),
        "$agent_name $agent_verb a small tear in the %^CYAN%^aether%^RESET%^ "
        "and $agent_verb forth magical energies wrapping them around $target_name.",
        who, thing, environment(who)
  );
   thing->SetProperty("enchant_armour", 1);
     switch (level) {
     case 1..50 :
        thing->SetProtectionBonus(PIERCE, 
        thing->GetProtectionBonus(PIERCE) + dmg);
        thing->SetProtectionBonus(SLASH, 
        thing->GetProtectionBonus(SLASH) + dmg);
        thing->SetProtectionBonus(BLUNT, 
        thing->GetProtectionBonus(BLUNT) + dmg);
      break;
     case 51..99 :
        thing->SetProtectionBonus(PIERCE, 
        thing->GetProtectionBonus(PIERCE) + dmg);
        thing->SetProtectionBonus(SLASH, 
        thing->GetProtectionBonus(SLASH) + dmg);
        thing->SetProtectionBonus(BLUNT, 
        thing->GetProtectionBonus(BLUNT) + dmg);
        thing->SetProtectionBonus(WATER, 
        thing->GetProtectionBonus(WATER) + dmg);
        thing->SetProtectionBonus(SHOCK, 
        thing->GetProtectionBonus(SHOCK) + dmg);
        thing->SetProtectionBonus(COLD, 
        thing->GetProtectionBonus(COLD) + dmg);
      break;
     case 100 :
        thing->SetProtectionBonus(PIERCE, 
        thing->GetProtectionBonus(PIERCE) + dmg);
        thing->SetProtectionBonus(SLASH, 
        thing->GetProtectionBonus(SLASH) + dmg);
        thing->SetProtectionBonus(BLUNT, 
        thing->GetProtectionBonus(BLUNT) + dmg);
        thing->SetProtectionBonus(WATER, 
        thing->GetProtectionBonus(WATER) + dmg);
        thing->SetProtectionBonus(SHOCK, 
        thing->GetProtectionBonus(SHOCK) + dmg);
        thing->SetProtectionBonus(COLD, 
        thing->GetProtectionBonus(COLD) + dmg);
        thing->SetProtectionBonus(HEAT, 
        thing->GetProtectionBonus(HEAT) + dmg);
        thing->SetProtectionBonus(MAGIC, 
        thing->GetProtectionBonus(MAGIC) + dmg);
        thing->SetProtectionBonus(ACID, 
        thing->GetProtectionBonus(ACID) + dmg);
      break;
    }
   thing->SetDestroyOnSell(1);
   thing->eventDeteriorate();
   thing->SetProperty("magic", "This item has been enchanted with "
                               "magical energies.");    
   return 1;
  }
}

