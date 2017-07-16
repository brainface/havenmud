#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../ogrelair.h"
inherit LIB_SENTIENT;
 
static void create() {
  sentient::create();
  SetKeyName("ogre priest");
  SetRace("ogre");
  SetClass("priest");
  SetLevel(random(10) + 85);
  SetGender("male");
  SetShort("a huge ogre priest");
  SetId( ({ "ogre", "priest" }) );
  SetAdjectives( ({ "huge", "ogre" }) );
  SetReligion("Kuthar");
  SetFriends( ({ "ogre" }) );
  SetLong("This huge ogre appears to be the leader of his small "
    "group of priests, being slightly better dressed and appearing "
    "to be slightly more focused on what is going on around him. "
    "His face is scarred, and he appears to be missing his left ear.");    
  SetAction(5, ({ "!emote scratches his head, as if deep in thought.", 
    "!grunt" }) );
  SetCombatAction(40, ({
    "!cast purify",    
    }) );    
  SetMorality(-500);
  SetInventory( ([
     LAIR_OBJ + "boots" : "wear boots",
     LAIR_OBJ + "breastplate" : "wear breastplate",
     LAIR_OBJ + "cuisse" : "wear cuisse",
     LAIR_OBJ + "gauntlet" : "wear first gauntlet on right hand",
     LAIR_OBJ + "gauntlet" : "wear first gauntlet on left hand",
     LAIR_OBJ + "helm" : "wear helm",     
     "/std/weapon/blunt/iron_mace" : "wield mace",     
     ]) );
  SetCurrency("shrydes", 600);
  SetFirstCommands( ({
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
        "cast barrier of faith",
  }) );
  SetSpellBook( ([
    "barrier of faith"  : 100,
    "purify"            : 100,    
  ]) );
  SetSkill("heavy plate armour", 150, 1);
}