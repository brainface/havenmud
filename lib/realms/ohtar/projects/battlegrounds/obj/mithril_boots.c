#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId(( {"boots", "chainmail", "chain", "mail" } ));
  SetShort("a pair of mithril chainmail boots");
  SetAdjectives( ({"mithril", "chain", "mail", "chainmail"}) );
  SetLong(
    "These solid chainmail boots are crafted of mithril. This "
    "particular mithril was high pressure treated and then weaved "
    "in the finest mines of the dwarves. The inside has been "
    "lined with silk and stuffed with cotton for the most comfort "
    "and warmth possible. The wearer's feet are completely covered "
    "providing a good amount of protection. "
  );   
  SetProperty("multiples", 1);
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_LARGE);
  SetMaterial("mithril");
  SetWarmth(2);
  SetRepairDifficulty(70);
  SetValue(3000);
  SetDamagePoints(3000);
  SetArmourType(A_BOOT);  
}
