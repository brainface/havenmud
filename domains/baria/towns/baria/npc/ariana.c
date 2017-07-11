//
// Created by Kyla
// Modified by Rhakz - Angel Cazares
// Date: 10/13/98
//
#include <lib.h>
#include <std.h>
#include "../jungle.h"
inherit LIB_SAGE;

static void create() {
  sage::create();
  SetKeyName("Ariana");
  SetId( ({ "ariana" }) );
  SetAdjectives( ({ "barian", "teacher" }) );
  SetShort("Ariana the Barian Teacher");
  SetLong(
     "Ariana is a woman who is dedicated to teaching the knowledge of "
     "languages to those whom would be willing to pay. She is short of "
     "stature and looks to be in poor shape. Her looks are not very dramatic, "
     "as she is not a very attractive person to see. Her hair is short and she "
     "looks as though she has seen a few battles in her day. Unlike her looks, "
     "she is very intelligent; She is one whom is dedicated to reading scrolls "
     "and spreading the wealth of knowledge that is linguistics. "
  );
  SetRace("human");
  SetMorality(200);
  SetClass("merchant");
  SetSkill("melee combat", 1, 1);
  SetLevel(20);
  SetTown("Baria");
  SetGender("female");
  SetCurrency( ([ 
      "chits" : 150 + random(50),
  ]) );
  RemoveLanguage("Enlan");
  SetLanguage("Barian", 100, 1);
  SetLanguage("Eltherian", 100);
  SetLocalCurrency("chits");
  SetLanguage("Draconian", 100);
  SetCharge(1000);
  SetInventory( ([
    STD_CLOTHING + "body/flare_sleeve_dress" : "wear dress",
  ]) );
}
