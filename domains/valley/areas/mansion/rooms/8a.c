/* ballroom part 2
    kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a ballroom");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This part of the ballroom seems to be the more social "
          "section. Many people are gathered here and seem to be having a "
          "wonderful time talking and joking. A large chandelier hangs in "
          "this part of the room and the light glimmers off of it quite "
          "brilliantly.");
  SetItems( ([
      ({ "ballroom", "room" }) : (:GetLong:),
      ({ "people", "person" }) : "The people look rather happy.",
         "chandelier" : "The chandelier is quite beautiful.",
      ]) );
  SetExits( ([
       "west" : MANSION_ROOMS + "7a",
         ]) );
  SetInventory( ([
      MANSION_NPC + "old_man" : 1,
      MANSION_NPC + "old_woman" : 1,
      MANSION_NPC + "guard" : 1,
        ]) );
  SetSmell( ([
       "default" : "The scent of perfume and cologne is in the air.",
          ]) );
  SetListen( ([
       "default" : "Beautiful music can be heard below the constant talking.",
         ]) );
  }
