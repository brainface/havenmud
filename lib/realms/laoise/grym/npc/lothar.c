#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("lothar");
  SetShort("Lothar Lionkiller, the hunter");
  SetId( ({ "lothar lionkiller", "lionkiller", "lothar",
    "hunter" })  );
  SetLong(
    "Lothar is more sinew than muscle. His great agility "
    "can be seen everytime he enters the arena. It is "
    "Lothar who stalks and captures the great beasts used in "
    "the arena games. Those who wish to learn these ways "
    "need only ask.");
  SetRace("nosferatu");
  SetGender("male");
  SetClass("valkyr");
  SetLevel(45);
  SetTown("Grymxoria");
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
  ]) );
  SetPlayerTitles(  ([
    "newbie" : "the Apprentice Hunter of Grymxoria",
    "mortal" : "the Hunter of Grymxoria",
    "hm" : "the GameKeeper of Grymxoria",
    "legend" : "the Master GameKeeper of Grymxoria",
    "avatar" : "the Lord Master GameKeeper of Kaille",
  ]) );
  SetFreeEquip( ([
    STD_PROJECTILE + "bola" : 1
  ]) );	
  SetFriends( ({ "thundar", "drahcir", "guard" }) );
}
