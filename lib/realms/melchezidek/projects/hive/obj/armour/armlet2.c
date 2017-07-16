#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chitin armlet");
  SetId( ({ "armlet" }) );
  SetAdjectives( ({"chitin"}) );  
  SetShort("a chitin armlet");
  SetLong("This armlet is made of the hard exoskeleton of a deceased"
          " thri-kreen. It is a soft sandy brown in color and is thick"
          " suggesting a high durability");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_LONG_GLOVE);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(100);
  SetValue(600);
  SetSize(SIZE_LARGE);
  SetDamagePoints(500);
  SetMaterial( ({"natural"}) );
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                       "armour smithing" : 8,
                       "natural working" : 8,
                  ]) );

  SetWarmth(0);
}
