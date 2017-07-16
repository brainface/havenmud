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
  SetShort("an embroidered dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"embroidered",}) );
  SetLong("The owner of this dress has embroidered azure and "            
          "emerald threads into the collar and hem to create "
          "a pattern of blooming lotuses. The sheer fabric "
          "hangs richly as if it were specially tailored. ");
  SetMass(70);
  SetProperty("multiples", 1);
  SetValue(400);
  SetDamagePoints(650);
  SetMaterial("textile");
  SetWarmth(15);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
}
