 /* cape
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
  SetKeyName("cape");
  SetShort("a gray cape");
 SetId( ({ "cape" }) );
  SetAdjectives( ({ "green","cotton","ornamented","belted" }) );
  SetLong("This cape has a generous hood and is full cut. "
          "It is dark gray and waterproof to protect "
          "against the elements.");
  SetMass(40);
  SetProperty("multiples", 1);
  SetSize(SIZE_MEDIUM);
  SetValue(80);
  SetDamagePoints(80);
  SetMaterial("textile");
  SetWarmth(25);
  SetArmourType(A_CLOAK);
}
