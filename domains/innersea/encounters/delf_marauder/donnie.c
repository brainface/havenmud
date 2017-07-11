#include <lib.h>
#include <domains.h>
#include <damage_types.h>
inherit LIB_PIRATE;

// become invis & backstab
void eventBackstab();

// pick between special abilities
void eventSpecial();

// damaging special
void eventGouge();

// pull npc out of combat and turn invis
void eventHide();

int smokeBomb(object killer );

static void create() {
  ::create();
  SetRace("dark-elf");
  SetGender("male");
  SetClass("sailor");
  SetClass("rogue");
  SetSkill("enchantment",1,1);
  SetSkill("dirty tricks",1,1);
  SetLevel(150);
  SetKeyName("donnie");
  SetId( ({ "donnie","dark-elf","assassin" }) );
  SetShort("donnie the Dark-elf Assassin");
  SetAdjectives( ({ "donnie","the dark-elf" }) );
  SetLong(
     "Donnie's pale skin is grey against the silky ebon of his hair "
     "and eyes and he moves with a dexterous grace that not many "
      "possess. His tall and lean frame give many the foolhardy a "
     "very dangerous level of confidence, which he is all too happy "
     "to shred with a quick plunge of his dagger."
  );
  SetInventory( ([
    INNERSEA_ENCOUNTERS "delf_marauder/don_knife":"wield dagger",
    INNERSEA_ENCOUNTERS "delf_marauder/don_pants":"wear pants",
    INNERSEA_ENCOUNTERS "delf_marauder/don_cloak":"wear cloak on torso",
    INNERSEA_ENCOUNTERS "delf_marauder/don_tricorn":"wear tricorne on head",
  ]) );
  SetCaptainAggressiveness(80);
  SetAction(25, (:eventBackstab:) );
  SetCombatAction(33, (:eventSpecial:) );
  SetResistance(ALL_ELEMENTS|ALL_PHYSICAL|MAGIC,"medium");//cheeeeaaatting
  SetProperty("pirate", "pirate");
  SetReligion("Soirin");
  SetTown("Malveillant");
  SetShipWander(1);
  SetCurrency("roni", 20000);
  SetInvis(1);
  SetMinLevel(200);
  SetMaxLevel(500);
  SetEncounterDifficulty(5);

  // Donnie is faster than you.
  SetNoCorpse(1);
  SetDie( (: smokeBomb :) );
}

void eventBackstab() {
  object ship = environment();

  object sapsucker;

  if (!random(3)) {
    eventForce("laugh evilly");
    return;
  }
  if (ship->GetPilot()) {
    sapsucker = ship->GetPilot();
    //if (!checkHostile(sapsucker)) return 0;
    send_messages("step",
      "$agent_name $agent_verb out of the %^BOLD%^BLACK%^shadows%^RESET%^ directly behind $target_name!",
      this_object(), sapsucker, environment()
    );
    eventForce("shiv " + sapsucker->GetKeyName());
    SetInvis(0);
  }
  return;
}

// either hide in shadows or deal damage somehow.
void eventSpecial() {
  switch(random(3)){
  case 0:
    eventHide();
    break;
  case 1:
    eventForce("gouge");
    break;
  case 2:
    eventForce("bumrush");
    break;
  }
  return;
}

// a hiding we will go
void eventHide() {
  send_messages("fade","$agent_name%^BOLD%^BLACK%^ $agent_verb %^RESET%^into the shadows",
    this_object(),0,environment());
  foreach (object enemy in this_object()->GetEnemies()) {
    enemy->RemoveEnemy(this_object());
    this_object()->RemoveEnemy(enemy);
    enemy->ResetCurrentEnemy();
    enemy->ResetCurrentEnemy();
  }
  SetInvis(1);
}


// Mostly to make named npc reapparing in different ships somehow vaguely make sense.
int smokeBomb(object killer) {
  send_messages( ({"reel"}), "$agent_name%^RED%^BOLD%^ $agent_verb%^RESET%^ from $agent_possessive wounds!",
    this_object(), 0, environment(this_object()) );
  eventForce("yell This isn't over, not by a long shot!");
  send_messages( ({"drop","vanish"}), "$agent_name $agent_verb $agent_possessive hat and" //sic
    "%^BLACK%^BOLD%^ $agent_verb%^RESET%^ overboard in a puff of smoke!",
    this_object(), 0, environment(this_object()) );
  eventForce("drop all");
  call_out( (:eventDestruct :), 0);
  return 0;
}

