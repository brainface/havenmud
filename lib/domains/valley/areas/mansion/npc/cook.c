/* a cook forthe mansion.
   kyla 3-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cook");
  SetId( ({"cook", "man"}) );
  SetAdjectives( ({"fat", "large"}) );
  SetGender("male");
  SetClass("fighter");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetShort("a large cook");
  SetLong("This large man is obviously the cook for the mansion. He is rather "
          "plump but appears to be quite handy with a knife and could take "
         "care of anyone who poses a threat.");
  SetSkill("knife combat", 1);
  SetLevel(30);
  SetMorality(-75);
  SetInventory( ([
      MANSION_OBJ + "but_knife" : "wield knife",
           ]) );

  SetAction(5, ({"The cook humms a little song to himself."}) );
  }
