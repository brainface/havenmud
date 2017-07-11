  /* velvet_cape
  Luna 12/14/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetKeyName("cape");
  SetShort("a velvet cape");
  SetId( ({"cape"}) );
  SetAdjectives( ({"satin-lined","black","velvet"}) );
  SetLong("This satin-lined cape has a generous mantle "
          "and hood with cut arm openings. It is black "
          "velvet, lined with purple satin.");
  SetMass(50);
  SetValue(200);
  SetDamagePoints(75);
  SetMaterial("textile");
  SetWarmth(30);
  SetArmourType(A_CLOAK);
}
