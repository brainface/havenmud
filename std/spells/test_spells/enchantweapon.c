#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_SPELL;

int eventEnchantWeapon(string weapon);
int PickEnchant(string weapon);
object target, caster;

static void create() {
  spell::create();
  SetSpell("enchant weapon");
  SetRules("OBJ");
  SetMagicCost(120, 100);
  SetSpellType(SPELL_OTHER);
  SetDifficulty(125);
  SetSkills( ([
      "conjuring" : 350,
      "enchantment" : 350,
    ]) );
  SetHelp(
          "Allows a power mage to enchant a weapon with the power of the elements. "
          "The enchantment only affects non-magical weapons.");
  }

int CanCast(object who, int level, mixed limb, object *targets){
    object thing;
    thing = targets[0];    

    if(!sizeof(targets)){
        message("", "Cast enchant weapon on what?", who);
        return 0;
    }

    if (thing->GetProperty("weapon_imbue") || thing->GetProperty("magic")){
        message("", "That weapon has enchanted with the power of the elements.", who);
        return 0;
    }

    if (!(thing->GetVendorType() & VT_WEAPON)){
        message("", "You cannot enchant something that is not a weapon!", who);
        return 0;
    }
  
    return spell::CanCast(who, level, limb, targets);
}

varargs int eventCast(object who, int level, mixed blah, object *targets) {
   target = targets[0];
   caster = who;

    message("my_action",
         "Please pick the elemental type you wish to enchant with: fire, ice, shock, earth. "
         "or input 'exit' to cancel.",
         who);
       input_to( (: PickEnchant :) );
    return 1;
   }

int PickEnchant(string weapon) {
  
  if(weapon=="exit") {return 0;}
  if(!(weapon == "fire" || weapon == "ice" ||
   weapon == "earth" || weapon == "shock")) {
    message("my_action",
      "That is not a valid enchantment type. Please pick again or input 'exit' to "
      "cancel.", caster);
    input_to( (: PickEnchant :) );
     return 1;
     }
  return eventEnchantWeapon(weapon);
   }

varargs int eventEnchantWeapon(string weapon) {
  int dmg;
  
  dmg = target->GetDamageType();
  if(weapon=="fire") { target->SetDamageType(HEAT|dmg); } 
  if(weapon=="ice") { target->SetDamageType(COLD|dmg); } 
  if(weapon=="shock") { target->SetDamageType(SHOCK|dmg); } 
  if(weapon=="earth") { target->SetDamageType(PIERCE|SLASH|BLUNT|ACID|dmg); } 

  send_messages( ({ "create", "pull", "wrap" }),
        "$agent_name $agent_verb a small tear in the %^CYAN%^aether%^RESET%^ "
        "and $agent_verb forth magical energies wrapping them around $target_name "
        "enchanting it with the power of the elements.",
        caster, target, environment(caster));
   target->SetProperty("weapon_imbue", 1);
   target->SetDestroyOnSell(1);     
   target->SetProperty("magic", "This item has been enchanted with "
                               "magical energies.");    
   return 1;
 }

