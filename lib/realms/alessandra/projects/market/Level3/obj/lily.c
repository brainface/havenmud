#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
  item::create();
  
  SetKeyName("lily");
  SetShort("a large white lily");
  SetId(  ({"lily", "flower"}) );
  SetAdjectives( ({"white", "large"}) );
  SetLong(
     "The six petals of this large lily curve gracefully outward and are "
     "a striking white, marred only by a thin golden stripe across the " 
     "center of the petal. The long orange stamens are covered in pollen." 
     );
  SetSmell("The lily has a heavy languorous scent.");
  SetTouch("The petals are soft.");
  SetMass(10);

}
