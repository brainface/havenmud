/*  Wooden Armour */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("wooden armour");
  SetId( ({ "vest", "armour" }) );
  SetAdjectives( ({ "wood", "wooden" }) );
  SetShort("a wooden vest of armour");
  SetLong(
     "This piece of armour looks to have been carved out of wood. "
     "The wood looks to have been carved by hand over a long period "
     "of time. This piece of armour is not particulary strong compared "
     "to other materials, but it is light and offers flexibility. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  SetArmourClass(ARMOUR_NATURAL); // Torak2013 formerly reinforced
  SetValue(65);
  SetMass(65);
  SetDamagePoints(1050);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "wood" }) );
  SetWarmth(2);
  SetRepairSkills( ([
     "wood working" : 0,
     "armour smithing" : 0,
    ]) );
  SetRepairDifficulty(5);

  }
