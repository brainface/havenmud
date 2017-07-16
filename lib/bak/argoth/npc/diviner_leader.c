/*  A diviner leader, since there is not one. */
#include <lib.h>
#include "../argoth.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("vyrten");
  SetShort("Vyrten Eyeshine the Master Evoker of Argoth");
  SetId( ({ "vyrten", "vyrten eyeshine", "eyeshine" }) );
  SetAdjectives( ({ }) );
  SetTown("Karak");
  SetRace("orc");
  SetClass("evoker");
  SetLevel(30);
  SetGender("male");
    SetLong("Vyrten Eyeshine is an infamous orc diviner, known far and "
    "wide for his aptitude at finding information about others.  He has "
    "often been used to help extract information from unwilling prisoners.");
  SetPlayerTitles( ([
    "newbie" : "the Aspiring Evoker",
    "mortal" : "the Evoker of Argoth",
    "hm"     : "the Master Evoker of Argoth",
    "avatar" : "the Omniscient Wizard of Argoth",
    ]) );
  SetFreeEquip( ([
    "/std/weapon/pole/staff.c" : 1,
    ]) );
  SetSpellBook( ([
      "detect magic" : 100,
      "research history" : 100,
      "discern location" : 100,
      "telepathy" : 100,
      "discern magic" : 100,
    ]) );
}
