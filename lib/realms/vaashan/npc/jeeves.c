#include <lib.h>
#include "../vaashan.h"
inherit LIB_NPC;

static void create() {
  ::create();

  SetKeyName("Jeeves");

  SetId( ({ "butler", "nosferatu" , "Jeeves" }) );

  SetAdjectives( ({ "tall", "well-dressed" }) );

  SetShort("Jeeves");

  SetLong(
    "This tall nosferatu is wearing a subdued suit of black. "
    "His eyes glow faintly red and his razor sharp fangs are "
    "visible when he smiles.  He looks as though he takes good "
    "care of himself and could do well in a fight."
  );

  SetRace("nosferatu");

  SetClass("animal");

  SetLevel(100);

  SetGender("male");

 /* SetAction(5, ({ 
    "Jeeves picks an invisible speck of dust off the drapes.",
  })
  
 
  );*/
}
