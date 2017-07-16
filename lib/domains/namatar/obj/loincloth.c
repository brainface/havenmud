// Artanis@Haven (July 18, 2004)

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("loincloth");
  SetId( ({ "cloth", "loincloth" }) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather loincloth");
  SetLong(
     "This simple piece of clothing looks to have been crudely "
     "made from some animal hide. This piece of clothing provides little "
     "warmth or protection due to it's revealing nature. It covers "
     "only the loins and nothing more. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BELT);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(75);
  SetValue(20);
  SetDamagePoints(800);
  SetSize(SIZE_VERY_LARGE);
  SetMaterial( ({ "leather" }) );
  SetWarmth(1);
  SetRepairSkills( ([
     "leather working" : 1,
  ]) );
  SetRepairDifficulty(8);
}
