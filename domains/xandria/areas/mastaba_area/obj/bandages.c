//Selket@Haven
//2006
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH); 
  SetMaterials( ({ "textile"}) ); 
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetKeyName("bandages");
  SetId( ({ "bandages" }) );
  SetShort("bandages");
  SetLong("These ancient bandages are stained with blood and other "
          "fluids. They are dusty and crackle when touched, as if "
          "they might disintegrate under slight pressure. Although "
          "they cover almost the entire body, they offer no protection "
          "against the cold and barely protect against being cut "
          "to pieces");
  SetMaterial( ({ "textile" }) );
  SetWarmth(1);
  SetMass(70);
  SetValue(50);
  SetDamagePoints(700);
  }
