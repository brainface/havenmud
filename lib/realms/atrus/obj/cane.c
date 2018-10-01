#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("a dragonstyk");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 6,
    "weapon smithing" : 6,
     ]) );
  SetShort("a wicked looking dragonstyk");
  SetAdjectives( ({ "wicked","wicked looking","long","dragonstyk" }) );
  SetId( ({ "dragonstyk", "cane" }) );
  SetLong("The fourty-eight inch long cane is topped with a steel figure "
          "of a dragon. It's shaft is wrought of cast iron, and the dragon "
          "is finely moulded. The dragon is coiled into a figure-eight with "
          "its wings protruding straight up from the body. Its lower claws "
          "fold around the shaft of the cane making the perfect flange to "
          "hold on the top. The claws are pressure welded to the shaft.");
  SetClass(15);
  SetDamagePoints(1000);
  SetValue(2000);
  SetMass(300);
  SetVendorType(VT_WEAPON);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  }
