#include <lib.h>  
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helm");
  SetId(( {"helm" } ));
  SetShort("a boarhead helm");
  SetAdjectives( ({"boar","boarhead"}) );
  SetLong(
    "This helmet is crafted from the preserved head of a boar. The mouth has been "
    "stretched to allow the wearer to view out between the tusks, and additional "
    "padding has been added to the neck and skull to stop an errant blow from an "
    "arrow or club."
  );
  SetMass(75);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetMaterial("natural");
  SetWarmth(5);
  SetRepairDifficulty(70);
  SetValue(1750);
  SetDamagePoints(25000);
  SetArmourType(A_HELMET);
  SetWear("The tusks obscure your vision somewhat.");
}

