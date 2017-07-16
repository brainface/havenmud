
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("skull");
  SetId( ({ "cracked" }) );
  SetAdjectives( ({ "white", "small" }) );
  SetShort( "a white cracked skull" );
  SetLong( "It appears to have been cracked on the top of the skeleton "
           "ages ago. Its shape is small, but humanoid and is covered in "
           "dust. The jaw bone remains connected to the skull and the "
           "entire thing emits a black flame.");
  SetRadiantLight(-5);
  SetPreventGet("The skull is magically sealed to the column.\n"
                "A quiet laughter is heard.");
    }
