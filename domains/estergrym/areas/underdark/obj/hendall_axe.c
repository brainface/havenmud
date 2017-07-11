#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("the Godly Axe");
  SetLong("The Godly Axe is a large one handed battle axe. "
          "It's head is made of finely wrought, bluish metal "
          "with a razor sharp edge. The handle is made of "
          "very hard wood, and is intricately carved. The "
          "axe nearly glows with power.");
  SetId( ({"the godly axe", "godly axe", "axe"}) );
  SetClass(15);
  SetDamagePoints(3500);
  SetMaterial( ({ "metal", "wood" }) );
  SetRepairSkills( ([
          "weapon smithing" : 20,
          "wood working" : 8 ]) );
  SetRepairDifficulty(60);
  SetValue(900);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("godly axe");
  SetMass(150);
  SetVendorType(VT_WEAPON); 
  SetWield("You feel the power of the axe flow through you "
          "as you grip the handle.");
  }
int eventStrike(object target) { 
  if(this_player()->GetKeyName() == "hendall") {
  if(!random(5)) {
  message("combat", "%^RED%^Hendall attempts to strike "
          "a killing blow to "+target->GetCapName()+
          " with the Godly Axe, but fumbles terribly%^RESET%^.",
          environment(this_player()), this_player()); 
  return item::eventStrike(target) -15;
  }
}
  else if(!random(4)) {
  message("combat", "%^YELLOW%^The Godly Axe glows white and "
          "slices through "+target->GetCapName()+" with "
          "ease%^RESET%^.", this_player());
  message("combat", "%^YELLOW%^"+this_player()->GetCapName() +
          "'s axe glows white and slices through "
          +target->GetCapName()+" with ease%^RESET%^.",
          environment(this_player()), this_player());
  return item::eventStrike(target) + 25;
  }
  return item::eventStrike(target);
}


