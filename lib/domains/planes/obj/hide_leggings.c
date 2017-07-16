// armour for a couple minor devils
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("charred hide leggings");
  SetId( ({ "leggings" }) );
  SetAdjectives( ({ "a", "pair", "of", "charred", "hide" }) );
  SetShort("a pair of charred hide leggings");
  SetLong(
    "This pair of leggings is crafted from the cured hide of some "
    "squamous beast. Thick pieces of hide sewn together with coarse "
    "thread cover both legs. A multitude of char "
    "marks and scratches covering the leggings attest to their "
    "durabilty."
 
  );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_PANTS);
  SetDamagePoints(2800);
  SetMass(200);
  SetMaterial( ({ "leather" }) );
  SetProperty("multiples", 1);
  SetSize(SIZE_LARGE);
  SetValue(500);
  SetVendorType(VT_ARMOUR);
  SetWarmth(5);
}
