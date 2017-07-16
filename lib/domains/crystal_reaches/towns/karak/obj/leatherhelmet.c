#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather helmet");
  SetId( ({ "helmet" }) );
  SetAdjectives( ({ "tough", "leather" }) );
  SetShort("a tough leather helmet");
  SetLong(
    "This helmet is made of toughened leather, held together by small metal "
    "studs. It looks fairly durable, able to take a reasonable amount of "
    "punishment to protect the wearer from many physical attacks. It seems "
    "fairly comfortable, and has a thin fur lining that provides the wearer "
    "with a little warmth."     
  );
  SetMass(95);
  SetValue(175);
  SetMaterial( ({ "leather" }) );
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(5);  
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_HELMET);
  SetSize(SIZE_LARGE);
  SetDamagePoints(2500);
}
