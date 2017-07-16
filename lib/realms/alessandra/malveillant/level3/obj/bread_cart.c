
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("cart");
  SetShort("a cart");
  SetId(  ({"cart"}) );
  SetAdjectives( ({"wooden", "bread"}) );
  SetLong(
     "This cart has been handsomely crafted out of wood and has a handle "
     "which attaches to the body of the cart in spirals of metal shaped into "
     "vines and leaves. Big woven baskets line the inside of the cart, and "
     "exotic fruits pile to almost overflowing. Attached to the sides of "
     "the cart are more baskets which carry freshly baked breads. The owner "
     "of the cart can't be far off."
     );
  SetPreventGet("You can't pick that up.");

}  
