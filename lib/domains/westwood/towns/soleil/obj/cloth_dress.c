// mahk 2018
// clothes for soleil
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterials( ({ "natural" }) );
       
  SetKeyName("leafy dress");
  SetShort("a leafy dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "leafy" }) );
  SetArmourType(A_BODY_ARMOUR);
  SetDamagePoints(1000);
  SetWarmth(5);
  SetValue(25);
  SetSize(SIZE_SMALL);
  SetLong("If you've ever wanted to wear a flowergarden, this is the dress for "
    "you. Broad green leafs mostly cover the skin while delicate lavender "
    "flowers poke out here and there. Tiny roots line the inside of the dress, "
    "to cling to fur you may or may not have.");
  SetWear("The dress clings to your skin a bit too literally.");
}                     

