#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rose");
  SetShort("an ice rose");
  SetId(  ({"rose"}) );
  SetAdjectives( ({"ice" }) );
  SetLong("This ice rose grows only in the coldest "
    "places of the world. The stem is adorned with icy "
    "thorns before opening up to the beautiful pedals. "
    "The inner veins are visible through the transparent "
    "ice form. It appears very fragile.");
  SetMass(1);
  SetMaterial("natural");
  }
