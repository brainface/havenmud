// parva ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetShort("a red bandana");
  SetId( ({ "bandana" }) );
  SetAdjectives( ({ "red", "silk"  }) );
  SetLong(
    "This is a red silk bandana, knotted together"
    " so that it can worn on the head. A paisley"
    " pattern is carefully stiched on its surface"
    " in white thread."
  );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_HELMET);
  SetDamagePoints(500);
  SetKeyName("red bandana");
  SetMaterials( ({ "textile" }) ); 
  SetSize(SIZE_MEDIUM);
  SetValue(50);
  SetWarmth(0);
}

