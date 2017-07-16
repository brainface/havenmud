/* the female counterpart to the old couple
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("old woman");
  SetShort("an old woman");
  SetId( ({"woman" }) );
  SetAdjectives( ({ "old" }) );
  SetLong("What this cute old woman lacks in stature she makes up in spunk. "
          "Her eyes sparkle with mischief and her delicate fingers seem to "
           "move quicker than one's eyes can follow.");
  SetGender("female");
  SetRace("human");
  SetClass("rogue");  
  SetLevel(28);
  SetFriends("old man");
  SetMorality(-75);
  SetInventory( ([
     	MANSION_OBJ + "dagger1" : "wield dagger",
      ]) );
  SetCurrency("imperials",150);

  SetAction(5,({ 
  		"The woman looks you over with a careful eye." 
  		}) );
  }
