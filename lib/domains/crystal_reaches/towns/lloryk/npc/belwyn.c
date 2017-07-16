#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;


static void create() {
  ::create();
  SetKeyName("belwyn");
  SetRace("halfling");
  SetClass("priest");
  SetLevel(50);
  SetGender("male");
  SetShort("Belwyn Finkleton, Supreme Commissar of Eclat");
  SetId( ({ "belwyn","finkleton", "commissar" }) );
  SetAdjectives( ({ "belwyn", "supreme", "commissar" }) );
  SetLong("Belwyn has a look in his eye. A look like he is staring "
          "into the future and sees that history knows his cause "
          "is just and right. His slightly smudged robes are no "
          "distraction from his overall mission to spread the "
          "word of Eclat across Kailie.");
  SetTown("Lloryk");
  SetReligion("Eclat");
  SetSpellBook( ([
    "sanctify"           : 100,
    "bless"              : 100,
    ]) );
  SetInventory( ([ 
    LLORYK     "obj/crobes"      : "wear robe",
    STD_WEAPON "blunt/iron_mace" : "wield mace"]) );
  SetPlayerTitles( ([
    "newbie"   : "the Student of Eclat",
    "mortal"   : "the Follower of Eclat",
    "hm"       : "the Commissar of Eclat",
    "fighter"  : "the Proletarian",
    "cavalier" : "the Exporter of Freedom"
    ]) );
  SetFreeEquip( ([
    STD_WEAPON "blunt/iron_mace" : 1,
    ]) );
  SetAction(10, ({
     "!speak The Masses yearn for freedom!",
     "!speak I can convert you to our ways.",
     "!speak Through Eclat, all is ideal.",
     "!speak From One, Many.",
     "!speak From each, to each.  Such is the cycle.",
     }) );
  SetCombatAction(40, ({
     "!cast sanctify",
     "!cast bless on me",
     }) );
}
