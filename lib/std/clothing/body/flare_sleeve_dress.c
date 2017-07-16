 /* flare sleeve dress
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("dress");
  SetShort("a flare sleeve dress");
  SetId( ({"dress"}) );
  SetAdjectives( ({"green","ankle-length"}) );
  SetLong("This hunter green ankle-length dress has flared "
          "sleeves and tapers at the waist. It can be "
          "worn with either a bodice or overdress.");
  SetMass(40);
  SetValue(75);
  SetDamagePoints(550);
  SetMaterial("textile");
  SetWarmth(15);
  SetArmourType(A_BODY_ARMOUR);
}
