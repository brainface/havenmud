#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("gemma");
  SetShort("Gemma, Lord Captain of the Grymxorian City Guard");
  SetId( ({
    "lord captain", "nosferatu", "captain", "gemma", "lord",
  }) );
  SetLong(
    "Gemma wears the utility grey livery of the Grymxorian "
    "city guard. The job of the guard is to enforce the "
    "laws of Warlord in the city and territory directly around "
    "Grymxoria. The guard is made up entirely of fighters. "
    "One might ask gemma about becoming a member."
  );
  SetRace("nosferatu");
  SetFriends( ({ "cyra", "guard", "citizen" }) );
  SetClass("cavalier");
  SetLevel(34);
  SetGender("female");
  SetTown("Grymxoria");
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
    G_OBJ + "nosf_axe" : "wield axe",
    G_OBJ + "nosf_armor" : "wear armor",
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Trainee of the Grymxorian Guard",
    "mortal" : "the Officer of the Grymxorian Guard",
    "hm"     : "the Sergeant of the Grymxorian Army",
    "legend" : "the Captain of the Grymxorian Guard",
    "avatar" : "the Lord Captain of the Grymxorian Guard",
    "rogue"  : "the Warlord's Assassin",
    "merchant" : "the Customs Inspector of the Grymxorian Guard",
    "enchanter" : "the Sorcerer of the Grymxorian Guard",
    "cleric" : "the Inquisitor of the Grymxorian Guard",
   ]) );
  SetFreeEquip( ([
    STD_HACK + "hand-axe" : 1,
  ]) );
}
