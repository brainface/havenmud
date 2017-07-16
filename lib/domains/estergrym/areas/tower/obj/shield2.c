// Leather shield with a thin metal plate on the inside 
// thus making it reinforced leather.

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("buckler");
   SetId( ({ "buckler" }) );
   SetAdjectives( ({ "elven","small" }) );
   SetShort("a small elven buckler");
   SetLong(
   "This elven buckler is small and round with a metal stud in the center. "
   "Hard leather stips have been placed and bolted to the buckler to wrap around "
   "into the center covering it completely. This buckler has two braided "
   "leather straps on the inside also bolted with thin metal studs. On the front "
   "is a yellow painted diamond which touches the circular edges."
   );
   SetVendorType(VT_ARMOUR);
   SetMass(30);
   SetSize(SIZE_SMALL);
   SetArmourClass(ARMOUR_REINFORCED);
   SetValue(70);
   SetDamagePoints(700);
   SetMaterial( ({ "leather" }) );
   SetArmourType(A_SHIELD);
   SetRepairDifficulty(25);
   SetProtectionBonus(SLASH, 1);
   SetProtectionBonus(WATER, -2);
   SetProperty("history",
    "This buckler was forged before the first GodsWar. It is "
	"very aged."
   );
   SetProperty("magic",                                             
    "The buckler wanes slightly in magical power. An odd "
	"ancient magic can be sensed which provides a slight "
	"advantage against sword wielders. "
   );
}
