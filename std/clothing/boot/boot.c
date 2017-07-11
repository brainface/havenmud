#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
armour::create();
     SetKeyName("boots");
     SetShort("a pair of black boots");
     SetId( ({ "boots" }) );
     SetAdjectives( ({ "black"}) );
     SetLong("This is a pair of black boots.");
     SetMass(5);
    SetMaterial("leather");
    SetWarmth(5);
  SetProperty("multiples", 1);
   SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) );
     SetValue(10);
     SetVendorType(VT_ARMOUR);
     SetArmourType(A_BOOT);
     SetDamagePoints(100);
   }
