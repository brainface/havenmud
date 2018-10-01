#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("vest");
  SetId(( {"vest"} ));
  SetShort("a tailored dress vest");
  SetAdjectives( ({"dress", "tailored"}) );  
  SetLong(
    "This comfortable vest has been tailored to the exact "
    "specifications for the gnome it was made for. There is a "
    "fine red lining and a solid black outer face. The front closes "
    "with two buttons."    
  );   
  SetMass(350);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_SMALL);
  SetMaterial("cloth");
  SetWarmth(0);
  SetRepairDifficulty(130);
  SetValue(400);
  SetDamagePoints(400);
  SetArmourType(A_VEST);  
  SetWear("The tailored vest squeezes a bit around the stomach.");
}
