// torak@haven 2013

#include <lib.h>
#include <vendor_types.h>

inherit LIB_POLE;

mixed DropTest(object who);

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
  SetPreventDrop( (: DropTest :) );
  SetPreventGet("The holy pole refuses to be gotten.");
  SetPreventPut("The pole does not fit in there!");
  SetMass(10);
  SetStrength(5000);
  SetVendorType(VT_FISHING);
  SetChance(99);
  SetDamagePoints(950);
  SetMaterial( ({ "mithril", "wood" }) );
  SetRepairDifficulty(20);
  SetProperty("magic", "This fishing pole is a gift from the "
    "God of Storms to his most devout cleric.");
  SetProperty("history", "This fishing pole is a gift from the "
    "God of Storms to his most devout cleric.");
  SetRadiantLight(5);
  SetDestroyOnSell(1);
  SetPreventSteal(1);
}

mixed DropTest(object who) {
      send_messages( ({ "exact" }),
         "%^CYAN%^The holy pole returns to the waters from which it came.%^RESET%^",
         this_object(), 0, who
       );
    call_out( (: eventDestruct :), 0 );
  return 0;
}
