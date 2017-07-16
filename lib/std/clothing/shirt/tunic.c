 /* tunic
  Luna 12/13/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("tunic");
  SetShort("an ornamented tunic");
  SetId( ({"tunic"}) );
  SetAdjectives( ({"green","cotton","ornamented","belted"}) );
  SetLong("This men's tunic is hunter green and made of "
          "durable cotton. It is ornamented with brass "
          "studs and is belted at the waist.");
  SetMass(35);
  SetSize(SIZE_SMALL);
  SetValue(60);
  SetDamagePoints(60);
  SetMaterial("textile");
  SetWarmth(10);
  SetArmourType(A_SHIRT);
}
