/*  A new cavalier object.  Let's see if this works. */
#include <lib.h>
#include "haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Dussel");
  SetShort("Dussel, the Lieutentant of Haven Town");
  SetId( ({ "dussel", "lieutenant" }) );
  SetAdjectives( ({ }) );
  SetClass("cavalier");
  SetRace("elf");
  SetLevel(40);
  SetMorality(250);
  SetCurrency( ([
     "imperials" : random(100),
     ]) );
  SetInventory( ([
     H_OBJ + "rapier" : "wield rapier",
     ]) );
  SetTown("Haven");
  SetFreeEquip( ([
      "/std/weapon/pierce/fencing_sword" : 1,
      ]) );
  SetPlayerTitles( ([
     "newbie" : "the Squire of Haven Town",
     "mortal" : "the Knight of Haven Town",
     "hm"     : "the Lord Knight of Haven Town",
     "avatar" : "the Knight Exemplar of Haven Town",
     ]) );
  SetLong("This is Dussel, the Lieutenant of Haven Town. He is standing "
          "in for Nastarum while Nastarum is on vacation.");
  SetGender("male");
  }
