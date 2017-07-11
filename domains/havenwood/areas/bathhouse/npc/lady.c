#include <lib.h>
#include "../bathhouse.h"
inherit LIB_NPC;

static void create() {
 npc::create();
 SetKeyName("woman");
 SetShort("a dirty looking woman");
 SetId( ({ "woman", "whore", "prostitute", "lady" }) );
 SetAdjectives( ({ "dirty", "dirty looking", "little" }) );
 SetRace("human");
 SetGender("female");
 SetClass("rogue");
 SetLevel(15);
 SetLimit(1);
 SetLong(
    "This poor girl looks to be about twenty years of age, but her "
    "eyes tell a different story. Hard, deepset blue eyes reveal "
    "a woman of unusual talents and adds an air of mystic to her "
    "otherwise simple appearance. Her body is slender and hardened "
    "making her a very acceptable target for any drunken sailor in "
    "town. Highly toned muscles suggest that this little lady is not "
    "as tender as she may appear."
  );
 SetInventory( ([
    BH_OBJ + "dress" : "wear dress",
    BH_OBJ + "knife" : "wield knife",
  ]) );
 SetAction(5, ({
    "!smile suggest",
    "!say Heya honey",
    "!wink",
  }) );
 SetCurrency("oros",random(50)+3);
 }

/** Approved by Laoise at Wed Jul 14 22:11:28 2004. **/