#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "tough", "leather" }) );
  SetShort("a pair of tough leather boots");
  SetLong(
    "These boots are made of toughened leather, held together by small metal "
    "studs. They look fairly durable, able to take a reasonable amount of "
    "punishment to protect the wearer from many physical attacks. They seem "
    "fairly comfortable, and have a thin fur lining that provides the wearer "
    "with a little warmth."     
  );
  SetMass(80);
  SetMaterial( ({ "leather" }) );
  SetValue(500);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(5);  
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1000);
}
