// haven ferry captain
// mahk '10
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); 
  SetShort("a white sailor hat");
  SetId( ({ "hat" }) );
  SetKeyName("hat");
  SetAdjectives( ({ "white", "sailor" }) );
  SetLong(
    "This hat is made of white canvas. The brim is rolled "
    "upwards and a red dragon atop a pair of scales is "
    "stiched to the front."
  );
  SetArmourClass(ARMOUR_CLOTH); 
  SetArmourType(A_HELMET);
  SetMass(30);
  SetDamagePoints(300);
  SetMaterials( ({ "textile" }) ); 
  SetSize(SIZE_MEDIUM);
  SetValue(0);
  SetWarmth(5);
}

