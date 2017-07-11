#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("gemma");
  SetShort("Gemma, Lord Captain of the Grymxorian City Guard");
  SetId( ({ "lord captain", "nosferatu", "captain", "gemma" }) );
  SetAdjectives( ({ "lord", "captain", "nosferatu" }) );
  SetLong(
    "Gemma wears the utility grey livery of the Grymxorian "
    "city guard. The job of the guard is to enforce the "
    "laws of Warlord in the city and territory directly around "
    "Grymxoria. The guard is made up entirely of fighters.  "
    "One might ask Gemma about becoming a member."
  );
  SetRace("nosferatu");
  SetFriends( ({ "cyra", "guard", "citizen" }) );
  SetClass("cavalier");
  SetLevel(140);
  SetGender("female");
  SetTown("Grymxoria");
  SetMorality(-2000);
  SetInventory( ([
    G_OBJ + "nosf_sword" : "wield sword",
    G_OBJ + "nosf_rapier" : "wield rapier",
    G_OBJ + "nosf_armor" : "wear armor",
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Trainee of the Grymxorian Guard", 
    "mortal" : "Officer $N of the Grymxorian Guard", 
    "hm" : "Sergeant $N of the Grymxorian Army", 
    "legend" : "Captain $N of the Grymxorian Guard", 
    "avatar" : "Lord Captain $N of the Grymxorian Guard",
    "merchant" : "the Customs Inspector of the Grymxorian Guard", 
    "enchanter" : "Arch-Mage $N of the Grymxorian Guard", 
    "cleric" : "Inquisitor $N of the Grymxorian Guard", 
    "necromancer" : "the Dark Heart of the Grymxoria Guard", 
  ]) );
  SetFreeEquip( ([
    STD_PIERCE + "fencing_sword" : 1,
  ]) );
}
