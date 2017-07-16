#include "../rome.h"
#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_NPC;

void LoadArena(object who, string what);
int Preview();

static void create() {
  ::create();
  SetKeyName("Titus Pullo");
  SetShort("Titus Pullo, Master of the Arena");
  SetId( ({ "titus", "pullo", "master" }) );
  SetAdjectives( ({ "titus", "master" }) );
  SetRace("human");
  SetGender("male");
  SetBaseLanguage("Imperial");
  SetClass("fighter");
  SetLevel(300);
  SetMorality(250);
  SetCurrency("imperials", 1500);
  SetInventory( ([
    ROME_OBJ "bsword" : 2,
    ]) );
  SetFirstCommands( ({ "wield swords" }) );
  SetLong(
    "Titus Pullo is the Master of the Arena.  He offers training to those "
    "who ask him. For a price, he will arrange a training match with a "
    "gladiator.  Be warned that while the gladiators know when to submit "
    "and end the contest they will not warn their foes to leave."
    );
  SetAction(6, ({
    "!speak You should request training from me.  I'll explain my prices.",
    "!speak Have you the guts to compete in the arena? Ask me for help to find out.",
    }) );
  SetCommandResponses( ([
    "default" : (: Preview :),
    ]) );
  SetLimit(1);
}

int Preview() {
  string *weps = ({ "slash", "pierce", "hack", "melee", "blunt", "pole", "projectile", "knife" });
  int cost;
  object who = this_player();
  
  eventForce("speak I'm not sure what you're requesting from me.  You should \"request "
             "<type> training from titus\", where <type> is the specific type of combat "
             "you would like training in.");
  foreach(string wep in weps) {
    cost =  who->GetSkillLevel(wep + " combat");
    cost += who->GetSkillLevel(wep + " combat");
    if (cost < 1) cost = 1;
    cost = cost * 50;
    eventForce("speak I would charge you " + cost + " imperials for a gladiator trained in " + wep + " combat.");
    }
  return 1;
}
 

mixed eventRequest(object who, string what) {
  int cost, x;
  object weapon, npc;
  string *weps = ({ "slash", "pierce", "hack", "pole", "melee", "blunt", "pole", "projectile", "knife" });
  
  switch(what) {
    case "slash training":
      weapon = new(STD_SLASH "shortsword");
      break;
    case "projectile training":
      weapon = new(STD_PROJECTILE "bola");
      break;
    case "blunt training":
      weapon = new(STD_BLUNT "copper_club");
      break;
    case "pole training":
      weapon = new(STD_POLE "baton");
      break;
    case "knife training":
      weapon = new(STD_KNIFE "small_knife");
      break;
    case "hack training":
      weapon = new(STD_HACK "stone_axe");
      break;
    case "pierce training":
      weapon = new(STD_PIERCE "epee");
      break;
    case "melee training":
      weapon = new(STD_MELEE "cestus");
      break;
    default:
      eventForce("speak I'm not sure what you're requesting from me.  You should \"request "
                 "<type> training from titus\", where <type> is the specific type of combat "
                 "you would like training in.");
      return 1;
      break;
    }
 cost  = who->GetLevel();
 if (cost < 1) cost = 1;
 cost = cost * 1200;
 
 if (who->GetCurrency("imperials") < cost) {
    eventForce("speak You can't afford the " + cost + " imperials that I charge "
               "to train someone like you. Go away now.");
    weapon->eventDestruct();
    return 1;
  }
  
 npc = new(ROME_NPC "gladiator");
 if (!npc) {
   eventForce("speak I'm having some labor troubles right now, please come back later.");
   CHAT_D->eventSendChannel("titus", "error", "Failed to clone a new gladiator.");
   return 1;
   }
 if (!weapon) {
   eventForce("speak I seem to be having some inventory issues with that weapon. Perhaps "
              "a different weapon?");
   CHAT_D->eventSendChannel("titus", "error", "Failed to clone a weapon for " + what + ".");
   return 1;
   }
 who->AddCurrency("imperials", -cost);
 npc->eventMove(ROME_ROOM "arena2");
 npc->SetSkill(weapon->GetWeaponType() + " combat", 10, 1);
 npc->SetLevel(who->GetLevel());
 weapon->eventMove(npc);
 npc->SetHired(who);
 npc->eventForce("wield " + weapon->GetKeyName());
 npc->eventForce("yell Come, " + capitalize(who->GetKeyName()) + ", so that you may Salute the Empire!");
 return 1;
}
