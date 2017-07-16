//Illura@Haven
//Sept 2009
//whip
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create()
{
item::create();
  SetKeyName("whip");
  SetId( ({ "whip" }) );
  SetAdjectives(  ({ "thin", "leather" })  );
  SetShort("a thin leather whip");
  SetLong(
    "This thin whip is made of braided leather and shows "
    "quite a bit of wear and tear from abrading the backs "
    "of many an elvish slave.");
  SetMass(80);
  SetValue(150);
  SetDamagePoints(1100);
  SetWeaponType("blunt");
  SetDamageType(SLASH);
  SetClass(12);
  SetVendorType(VT_WEAPON);
  SetMaterial(  ({ "leather" })  );
  SetRepairSkills(  ([ "weapon smithing" : 1 ])  );
  SetRepairDifficulty(8);
}
