/* the male counterpart to the young couple
    kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("young man");
  SetShort("a strapping young man");
  SetId( ({ "man" }) );
  SetAdjectives( ({"young", "strapping"}) );
  SetLong("This handsome young man is very well built and very attractive. "
          "He seems to have a protective aura about him as if he would never "
          "let any harm come to the woman he loves. His well-toned muscles "
          "indicate his ability to protect her from anything that might "
          "want to hurt her.");
  SetGender("male");
  SetClass("cavalier");
  SetRace("human");
  SetLevel(30);
  SetMorality(75);
  SetInventory( ([
      MANSION_OBJ + "cer_longsword" : "wield sword",
            ]) );
  SetFriends("young woman");
  SetAction(6, "The young man looks you up and down suspiciously.");
  SetCombatAction(4, "!slice");
  SetCurrency( ([
         "imperials" : 300,
             ]) );
  }
