// Modified Backpack

#include <lib.h>
inherit LIB_WORN_STORAGE;
#include <armour_types.h>
#include <vendor_types.h>
static void create() 
  {
  ::create();
  SetKeyName("haversack");
  SetId( ({ "sack","haversack" }) );
  SetShort("a haversack");
  SetLong(
	  "This haversack is made of thick cloth, which is carried by a strap either "
	  "slung over a shouler or worn across the back. This sack is made to carry "
	  "a small amount of equipment. Fashioned from some type of durable and heavy "
	  "cloth, it appears to be of high quality.");
  SetMass(150);
  SetValue(300);
  SetArmourType(A_CLOAK);
  SetRestrictLimbs( ({"left arm" || "right arm" || "torso"}) );
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(1500);
  SetMaterial( ({ "textile" }) );
  SetRepairSkills( ([ "textile" : 1,]) );
  SetRepairDifficulty(30);
  SetCanClose(1);
  SetClosed(1);
  SetMaxCarry(500);
}
