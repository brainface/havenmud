#include <lib.h>                                                                                                                                                                    
#include <std.h>                                                                                                                                                                    
#include <domains.h>                                                                                                                                                                
inherit LIB_NPC;                                                                                                                                                                    
int Fighty();                                                                                                                                                                       

private string defense_spell = "fidei defensor";
private string offense_spell = "wrath";

string GetDefenseSpell();
string GetOffenseSpell();

int SetupSpells(int level);

static void create() {
  npc::create();      
  SetKeyName("cleric");
  SetShort("a pious cleric of Kylin");
  SetLong(                            
    "This cleric of Kylin shows no interest in discussing world events, only in killing "
    "evil-doers and those that aid them."                                                
    );                                                                                   
  SetId( ({ "cleric" }) );                                                               
  SetAdjectives( ({ "pious", "kylin" }) );                                               
  SetTown("Haven");
  SetReligion("Kylin");                                                                                         
  SetRace("elf");                                                                        
  SetGender("female");                                                                   
  SetClass("priest");
  SetSkill("slash combat",1,1);                                                                    
  SetLevel(random(2)+1);                                                                 
  SetFriends( ({ "acolyte", "cleric" }) );                                               
  SetMorality(1000);                                                                      
  SetCurrency("imperials",random(70));                                                   
  SetInventory( ([                                                                       
    STD_WEAPON + "slash/shortsword" : "wield shortsword",                                
  ]) );                                                                                  
  /*
  SetCombatAction(30, ({
    "!cast "+ defense_spell,
    "!cast "+ offense_spell,
    "!cast "+ offense_spell,
  }) );*/
}

void eventEnemyDied(object died) {
  if (base_name(died) == BARIA_TOWNS "baria/npc/quest/merchant") {
    eventForce("yell All right then, the runner is dead!");
    eventForce("get all");
    environment()->eventPrint("The cleric retreats back from whence he came!");
    call_out( (: eventDestruct :), 0);
  }
  return ::eventEnemyDied(died);
}


int SetupSpells(int level) {
  offense_spell = "smite";
 
  if (level > 25) {
   offense_spell = "wrath";
  }
  if (level > 45) {
    offense_spell = "kylin touch";
  }
  if (level > 65) {
    offense_spell = "superior wrath";
  }
  if (level > 105) {
    offense_spell = "hand of judgement";
  }

  defense_spell = "touch";
  if (level > 25) {
    defense_spell = "fidei defensor";
  }
  if (level > 55) {
    defense_spell = "wall of force";
  }
  if (level > 105) {
    defense_spell = "superior wall of force";
  }
}

string GetDefenseSpell() {
  return defense_spell;
}

string GetOffenseSpell() {
  return offense_spell;
}
