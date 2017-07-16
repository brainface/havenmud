//  Trigger command
//  For starting invasions
//  Laoise, 2005

#include <lib.h>
#include <daemons.h>
#include <dirs.h>

inherit LIB_DAEMON;
int SecondHavenUndead();
int SecondJidoorOrc();
int SecondSoleilDemon();
int ThirdSoleilDemon();


mixed cmd(string str) {
  object invasion;
  string file;

  if(!archp(previous_object())) {
    this_player()->eventPrint("You have to be a Admin to start mischief like that.");
    return 1;
  }
  if(!str) {
    this_player()->eventPrint("Trigger what?");
    return 1;
  }
  if(str == "haven demon") {
    object demons = new(DIR_INVASIONS + "/haven_demon/dih_inv");
    INVASION_D->eventRegisterInvasion(demons, this_player());
  return 1;
  }
  if (str == "haven pirate") {
    object pirates = new(DIR_INVASIONS + "/haven_pirate/pih_inv");
    INVASION_D->eventRegisterInvasion(pirates, this_player());
  return 1;
  }
  if(str == "haven undead") {
    object undead = new(DIR_INVASIONS + "/haven_undead/uih_inv");
    INVASION_D->eventRegisterInvasion(undead, this_player());
    call_out((: SecondHavenUndead :), 150);
  return 1;
  }
  if(str == "jidoor lizardmen") {
    object lizardmen = new(DIR_INVASIONS + "/jidoor_lizardmen/lmij_inv");
    INVASION_D->eventRegisterInvasion(lizardmen, this_player());
  return 1;
  }
  if(str == "jidoor orcs") {
    object orcs = new(DIR_INVASIONS + "/jidoor_orc/oij_inv");
    INVASION_D->eventRegisterInvasion(orcs, this_player());
    call_out((: SecondJidoorOrc :), 150);
  return 1;
  }
  if(str == "jidoor templar") {
    object templars = new(DIR_INVASIONS + "/jidoor_templar/tij_inv");
    INVASION_D->eventRegisterInvasion(templars, this_player());
  return 1;
  }
  if(str == "parva bandit") {
    object bandits = new(DIR_INVASIONS + "/parva_bandit/bip_inv");
    INVASION_D->eventRegisterInvasion(bandits, this_player());
  return 1;
  }
  if(str == "parva pirate") {
    object pirates = new(DIR_INVASIONS + "/parva_pirate/pip_inv");
    INVASION_D->eventRegisterInvasion(pirates, this_player());
  return 1;
  }
  if(str == "parva templar") {
    object templars = new(DIR_INVASIONS + "/parva_templar/tip_inv");
    INVASION_D->eventRegisterInvasion(templars, this_player());
  return 1;
  }
  if(str == "sanctum bandit") {
    object bandits = new(DIR_INVASIONS + "/sanctum_bandit/bis_inv");
    INVASION_D->eventRegisterInvasion(bandits, this_player());
  return 1;
  }
  if(str == "shire lizardmen") {
    object lizardmen = new(DIR_INVASIONS + "/shire_lizardmen/lmil_inv");
    INVASION_D->eventRegisterInvasion(lizardmen, this_player());
  return 1;
  }
  if(str == "soleil demon") {
    object demon = new(DIR_INVASIONS + "/soleil_demon/dis_inv");
    INVASION_D->eventRegisterInvasion(demon, this_player());
    call_out((: SecondSoleilDemon :), 150);
  return 1;
  }
  if(str == "soleil goblin") {
    object goblin = new(DIR_INVASIONS + "/soleil_goblin/gis_inv");
    INVASION_D->eventRegisterInvasion(goblin, this_player());
  return 1;
  }
  if(str == "soleil ogre") {
    object ogre = new(DIR_INVASIONS + "/soleil_ogre/ois_inv");
    INVASION_D->eventRegisterInvasion(ogre, this_player());
  return 1;
  }
}

// Other waves of mult-stage invasions

int SecondHavenUndead() {
  object undead = new(DIR_INVASIONS + "/haven_undead/uih_2_inv");
  INVASION_D->eventRegisterInvasion(undead, this_player());
return 1;
}

int SecondJidoorOrc() {
  object orc = new(DIR_INVASIONS + "/jidoor_orcs/oij_2_inv");
  INVASION_D->eventRegisterInvasion(orc, this_player());
return 1;
}

int SecondSoleilDemon() {
  object demon = new(DIR_INVASIONS + "/soleil_demon/dis_2_inv");
  INVASION_D->eventRegisterInvasion(demon, this_player());
  call_out((: ThirdSoleilDemon :), 100);
return 1;
}

int ThirdSoleilDemon() {
  object demon = new(DIR_INVASIONS + "/soleil_demon/dis_3_inv");
  INVASION_D->eventRegisterInvasion(demon, this_player());
return 1;
}


string GetHelp(string blah) {
  return "Syntax: <trigger [invasion]>\n\n"
    "Starts an invasion, for example <trigger haven demon>. The invasions currently avaliable, "
    "listed in the syntax combination that will trigger them, are:\n"
    "Invaded city - Invader Options:\n"
    "Haven - Demon, Pirate or Undead\n"
    "Jidoor - Lizardmen, Orcs, Templar\n"
    "Parva - Bandit, Pirate, Templar\n"
    "Sanctum - Bandit\n"
    "Shire - Lizardmen\n"
    "Soleil - Demon, Goblin or Ogre\n";
}
