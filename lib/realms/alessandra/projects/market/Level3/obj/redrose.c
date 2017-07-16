#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
  item::create();
  
  SetKeyName("rose");
  SetShort("a beautiful red rose");
  SetId(  ({"rose", "flower"}) );
  SetAdjectives( ({"red", "beautiful", "velvet", "velvety"}) );
  SetLong(
     "A long stem with few deep green leaves leads to a velvety red bulb in "
     "partial bloom; the petals barely starting to make their outward fold. "
     "The sturdy stem bears no thorns."
     );
  SetSmell("The rose has a sweet, heady fragrance.");
  SetTouch("The petals feel like satin.");
  SetMass(10);

}
