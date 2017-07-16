//   by Alessandra 9/04    //
//   edited 9/11 to fix armour class   //
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   
  SetKeyName("skirt");
  SetShort("a short leather skirt");
  SetId( ({ "skirt" }) );
  SetAdjectives( ({ "short", "leather", "black" }) );
  SetLong(
     "This black leather skirt is fairly short and reveals much of "
     "the leg and thigh. The leather is soft and hangs low on the "
     "hips."
     );
  SetWear("The skirt is really short.");
  SetMass(5);
  SetWarmth(10);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(150);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(250);
  SetMaterial( ({ "leather" }) );
  SetRepairSkills( ([
     "leather working" : 1,
     ]) );
  SetRepairDifficulty(15);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
}
