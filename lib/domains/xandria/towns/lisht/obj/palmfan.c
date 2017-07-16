#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("fan");
  SetShort("a palm leaf fan");
  SetId(  ({ "fan", "leaf" }) );
  SetAdjectives( ({ "palm", "giant" }) );
  SetLong(
     "This giant palm leaf has no purpose and is worth nothing."
     );

} 
