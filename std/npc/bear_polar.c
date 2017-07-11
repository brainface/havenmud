//
// A polar bear
// Created by Zaxan@Haven
// 23rd of November, 1997
//

#include <lib.h>

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("polar bear");
  SetId( ({ "bear" }) );
  SetAdjectives( ({ "polar" }) );
  SetShort("a polar bear");
  SetLong(
    "This huge white mass stands tall as he walks through "
    "the mountain. He looks very cautious and protective "
    "of his turf."
  );
  SetGender("male");
  SetClass("animal");
  SetLevel(5);
  SetRace("bear");
}


/* Approved by Duuktsaryth on Wed Nov 26 00:11:49 1997. */
