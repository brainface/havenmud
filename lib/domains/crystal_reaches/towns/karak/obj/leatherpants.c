#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("leather pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "a", "pair", "of", "tough", "leather" }) );
  SetShort("a pair of tough leather pants");
  SetLong(
    "This pair of pants is made of toughened leather, held together by small metal "
    "studs. They look fairly durable, able to take a reasonable amount of "
    "punishment to protect the wearer from many physical attacks. They seem "
    "fairly comfortable, and have a thin fur lining that provides the wearer "
    "with a little warmth."    
  );
  SetMass(160);
  SetMaterial( ({ "leather" }) );
  SetValue(200);
  SetProperty("multiples", 1);
  SetWarmth(5);
  SetArmourClass(ARMOUR_LEATHER); 
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetSize(SIZE_LARGE);
 SetDamagePoints(2500);
}
