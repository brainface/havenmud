//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetShort( "a linen dress" );
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "linen" }) );
  SetLong(
    "This dress is made of semi-transparent fluted linen,"
    "which gently caresses the curves of the slim body it "
    "was made for.");
  SetValue(30);
  SetMass(45);
  SetProperty( "multiples", 1);
  SetMaterials( ({ "textile" }) );
  SetWarmth(20);
  SetDamagePoints(700);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  }
