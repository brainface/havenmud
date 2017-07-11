// mahkefel 20111017
#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_PIRATE;

void DoAction();

int slaveCount = 0;

static void create() {
  ::create();
  SetKeyName("slaver captain");
  SetShort("a slaver captain (gnoll)");
  SetId( ({ "captain", "slaver", "gnoll" }) );
  SetAdjectives( ({ "slaver","gnoll","captain" }) );
  SetRace("gnoll");
  SetTown("Lisht");
  SetClass("viking");
  SetLevel(50);
  SetMorality(-1100);
  SetLong("A wide, sneering mouth full of wicked teeth is the most "
    "prominent feature on this captain's face. Criss-crossing scars "
    "and patches of missing fur on his face and bare arms attest "
    "to his many victories over rebellious slaves and other lesser "
    "combatants.");
  SetGender("male");
  SetCaptainAggressiveness(80);
  SetInventory( ([
    // gnolls gotta be specific
    INNERSEA_ENCOUNTERS "obj/galabiyeh" : "wear galabiyeh on torso "
      "and right arm and left arm and right leg and left leg",
    INNERSEA_ENCOUNTERS "obj/lash" : "wield lash",
  ]) );
  SetCombatAction(25, (:DoAction:) );
  SetProperty("pirate", "gnoll");
  SetShipWander(1);
  SetCurrency("deben", 10000);
  SetMinLevel(50);
  SetMaxLevel(180);
  //SetBoarder(INNERSEA_ENCOUNTERS "slaver/piratemen");
  SetFirstMate(INNERSEA_ENCOUNTERS "slaver/hyena");
  //SetPassengerAttacker(INNERSEA_ENCOUNTERS "pirate/smallboarder");
}

void DoAction() {
  object pirate;
  if (slaveCount >= 2 ) return 0;
  message("enter",
    "An emaciated captive %^BOLD%^RED%^bursts%^RESET%^ from the hold "
    "in a desperate attempt to escape!",
     environment(this_object()) );
  pirate = new(INNERSEA_ENCOUNTERS "slaver/slave");
  pirate->SetLevel( GetLevel() - GetLevel()/10);
  pirate->eventMove(environment());
  call_out( (: call_other, pirate, "eventForce", "yell Now's our chance!" :), 2 );
  call_out( (: call_other, pirate, "eventForce", "kill first slaver" :), 2 );
  slaveCount++;
}

