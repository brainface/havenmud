/* the male counterpart to the old couple
   kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("old man");
  SetShort("an old man");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "old", "strong"}) );
  SetLong("The wrinkles that outline his eyes indicate that this old man is in "
          "his mid to late fifties. His clothing seems to imply he was a well-"
          "respected member of the Haven Town Guard before his retirement. "
          "There is no indication that this man let his training cease after "
          "his retirement.");
  SetRace("human");
  SetClass("fighter");
  SetFriends("old woman");
  SetGender("male");
  SetLevel(35);
  SetMorality(50);
  SetAction(5,
         "The old man looks around the room with a well-trained eye.",
            );
  SetInventory( ([
      MANSION_OBJ + "cer_longsword" : "wield sword",
              ]) );
  }
