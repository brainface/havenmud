#include <lib.h>
#include "../grymxoria.h"
inherit LIB_LEADER;

static void create()
{
  leader::create();
  SetKeyName("thundar");
  SetShort("Thundar, the Barbarian");
  SetId( ({ "barbarian", "nosferatu", "thundar" }) );
  SetLong(
    "Thundar is a hulking brute of a nosferatu. He wears "
    "no armor, nor wields a weapon for he went to the plains "
    "to learn the way of the barbarians. Thundar is willing "
    "pass on this knowledge to any he feels is worthy."
  );
  SetRace("nosferatu");
  SetGender("male");
  SetClass("barbarian");
  SetLevel(40);
  SetTown("Grymxoria");
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Barbarian of Grymxoria",
    "mortal" : "the Barbarian of Grymxoria",
    "hm"     : "the Fist of Grymxoria",
    "legend" : "the Lord Fist of Grymxoria",
    "avatar" : "the Destroyer",
    "fighter" : "the Gladiator of Grymxoria",
    "ranger" : "the Nomad",
  ]) );
  SetFreeEquip( ([
    STD_HACK + "hand-axe" : 1,
  ]) );
  SetFriends( ({ "lothar", "drahcir", "guard", "citizen" }) );
}

