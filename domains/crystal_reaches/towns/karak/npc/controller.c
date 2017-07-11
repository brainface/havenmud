#include <lib.h>
#include <domains.h>
#include "../karak.h"
inherit LIB_CONTROLLER;

static void create() {
  ::create();
  SetKeyName("pranak");
  SetShort("Pranak, Bandmaster of the Ravening Horde");
  SetId( ({ "pranak", "bandmaster", "giver" }) );
  SetAdjectives( ({ "pranak", "bandmaster", "of the horde", "ravening",
  	                "of the ravening horde", }) );
  SetRace("orc");
  SetClass("fighter");
  SetLevel(50);
  SetGender("male");
  SetTown("Karak");
  SetReligion("Saahagoth");
  SetLong(
    "Pranak is an orc of average height with wide stocky body "
    "covered in scars. A large scar runs from his left ear to his left eye, "
    "which makes Pranak uglier than normal for an orc. Dealer has placed Pranak "
    "as Bandmaster of the Ravening Horde to give orders to citizens of "
    "Karak Varn. If you are interested, you need to <ask pranak for "
    "quest>."
    );
  SetMorality(-1000);
  SetInventory( ([
    KARAK_OBJ + "axe"   : "wield axe in right hand",
    KARAK_OBJ + "runea"  : "wear armour"
    ]) );
  	
}

void eventGreet(object who) {
  ::eventGreet(who);
  SetAction(15, ({
    "!speak You could ask me for a quest.",
    "!speak You could request quests from me.",
  }) );
}


