/* a butler for the mansion
    kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("butler");
  SetShort("Alteris the butler");
  SetId( ({ "alteris", "man", "butler" }) );
  SetAdjectives( ({"tall", "stuffy" }) );
  SetLong("Alteris stands about six feet high and is a rather scrawny "
          "man. Nevertheless, he is quite loyal and would never allow "
          "someone to harm the inhabitants of the mansion. His eyes "
         "have the icy quality of one who has seen too many deaths.");
  SetGender("male");
  SetRace("human");
  SetClass("rogue");
  SetLevel(25);
  SetMorality(-100);
  SetCurrency("imperials",150);
  SetInventory( ([
        ]) );
 
  SetAction(5, "Alteris looks around the foyer anxiously.");
  }

