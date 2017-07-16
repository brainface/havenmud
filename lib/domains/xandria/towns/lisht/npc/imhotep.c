//Selket@Haven
//2006
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../lisht.h"
inherit LIB_LEADER;

static void create(){
  leader::create();
  SetKeyName("imhotep");
  SetShort("Imhotep, the Justified");
  SetId( ({ "imhotep", "priest" }) );
  SetAdjectives( ({ "justified" }) );
  SetLong(
    "Imhotep is the holiest of all priests of Xandria. His dark "
    "glittering eyes seem to hold within them boundless knowledge "
    "of his world and an uncompromising faith to his goddess."
  );
  SetFriends( ({ "neferu" }) );
  SetRace( "gnoll");
  SetClass( "priest" );
  SetBaseLanguage("Rehshai");
  SetLevel(70);
  SetGender( "male" );
  SetUniqueSkills( ([
  ]) );
  SetSpellBook( ([
    "pious obstructions" : 100,
    "barrier of faith" : 100,
    "divine field" : 100,
    "touch of death" : 100,
    "harmony hand" : 100,
    "harmony wind" : 100,
    "turning" : 100,
    "divine cataclysm" : 100,
  ]) );
  SetAction(10, ({
    "!speak Selket brings us glory, so long as we are dutiful.",
     "!cast wall of force",
    "!speak All who are someday return to her.",
    "!speak She gives us breath, and can take it away.",
    "!speak What is it that you seek, worthless one?",
    "!emote bows before the altar.",
  }) );
  SetCombatAction(15, ({
    "!cast harmony hand",
    "!cast divine cataclysm",
    "!cast divine field",
    "!cast touch of death",
  }) );
  SetReligion("Enniae");
  SetTown("Lisht");
  SetPlayerTitles( ([
    "newbie" : "the Acolyte of Enniae",
    "mortal" : "the Priest of Enniae",
    "hm" : "the Dreaded Priest of Enniae",
    "legend" : "the Venom Lord",
    "avatar" : "the Mouthpiece of Selket",
    "cavalier" : "the Keeper of the Threshold",
    "fighter" : "the Uplifted of Enniae",
  ]) );
  SetRestrictRace(1);
  SetInventory( ([
    "/std/weapon/blunt/staff" : "wield staff",
    LISHT_OBJ "shenti" : "wear shenti",
    LISHT_OBJ "cl_amulet.c" : "wear amulet",
  ]) );
}
