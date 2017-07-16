#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chainmail");
  SetShort("a battered vest of chainmail");
  SetId( ({ "vest", "chainmail" }) );
  SetAdjectives( ({ "chainmail", "battered" }) );
  SetLong("This vest of chainmail has been beaten"
          " to near uselessness. The metal ringlets"
          " that it is composed of are damaged and"
          " rusted.");
  SetDamagePoints(350);
  SetValue(20);
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(300);
  SetArmourType(A_VEST);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(15);
  SetWarmth(0);
}


