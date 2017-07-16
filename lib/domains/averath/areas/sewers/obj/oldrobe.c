// Averath Sewers
// Aerelus

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("tattered robe");
  SetShort("a tattered robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "tattered" }) );
  SetLong(
    "This plain looking robe is filthy, covered in dirt and stained with "
    "sewage water. It seems to offer almost no protection, but should at "
    "least be capable of providing some warmth."    
  );
  SetMass(30);
  SetValue(0);
  SetMaterial("textile");
  SetRepairDifficulty(90);
  SetArmourType(A_BODY_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_CLOTHING);  
  SetDamagePoints(100);
  SetSize(SIZE_MEDIUM);
}