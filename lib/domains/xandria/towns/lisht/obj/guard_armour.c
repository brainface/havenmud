//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of bronze chainmail");
  SetId( ({ "suit", "chainmail" }) );
  SetAdjectives( ({ "bronze" }) );
  SetLong("This chainmail might be the type worn by "
          "Guards of Lisht. It seems durable.");
  SetValue(4300);
  SetMass(300);
  SetWarmth(0);
  SetDamagePoints(3000);
  SetProperty("multiples",1);
  SetMaterials( ({ "metal" }) );
  SetArmourClass(ARMOUR_CHAIN);
 }
