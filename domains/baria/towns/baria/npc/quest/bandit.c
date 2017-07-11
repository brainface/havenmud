#include <lib.h>
#include <std.h>
#include <domains.h>
inherit LIB_NPC;    

private string defense_spell = "fidei defensor";
private string offense_spell = "wrath";

// we're overwriting the snot outta this.
int SetLevel(int level);
string GetDefenseSpell();
string GetOffenseSpell();

static void create() {
  npc::create();      
  SetKeyName("acolyte");
  SetShort("a pious acolyte of Kylin");
  SetLong(                             
    "This Acolyte of Kylin seems devoted to the idea of cutting off trade between Baria "
    "and Keryth."                                                                        
    );                                                                                   
  SetId( ({ "acolyte", }) );                                                             
  SetAdjectives( ({ "pious", "kylin" }) );                                               
  SetProperty("no bump", 1);                                                             
  SetRace("elf");                                                                        
  SetGender("male");                                                                     
  SetClass("cavalier");                                                                  
  SetClass("priest");                                                                    
  SetTown("Haven");
  SetReligion("Kylin");
  SetMorality(1000);
  SetLevel(random(2)+20);
  SetFriends( ({ "acolyte", "cleric" }) );
  SetSpellBook( ([
    "fidei defensor" : 100,
    "wrath"          : 100,
   ]) );
  SetCurrency("imperials",random(70));
  SetInventory( ([
    STD_WEAPON "hack/battle_axe" : "wield axe",
  ]) );
  /*SetCombatAction(30, ({
    "!cast " + defense_spell,
    "!cast " + offense_spell,
    "!cast " + offense_spell,
  }) );*/
}

void eventEnemyDied(object died) {
  if (base_name(died) == BARIA_TOWNS "baria/npc/quest/merchant") {
    eventForce("yell All right then, the runner is dead!");
    eventForce("get all");
    environment()->eventPrint("The acolyte retires back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}

int SetLevel(int level) {
  offense_spell = "smite";

  if (level > 25) {
   offense_spell = "wrath";
  } else if (level > 45) {
    offense_spell = "kylin touch";
  } else if (level > 65) {
    offense_spell = "superior wrath";
  } else if (level > 105) {
    offense_spell = "hand of judgement";
  }

  defense_spell = "touch";
  if (level > 25) {
    defense_spell = "fidei defensor";
  } else if (level > 55) {
    defense_spell = "wall of force";
  } else if (level > 105) {
    defense_spell = "superior wall of force";
  }
  return ::SetLevel(level);
}

string GetDefenseSpell() {
  return defense_spell;
}

string GetOffenseSpell() {
  return offense_spell;
}
