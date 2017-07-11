// Torak@Haven 2013
// For Lord H in the Fire Planes
// & mithril for medium sized players

#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helm");
  SetId(( {"helm" } ));
  SetShort("a fiery mithril helm");
  SetAdjectives( ({ "mithril", "fiery" }) );
  SetLong(
    "This mithril helm is engraved with flames around its base. "
    "It emanates a soft glow, the engraved flames coming to life "
    "with the fiery shimmer. "
    "The helm fully covers the wearer's head and offers superb "
    "protection. An eye slit in the front allows the wearer to see. "
    );     
  SetMass(50);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("mithril");
  SetRepairDifficulty(60);
  SetValue(15000);
  SetDamagePoints(5000);
  SetArmourType(A_HELMET);
  SetRadiantLight(5);
  SetProperty("magic",
    "This helm was crafted by some fell smith of the "
    "planes of fire."
  );
  SetProperty("history",
    "This helm formerly belonged to Lord Hephaeston from "
    "the planes of fire."
  );   
}
