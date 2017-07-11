#include <lib.h>
#include <domains.h>
#include <std.h>
#include <damage_types.h>
inherit LIB_PIRATE;

static void create() {
  ::create();
  SetKeyName("averan ensign");
  SetShort("an averan ensign (human)");
  SetId( ({ "ensign", "human" }) );
  SetAdjectives( ({ "averan", "ensign", "human" }) );
  SetRace("human");
  SetReligion("Aetarin");
  SetTown("Averath");
  SetClass("sailor");
  SetLevel(25);
  SetLong("This young officer has achieved enough rank to "
    "captain one of the many small warships that blockade "
    "Averath's coastal waters, working to prevent certain "
    "undesirables from reaching the island."
  );
  SetGender("male");
  SetCaptainAggressiveness(50);
  SetInventory( ([
    INNERSEA_ENCOUNTERS "obj/aetarin_saber" : "wield saber",
    INNERSEA_ENCOUNTERS "obj/averath_jacket" : "wear jacket",
  ]) );
  SetCombatAction( 15, ({
    "!say I have not yet begun to fight!",
    "!say Ye have no honor!",
  }) );
  SetAction( 15, ({
    "!say A sailor's life is lonely.",
    "!say Dolphins off the starboard bow!",
  }) );
  SetShipWander(1);
  SetCurrency("ducats", 2000);
  SetBoarder(INNERSEA_ENCOUNTERS + "averath_corvair/merc");
  SetEncounter( (:eventCheckPlayer:) );

  SetMinLevel(20);
  SetMaxLevel(50);
  SetEncounterDifficulty(-3);
  SetProperty("pirate","averath");
}

int eventEncounterShip(object ship) {
  object targ;
  int piratelevel;
  //debug("looking for witch ship");
  targ = ship->GetPilot();
  if (!targ) { return ::eventEncounterShip(ship); }
  if(targ->GetSkillLevel("conjuring") ||
    targ->GetSkillLevel("necromancy")
  ){
    //debug("found witch ship!");
    return ::eventEncounterShip(ship);
  }
  return 0;
}

int eventCheckPlayer() {
    object who = this_player();
    object pirate;
    int piratelevel;
    if (!creatorp(who) && (
      who->GetSkillLevel("conjuring") ||
      who->GetSkillLevel("necromancy") )
    ) {
      SetAttack(who);
      eventForce("Yell Death to ye witch!");
      return 1;
    } else return 0;
}

