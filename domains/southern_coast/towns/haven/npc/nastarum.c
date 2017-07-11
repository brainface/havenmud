#include <lib.h>
#include "haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("nastarum");
  SetRace("elf");
  SetGender("male");
  SetClass("cavalier");
  SetLevel(40);
  SetMorality(500);
  SetCurrency("imperials",random(70)+1);
  SetShort("Nastarum, Captain of the Haven Guard");
  SetLong(
    "Nastarum is the Captain of the Haven Guards. "
    "He teaches new recruits all that they need to "
    "know about combat and war."
    );
  SetInventory( ([
      H_OBJ + "rapier" : "wield rapier in right hand",
      ]) );
  SetId( ({ "captain", "nastarum" }) );
  SetTown("Haven");
  SetPlayerTitles( ([
     "newbie" : "the Squire of Haven Town",
     "mortal" : "the Knight of Haven Town",
     "high mortal" : "the Lord Knight of Haven Town",
     "legend" : "the Imperial Lord Knight of Haven Town",
     "avatar" : "the Supreme Imperial Lord Knight of Haven Town",
     "priest" : "the Paladin of Haven Town",
     "evoker" : "the Noble Mage of Haven Town",
     ]) );
  SetFreeEquip( ([
    "/std/weapon/pierce/fencing_sword" : 1,
    ]) );
  }
