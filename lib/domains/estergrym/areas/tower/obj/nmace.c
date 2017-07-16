#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"mace","heavy steel"}) );
  SetAdjectives( ({ "steel","heavy"}) );
  SetShort("a heavy steel mace");
  SetLong(
    "This steel mace has been well maintained. Numerous large spikes have "
    "been forged to the head of this weapon. Slightly bent these spikes "
    "do not lose their effectiveness. The handle is made of polished steel "
    "as well, with a thick leather braided grip. "
  );
  SetClass(25);
  SetDamagePoints(1500);
  SetValue(300);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("mace");
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(35);
  SetProperty("history",
   "This mace was crafted from a smith from Parva. It's "
   "effectiveness was enhanced with the price tag that "
   "came with it, which the smith spent on booze. "
    );  
}