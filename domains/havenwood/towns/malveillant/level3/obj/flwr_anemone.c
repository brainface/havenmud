// Anemone for Flower Vendor
// Alessandra 2009

#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
  item::create();

  SetKeyName("anemone");
  SetShort("a delicate blue anemone");
  SetId(  ({"anemone", "flower"}) );
  SetAdjectives( ({"blue", "delicate"}) );
  SetLong(
     "Tiny clusters of leaves cling to the thin stem of this delicate flower. "
     "The petals are a vibrant violet blue and ruffle at the tips. A ring of "
     "tiny blue stamens circle the center of the flower."
     );
  SetSmell("The anemone's fragrance is a heady mixture of sweet and spice.");
  SetTouch("The delicate petals feel soft and thin.");
  SetMass(10);
  SetValue(15);

}
