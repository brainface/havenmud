
#include <lib.h>
#include <daemons.h>
#include "../durgoroth.h"

inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Niscronma");
  SetShort("Horror Niscronma, the Nemesis of Safety");
  SetId( ({ "niscronma", "horror", "daemon", "durg_nocombat",
       }) );
  SetAdjectives( ({ "horror" }) );
  SetLong(
    "Niscronma is walking abomination. Her face"
    " and visible skin are a virtual collage of"
    " battle wounds. Large white horns stand atop"
    " her head pointing directly up towards the sky."
    " She is missing part of her left wing and as such"
    " it hangs limply by her side. She is known"
    " throughout the ruins to be the oldest"
    " surviving horror and one wishing to join"
    " the ranks of the feared warrior class"
    " must speak to her."
  );
  SetRace("daemon");
  SetGender("female");
  SetClass("horror");
  SetLevel(250);
  SetTown("Durgoroth");
  SetMorality(-3000);
  SetInventory( ([
     DURG_OBJ "horror_helmet" : "wear helmet",
     DURG_OBJ "horror_plate"  : "wear suit",
     DURG_OBJ "horseshoe"     : "wear 1st horseshoe on left hoof",
     DURG_OBJ "horseshoe2"    : "wear 1st horseshoe on right hoof",
     DURG_OBJ "duster"        : "wield 1st duster",
     DURG_OBJ "duster2"       : "wield 1st duster",
    ]) );
  SetAction(5,  ({
     "!speak I'm getting quite hungry, perhaps you would"
            " make a good snack.",
     "!emote stretches her one good wing.",
     "!speak I have seen the greatness of the"
            " Lower Planes.",
     "!speak I am the revered eldest Horror.",
    }) );
  SetCombatAction(50, ({
    "!scream",
    "!disarm",
    "!disorient",
    "!scream",
  }) );
  SetPlayerTitles( ([
      "newbie"   : "the Contemptible Initiate of Fear",
      "mortal"   : "the Messenger of Fright",
      "hm"       : "Horror $N the Hated",
      "legend"   : "the Feared",
      "avatar"   : "the Long-Lived Tormentor of Dreams",
     ]) );
  SetFreeEquip( ([
     "/std/weapon/melee/brass_knuckles" : 2,
     DURG_OBJ "newb_chain" : 1,
     ]) );
}


