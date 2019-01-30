/*    /lib/corpse.c
 *    from the Nightmare IV LPC Library
 *    standard corpse object
 *    created by Descartes of Borg 960711
 *    Version: @(#) corpse.c 1.6@(#)
 *    Last Modified: 98/09/17 by Zeddicus for Discern Killer spell
 */

#include <lib.h>
#include <message_class.h>
#include "include/corpse.h"

inherit LIB_STORAGE;
inherit LIB_SMELL;
inherit LIB_COOK;
inherit LIB_LIGHT;

private int DecayLife, Count, CallOut, Fresh;
private int Level;
private string Gender;
private int Food;
private string Owner, Race, KillerName, KillerGender, KillerRace;
private string CorpseState, OriginalClass;
private object UserCorpse;

string SetCorpseState(string);
string SetGender(string);
string GetGender();
int SetLevel(int);
int GetLevel();
string GetCorpseState();
void SetKiller(object perp);         // Using a seperate function for all
string SetKillerName(string perp);   // of these aspects to allow for the
string GetKillerName();              // possibility of a spell to randomly
string SetKillerGender(string perp); // scramble killer information.
string GetKillerGender();
string SetKillerRace(string perp);
string GetKillerRace();
string SetOriginalClass(string s);
string GetOriginalClass();

static void create() {
    storage::create();
    light::create();
    SetId( ({ "corpse", "flesh", "remains" }) );
    SetAdjectives( ({"pile of", "rotting", "stinky"}) );
    Count = 0;
    UserCorpse = 0;
    CallOut = 0;
    DecayLife = 1500;
    Owner = 0;
    Race = 0;
    AddSave( ({ "DecayLife", "Count", "CallOut", "Fresh", "Level", "OriginalClass",
                "Gender", "Food", "Owner", "Race", "KillerName", "KillerGender",
                "KillerRace", "CorpseState" }) );
    SetLitString("burning");                
     SetMaterials( ({ "natural" }) );
}

object SetUserCorpse(object who) { return UserCorpse = who; }
object GetUserCorpse() { return UserCorpse; }

mixed direct_eat_obj() {
  if (GetUserCorpse()) return "Oddly you don't think that would be tasty.";
  if (GetCorpseState() == "skeleton") {
    return "There is no meat left on those bones.";
  }
  if ((this_player()->GetRace() == "orc")    ||
      (this_player()->GetRace() == "gnoll")  ||
      (this_player()->GetRace() == "goblin") ||
      (this_player()->GetRace() == "lizardman") ||
      (this_player()->GetRace() == "ogre")   ||
      (this_player()->GetRace() == "dragon") ||
      (this_player()->GetRace() == "daemon") ||
      (this_player()->GetRace() == "nosferatu") ) { 
    return this_player()->CanEat(this_object()); 
  }
  else return (capitalize(pluralize(this_player()->GetRace())) + 
               " like their meat a little bit more well done than that!");
  }
int direct_animate_obj() { 
  if (GetUserCorpse()) return 0;
  return 1; 
}

int direct_offer_obj() { 
  if (GetUserCorpse()) return 0;
  return 1; 
 }

int eventEat(object who) {
  mapping inv;

  inv = GetInventory();
  foreach(object thing in keys(inv)) {
    thing->eventMove(environment());
    }
  send_messages("eat",
  "$agent_name $agent_verb " + GetShort() + ".",
     who, 0, environment(who) );
  who->AddFood(GetStrength());
  eventDestruct();
  return 1;
  }

int GetDecayCount() { return Count; }

int eventDecay() {
  if( !environment() ) {
    Destruct();
    return 0;
  }
  Fresh = 0;
  if (GetLit()) {
    environment()->eventPrint("The stench of burning flesh fills the air as " + GetShort() + " is consumed by flames.");
    Destruct();
    return 1;
  }
  switch(Count) {
    case 1:
	    environment()->eventPrint(capitalize(possessive_noun(Owner)) + " corpse " +
				      "is starting to stink.", MSG_ROOMDESC);
	    SetId(GetId()..., "corpse", "remains");
	    SetAdjectives(GetAdjectives()..., "rotted", "rotting");
      SetCorpseState("rotted corpse");
      SetShort("a mostly rotted corpse");
	    SetSmell("This corpse is beginning to stink up the entire area.");
      break;
    case 2:
      environment()->eventPrint(capitalize(GetShort()) + " decays into a " 
                        "skeleton.");
	    SetId(GetId()..., "skeleton");
      SetAdjectives(GetAdjectives()..., "decaying");
      SetCorpseState("skeleton");
      SetGender("nueter");
      SetShort("a decaying skeleton");
	    SetSmell("Its smell is nearly unbearable.");
      break;
    case 3:
      Destruct();
      return 0;
    }
    Count++;
    return Count;
}

