#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather cuirass");
  SetId( ({ "cuirass" }) );
  SetAdjectives( ({ "tough", "leather" }) );
  SetShort("a tough leather cuirass");
  SetLong(
    "This cuirass is made of toughened leather, held together by small metal "
    "studs. It looks fairly durable, able to take a reasonable amount of "
    "punishment to protect the wearer from many physical attacks. It seems "
    "fairly comfortable, and has a thin fur lining that provides the wearer "
    "with a little warmth."     
  );
  SetMass(175);
  SetMaterial( ({ "leather" }) );
  SetValue(250);
  SetWarmth(5);
  SetArmourClass(ARMOUR_LEATHER);  
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(2500);
}
