// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("orc shield");
  SetId( ({ "shield"}) );
  SetAdjectives( ({ "small", "orcish" }) );
  SetShort("a small orcish shield");
  SetLong(
    "This is an orc-crafted shield of a size orcs would consider small, but "
    "would still be deemed large by most other races. It is formed of a single "
    "piece of metal, folded and riveted into the shape of a shield, including "
    "a pair of handles on the inner side. Its front has been burnished to a "
    "high gloss. Altogether, it appears to be a simple yet functional piece "
    "of equipment."
  );
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetArmourType(A_SHIELD);
  SetSize(SIZE_LARGE);
  SetMass(250);
  SetValue(120);
  SetDamagePoints(800);
  SetWarmth(0);
  SetMaterial( ({ 
  	"metal" 
  }) );
  SetRepairDifficulty(20);
}
