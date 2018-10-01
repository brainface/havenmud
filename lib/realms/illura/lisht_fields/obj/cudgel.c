//Illura@Haven
//Sept 2009
//cudgel
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create()
{
  item::create();
  SetKeyName("cudgel");
  SetId(  ({ "cudgel", "club" })  );
  SetAdjectives( ({"stout"}) );
  SetShort("a stout cudgel");
  SetLong( "This club is handy for putting unruly subjects "
    "in their place and is made of a stout piece of wood.");
  SetMass(200);
  SetValue(150);
  SetDamagePoints(1000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(15);
  SetVendorType(VT_WEAPON);
  SetRepairSkills(  ([ 
      "weapon smithing" : 4 
  ])  );
  SetMaterial("wood");
  SetRepairDifficulty(10);
}
