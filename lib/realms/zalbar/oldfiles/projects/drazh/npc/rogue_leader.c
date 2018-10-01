// Modified by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("vrinkak");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"vrinkak","skaven","councilman"}) );
  SetShort("Vrinkak the Sneak");
  SetLong(
     "This hunched over skaven has a mean grin on his snout. Filthy "
     "matted sandy fur covers Vrinkak's body. Vrinrak is of medium "
     "height who has a slight hunch in his back. He looks vigorous "
     "and tough, suggesting he could teach a thing or two to any who "
     "would care to listen."
     );
  
  SetGender("male");
  SetRace("skaven");
  SetClass("rogue");
  SetLevel(65);
  SetCurrency("roni",random(1000));
  SetInventory( ([
     V_OBJ + "hooded_robe"  : 
       "wear robe on torso and right arm and right leg and left arm and left leg",
     V_OBJ + "lpants"       : "wear pants",
     V_OBJ + "lvest"        : "wear vest",
     V_OBJ + "guard_knife"  : "wield knife",
     ]) );
  SetFreeEquip( ([
     V_OBJ + "newbie_knife" : 1,
     V_OBJ + "hooded_robe"  : 1,
     ]) );
 SetMorality(-1500);
 SetPlayerTitles( ([
     "newbie"  : "the Inexperienced Gutterunner",
     "mortal"  : "the Night Creeper",
     "hm"      : "the Feared Nightrunner",
     "legend"  : "the Loathsome Nightstalker",
     "avatar"  : "the Shadow of the Night",
     "fighter" : "the Blood Hunter of Vacazar",
     "priest"  : "the Wicked Rapscallion",
   ]) );  
  SetLimit(1);
  SetFriends( ({
     "skaven","black agent","watchman","councilman"
     }) );
  SetAction(2, ({
     "!speak You here to join up with us?",
     "!speak I can teach you many things.",
     "!speak You dislike being poor?",
     "!speak Join us and I'll teach you how to make a good "
     "living off of the fools that surround us. ",
     }) );
  SetCombatAction(5, ({
     "!speak I'll teach you to mess with me. ",
     "!speak Die!",
     "!disorient",
     "!disarm",
     }) );
}