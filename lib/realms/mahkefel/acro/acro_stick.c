
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName( "walking stick" );
  SetId( ({ "stick" }) );
  SetAdjectives( ({ "ancient" }) );
  SetShort( "an ancient walking stick" );
  SetLong(
    "A long willow walking stick, veined by cracks of age and violence. "
    "Dents and stains of assorted hues mottle the surface."
    );
  SetClass(35);
  SetDamagePoints(3000);
  SetValue(2500);
  SetWeaponType("pole");
  SetDamageType(BLUNT|MAGIC);
  SetMass(300);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetRepairDifficulty(50);
  
  SetProperty("history",
    "A branch of the lost tree of Thra, well worn by Helial the Wanderer, the "
    "longest lived gelfling and survivor of that lost city. Since you're "
    "holding it, it seems his luck ran out."
     );
  SetProperty("magic",
    "Not a truly enchanted weapon, nevertheless its close proximity to a "
    "legendary name seems to have imbued it with some small power. It can "
    "damage creatures resistant to mundane damage and restore some stamina "
    "to whoever wields and walks with it."   
    );
  set_heart_beat(30);
}

void heart_beat() {                
  object wielder = environment();
    
  if (GetWorn() && wielder && wielder->GetStaminaPoints() != wielder->GetMaxStaminaPoints()) {
    wielder->AddStaminaPoints(random(50)+50);
    wielder->eventDisplayStatus();                                                       
    wielder->eventPrint("%^YELLOW%^The comforting weight of the walking stick in your hand seems to invigorate you.%^RESET%^");
  }
}






