/*  A fake leader */
#include <lib.h>
inherit LIB_LEADER;

static void create() {
    ::create();
  SetKeyName("leader");
  SetClass("illusionist");
  SetShort("a leader");
  SetId( ({ "leader" }) );
  SetAdjectives( ({ "illusionist" }) );
  SetRace("gnome");
  SetLevel(10);
  SetPlayerTitles( ([
    "newbie"   : "the Test Illusionist",
    ]) );
  SetTown("Underland");
  SetLong("This is a test leader.");
 }
