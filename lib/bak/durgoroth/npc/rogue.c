#include <lib.h>
#include "../durgoroth.h"
inherit LIB_LEADER;

static void create() {
   leader::create();
   SetTown("Durgoroth");
   SetMorality(-150);
   SetKeyName("Fowler");
   SetShort("Fowler");
   SetId( ({ "fowler","boy","young boy" }) );
   SetAdjectives( ({ "young" }) );
   SetLong("Fowler is a young boy who works for Mortilus.  "
           "He spends most of his days sweeping floors and "
           "running errands for Mortilus.  During the evening "
           "he spends his time cleaning the patrons tables and "
           "pockets, at Mortilus' request of course." );
   SetClass("rogue");
   SetGender("male");
   SetRace("daemon");
   SetLevel(15);
   SetAction(6,({
   		"!emote sweeps the floor.",
      "!emote eyes you cautiously.",
      "!emote looks you over carefully", }) );
   SetFreeEquip( ([
      "/domains/frostmarches/towns/durgoroth/obj/knife" : 2,
      ]) );
   SetPlayerTitles( ([
      "newbie" : "the Young Runner",
      "mortal" : "the Sneak Thief",
      "hm"     : "the Cutthroat",
      "legend" : "the Spy of Durgoroth",
      "avatar" : "the Lord of the Durgoroth Underground",
      "necromancer" : "the Raper of the Undead",
      "merchant" : "the Penny Pincher",
      "diviner" : "the Shadow Reader",
      "fighter" : "the Assassin",
      "evoker" : "the Manipulator of Shadows",
      ]) );
}
