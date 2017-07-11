//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
  inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "textile" }) ); 
  SetKeyName("dress");
  SetShort("a pleated linen dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"pleated","linen",}) );
  SetLong("This pleated linen dress has a full skirt and a "            
          "body-hugging bodice. The soft white fabric reveals "
          "much and conceals little, but keeps the wearer "
          "protected from the elements much like mosquito "
          "netting might.");
  SetMass(70);
  SetProperty("multiples", 1);
  SetValue(300);
  SetDamagePoints(500);
  SetSize(SIZE_MEDIUM);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
