//A statue of yours truly//
#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("statue");
  SetMaterials( ({ "natural" }) );
  SetShort("a statue of Alessandra");
  SetId(  ({"statue"}) );
  SetAdjectives( ({" "}) );
  SetLong(
     "A beautiful piece of artwork, this statue depicts the goddess Alessandra "
     "in all her feminine glory. Flawless marble has been carved to form the "
     "soft curves of the Soirin goddess, shown bare, but for her flowing hair "
     "and a length of windblown looking scarf clinging to her. Her bare feet "
     "stand nestled amongst a layer of black roses. The statue has a long and "
     "interesting history, and until recently was scattered throughout "
     "Kailie in pieces. It was restored by the Soirin saviour, Sekh Himantaro "
     "on this day of Moonday Scales the 9th, Year 10."
     );
  SetPreventGet("The statue is much too heavy to just carry around.");

}  
