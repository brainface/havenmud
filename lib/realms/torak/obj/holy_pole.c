#include <lib.h>
#include <vendor_types.h>
inherit LIB_POLE;

static void create() {
  pole::create();
  SetKeyName("pole");
  SetShort("a holy mithril fishing pole");
  SetId( ({ "pole" }) );
  SetAdjectives( ({ "holy","fishing", "mithril" }) );
  SetLong("This fishing pole is made of tempered bamboo and "
    "plated in mithril. Engraved along its shaft are images "
    "of waves across the ocean and dolphins at play. Its "
    "size is perfect for deep sea fishing. This is a "
    "fishing pole worthy of a Damhair Cleric and is a symbol "
    "reserved for the most devout. It appears to glow "
    "with its own faint light.");
  SetClass(10);
  SetValue(0);
  SetPreventDrop("You would never part with a holy relic!");
  SetPreventGet("The holy pole refuses to be gotten.");
  SetMass(10);
  SetStrength(5000);
  SetVendorType(VT_FISHING);
  SetChance(99);
  SetDamagePoints(950);
  SetMaterial( ({ "mithril", "wood" }) );
  SetProperty("magic", "This fishing pole is a gift from the "
    "God of Storms to his most devout cleric.");
  SetProperty("history", "This fishing pole is a gift from the "
    "God of Storms to his most devout cleric.");
  SetRadiantLight(5);
}
