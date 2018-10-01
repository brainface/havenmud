#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int DoCreate();

static void create() {
  armour::create( (: DoCreate :) );

  

  SetDestroyOnSell(1);
}

int DoCreate() {
  if ( (this_player()->GetTown() == "Haven") &&
     (this_player()->GetLevel() < 100) ) {

  SetKeyName("armour");
  SetId( ({ "armour", "armor" }) );
  SetAdjectives( ({ "plate" }) );
  SetShort("a armour");
  SetLong("This is a setlong.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetMass(50);
  SetValue(10);
  SetDamagePoints(200);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "metal" }) );
  SetWarmth(1);
  SetRepairSkills( ([
     "metal working" : 20,
  ]) );
  SetRepairDifficulty(40);
    return 1; 
}

}
