#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../ogrelair.h"
inherit LIB_SENTIENT;
 
static void create() {
  sentient::create();
  SetKeyName("scruffy ogre");
  SetRace("ogre");
  SetClass("priest");
  SetLevel(random(5) + 60);
  SetGender("male");
  SetShort("a scruffy ogre");
  SetId( ({ "ogre" }) );
  SetAdjectives( ({ "scruffy" }) );
  SetReligion("Kuthar");
  SetFriends( ({ "ogre" }) );
  SetLong("This scruffy ogre has a vacant expression on his face, "
    "making him seem somewhat unintelligent. His huge body and "
    "bulging muscles, however, suggest that he could hold his own "
    "in combat.");  
  SetWander(5);
  SetAction(5, ({ "!emote mutters something uninteligable.", "!grunt" }) );
  SetCombatAction(35, ({
    "!cast harm body",    
    }) );    
  SetMorality(-1000);
  SetInventory( ([
     "/std/clothing/lg_coat" : "wear coat",
     "/std/weapon/blunt/iron_mace" : "wield mace",     
     ]) );
  SetCurrency("shrydes", 200);
  SetFirstCommands( ({
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
  }) );
  SetSpellBook( ([
    "barrier of faith"  : 20,
    "harm body"         : 40,    
  ]) );
  }