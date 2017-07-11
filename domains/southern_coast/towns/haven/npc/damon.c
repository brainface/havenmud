#include <lib.h>
#include "../haven.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("damon");
  SetShort("Damon Falterless, the Warrior of Haven Town");
  SetId( ({ "damon", "warrior", "falterless", "fighter" }) );
  SetAdjectives( ({ "damon", "falterless" }) );
  SetLong("Damon is a warrior extreme.  His large build and \n"
          "hulking manner suggest that he is a fighter to the \n"
          "core.  In his eye is a gleam that he could teach a few \n"
          "things to anyone willing to listen.");
  SetRace("human");
  RemoveLanguage("Enlan");
  SetLanguage("Eltherian",100,1);
  SetClass("fighter");
  SetSkill("melee combat",1,1);
  SetLevel(40);
  SetGender("male");
  SetMorality(250);
  SetAction(5, ({
    "!speak Would you like to join fighters?",
    "!speak A fighting life is a life for me!",
    "!speak Ours is not the ways of the Guard, ours is more fun!",
    }) );
  SetCombatAction(15, ({
	  "!disarm",
	  "!disorient",
		}) );
  SetPlayerTitles( ([
    "newbie" : "the Warrior of Haven Town",
    "mortal" : "the Soldier of Haven Town",
    "hm"     : "the Guardsman of Haven Town",
    "legend" : "the Greater Guardsman of Haven Town",
    "avatar" : "the Supreme Guardsman of Haven Town",
    ]) );
  SetTown("Haven");
  SetFreeEquip( ([
    "/std/weapon/hack/hand-axe" : 1,
    ]) );
 }
