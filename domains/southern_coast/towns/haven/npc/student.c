/*  A student of evokation for the Library */
#include <std.h>
#include <lib.h>
#include "../haven.h"
inherit LIB_NPC;
void SetStuff();

static void create() {
  ::create();
  SetKeyName("student");
    switch (random(4)) {
      case 0: SetRace("elf"); break;
      case 1: SetRace("human"); break;
      case 2: SetRace("half-elf"); break;
      case 3: SetRace("gelfling"); break;
      }
  if (random(2)) { SetGender("male"); } else { SetGender("female"); }
  switch (random(4)) {
    case 0: SetClass("enchanter"); break;
    case 1: SetClass("evoker"); break;
    case 2: SetClass("enchanter"); break;
    case 3: SetClass("evoker"); break;
    }
  SetLevel(random(4) + 1);
  SetMorality(250);
  SetLong("This is a student of magical arts in the Library. "
          "The student looks to be studying something, and not doing "
          "very well at it.");
  SetAction(5, ({
     "!speak Practice with us!",
     "!emote mutters some kind of magical words.",
     "!emote makes a sweeping gesture, but nothing happens.",
     "!cast buffer",
     "!cast wards of protection",
    }) );
  SetCombatAction(15, ({
     "!cast missile",
     "!cast ice ball",
     "!cast buffer",
     "!cast aura",
    }) );
  SetSpellBook( ([
     "aura" : 100,
     "buffer" : 100,
     "missile" : 100,
     "ice ball" : 100,
    ]) );
  SetCurrency("imperials", random(50)+1);
  switch(random(2)) {
  case 0:
  SetInventory( ([
      "/std/weapon/pole/staff" : "wield staff",
      ]) );
  break;
  case 1:
    SetInventory( ([
     "/std/weapon/knife/small_knife" : "wield knife",
    ]) );
  break;
  }
  SetStuff();
 }

string GetShort() {
   return ("a " + GetGender() + " " + GetRace() + " student of magic");
  }

void SetStuff() {
  SetAdjectives( ({ GetGender() }) );
  SetId( ({ GetRace(), "mage", "student" }) );
  if (GetRace() == "half-elf") {
    SetAdjectives( ({ "half", GetGender() }) );
    SetId( ({ "elf", "mage", "student" }) );
    }
  }
