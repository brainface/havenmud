// Torak@Haven 2013
// For Lord H in the Fire Planes
// & mithril for medium sized players

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "mithril", "fiery" }) );
  SetShort("a fiery mithril breastplate");
  SetLong(
    "This mithril breastplate is engraved with flames from the "
    "base reaching up to the shoulders. "
    "It emanates a soft glow, the engraved flames coming to life "
    "with the fiery shimmer. "
    "It offers superb protection to the wearer's torso and upper arms. "
  );
  SetMass(1200);
  SetMaterial( ({
    "mithril",
    }) );
  SetRepairDifficulty(60);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetValue(15000);
  SetDamagePoints(8000);
  SetArmourType(A_ARMOUR);
  SetVendorType(VT_ARMOUR); 
  SetRadiantLight(5);
  SetProperty("magic",
    "This gauntlet was crafted by some fell smith of the "
    "planes of fire."
  );
  SetProperty("history",
    "This gauntlet formerly belonged to Lord Hephaeston from "
    "the planes of fire."
  );  
} 