int CanReceive(object ob) { return 1; }

int SetDecayLife(int x) { return (DecayLife = x); }

int GetDecayLife() { return DecayLife; }

void SetCorpse(object who) {
  if( DecayLife < 100 ) {
	  DecayLife = 100;
    }
  SetKeyName("corpse");
  SetGender(who->GetGender());
  SetLevel(who->GetLevel());
  SetId( ({ who->GetKeyName(),  "corpse" }) + who->GetId());
  SetAdjectives( ({ who->GetRace(), }) + who->GetAdjectives());
  Owner = who->GetCapName();
  Race = who->GetRace();
  if (Race == "elf") { SetClass(2); SetValue(5); SetDamagePoints(100); }
  OriginalClass = who->GetClass();
  Count = 1;
  Food = who->GetLevel() * 5;
  Fresh = 1;
  SetCorpseState("fresh corpse");
  SetShort("a corpse of " + who->GetShort());
  SetLong("As you look closely at " + who->GetCapName() +
	        ", you notice that " +  nominative(who) +
	        " does not appear to be moving.");
  if (userp(who)) {
    SetUserCorpse(who);  
    SetPreventGet(capitalize(GetShort()) + " is too nasty too touch.");
  }
  set_heart_beat(DecayLife/3);
}

void heart_beat() {
  eventDecay();
}

int isFreshCorpse() {
    return Fresh;
}

string GetHealthShort() {
    return "%^RED%^" + GetShort();
}

string GetOwner() { return Owner; }

string GetRace() { return Race; }

string GetSaveString() { return 0; }

int GetStrength() { return (Food); }

void SetKiller(object perp) {
  SetKillerName(perp->GetKeyName());
  SetKillerGender(perp->GetGender());
  SetKillerRace(perp->GetRace());
}

string SetKillerName(string perp) { return (KillerName = perp); }
string GetKillerName() { return KillerName; }

string SetKillerGender(string perp) { return (KillerGender = perp); }
string GetKillerGender() { return KillerGender; }

string SetKillerRace(string perp) { return (KillerRace = perp); }
string GetKillerRace() { return KillerRace; }

string SetCorpseState(string arg) {
  return CorpseState = arg;
}

string GetCorpseState() {
  return CorpseState;
}

int SetLevel(int level) {
  return Level = level;
}

int GetLevel() { return Level; }

string SetGender(string gender) { return Gender = gender; }

string GetGender() { return Gender; }

varargs mixed eventShow(object who, string component) {
	return storage::eventShow(who, component)  + storage::eventShowInterior(who, component);
}

string SetOriginalClass(string s) { return OriginalClass = s; }
string GetOriginalClass() { return OriginalClass; }

int GetMass() {
  int x;
  foreach(object o in all_inventory()) {
    x += o->GetMass();
  }
  return (x + 50);
}

/* Skinning verb functionality for corpses
 * Duuk
 */

mixed direct_skin_obj() {
  if (GetCorpseState() == "skeleton") {
    return "You cannot skin a skeleton.";
  }
  if (GetOriginalClass() != "animal") {
    return "You can only skin animal corpses.";
  }
  return 1;
}

mixed direct_cook_obj() {
  if (GetCorpseState() == "skeleton") {
    return "You cannot cook a skeleton.";
  }
  if (GetOriginalClass() != "animal") {
    return "You can only cook animal corpses.";
  }
  return 1;
}

mixed indirect_get_obj_from_obj(object ob) {
  if (GetUserCorpse() && GetCorpseState() == "fresh corpse"){
     if (GetUserCorpse() != this_player())
       return "You cannot bother that corpse right now.";
    }
  return ::indirect_get_obj_from_obj(ob);
}

varargs mixed eventLight(object who, object tool) {
  if (GetUserCorpse() && GetCorpseState() == "fresh corpse"){
     if (GetUserCorpse() != this_player())
       return "You cannot bother that corpse right now.";
    }
  SetLit(1);
  call_out( (: eventDecay :), 60);
  return 1;
}

string GetShort() {
    if( GetLit() ) return ::GetShort() + " (" + GetLitString() + ")";
    else return ::GetShort();
}

int GetRadiantLight() {
  if (GetLit()) { return 20; }
  return 0;
}

int GetHeat() { 
  if (GetLit()) { return 25; }
  else return 0;
}
    
// mahkefel 2017--added the ability to scrap items for scrummy mats
// and picky races probably shouldn't be able to scrap corpses for mats.
// stealing the direct_ that prevents elf from eating corpses without copying it over again
int direct_scrap_obj() {
  return direct_eat_obj();
}
