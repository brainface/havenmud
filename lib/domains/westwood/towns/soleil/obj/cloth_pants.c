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
       
  SetKeyName("leafy kilt");
  SetShort("a leafy kilt");
  SetId( ({ "kilt" }) );
  SetAdjectives( ({ "leafy" }) );
  SetArmourType(A_PANTS);
  SetDamagePoints(1000);
  SetWarmth(5);
  SetValue(25);
  SetSize(SIZE_SMALL);
  SetLong("Somewhere between a skirt and a houseplant turned upside down, "
    "this kilt provides the barest bit of modesty with broad, shiny green "
    "leafs. The still-living roots of the plants encircle the beltline in a "
    "way that's probably desperately uncomfortable for non-muezzins."
  );
  SetWear("The kilt clinches itself around your waist a bit too readily.");
}                     

