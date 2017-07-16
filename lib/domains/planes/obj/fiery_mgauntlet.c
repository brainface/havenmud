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
  SetKeyName("gauntlet");
  SetId(( {"gauntlet" } ));
  SetShort("a fiery mithril gauntlet");
  SetAdjectives( ({"mithril", "fiery"}) );
  SetLong(
    "This mithril gauntlet is engraved with flames from "
    "the base reaching out to the fingers. "
    "It emanates a soft glow, the engraved flames coming to life "
    "with the fiery shimmer. "
    "It offers superb protection "
    "to the wearer's hand, while allowing adequate maneuverability. " 
    );     
  SetMass(35);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("mithril");
  SetRepairDifficulty(60);
  SetValue(15000);
  SetDamagePoints(5000);
  SetArmourType(A_GLOVE);
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
