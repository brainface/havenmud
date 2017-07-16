#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
  item::create();

  SetKeyName("hellebore");
  SetShort("a deep purple hellebore");
  SetId(  ({"hellebore", "flower"}) );
  SetAdjectives( ({"deep", "purple"}) );
  SetLong(
     "The yellow stamens of the hellebore are framed by short, plump petals "
     "which curve into near points. The deep purple of the petals fades "
     "slightly toward their tips. Long, thin evergreen leaves fan out "
     "from underneath leading to a thick stem."
     );
  SetSmell("The flower smells faintly of rotten onions.");
  SetTouch("The stem and leaves feel fuzzy.");
  SetMass(10);

}
