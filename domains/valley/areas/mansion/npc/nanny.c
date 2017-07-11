/* the baby's nanny
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("nanny");
  SetShort("a plump nanny");
  SetId( ({"nanny"}) );
  SetAdjectives( ({"plump"}) );
  SetLong("This old nanny looks like the perfect woman to take care "
          "of a child. She appears to have a great deal of experience "
          "and it is not unlikely that she was Mr. Bank's nanny when he "
         "was small. Despite her age, she seems to be in rather good health "
         "presumably from chasing children around all day.");
  SetRace("human");
  SetClass("rogue");
  SetLevel(17);
  SetGender("female");
  SetFriends("baby");
  SetMorality(300);
  SetAction(5,
        ({ "The nanny looks at the baby with love in her eyes." }) );
  }
