/*  Germ inheritable v3.0
 *  Duuktsaryth@Haven
 *  23 April 1998
 */
#include <daemons.h>
#include <lib.h>
#include "include/germ.h"
inherit LIB_ITEM;

private int Contagious = 0, LifeSpan = 0, CureChance = 0, Warmth = 0;
private mixed Suffer;

static void create() {
  ::create();
  AddSave( ({ "LifeSpan" }) );
  CureChance = 100;
  Contagious = 0;
  Suffer = "You suffer from a germ.";
  SetPreventGet("");
  SetPreventDrop("");
  SetPreventPut("");
  SetLong("");
  SetInvis(3);
  SetProperty("germ", 1);
  set_heart_beat(10);
  }

void heart_beat() {
  object *people = ({ });
  int InfCh, Def;
  if (!LifeSpan) {
     eventDestruct();
     return;
    }
  if (!environment()) {
    eventDestruct();
    return;
   }
  if (!environment(environment())) {
    eventDestruct();
    return;
  }
  if (creatorp(environment())) return;
  LifeSpan--;
  if (living(environment()) && !newbiep(environment())) {
    if (environment()->GetUndead()) return;
    if (functionp(Suffer)) evaluate(Suffer);
      else message("system", Suffer, environment());
  }
  if (Contagious) {
    InfCh = GetContagious();
    if (living(environment())) {
      people = all_inventory(environment(environment()));
      people -= ({ environment() });
      people -= filter(people, (: creatorp :) );
      if (!sizeof(people)) return;
      people = filter(people, (: living :) );
      foreach(object person in people) {
        Def = person->GetStatLevel("durability");
        Def += (random(100));
        
        if (InfCh > Def) {
          
          if (!present(GetKeyName(), person)) {
            eventInfect(person);
            }
          }
        }
      }
    }
 }

mixed SetSuffer(mixed effect) {
  return (Suffer = effect);
 }

mixed GetSuffer() {
  return (Suffer);
  }

int SetLifeSpan(int len) {
  return (LifeSpan = len);
  }

int GetLifeSpan() {
  return (LifeSpan);
  }

int SetContagious(int con) {
  return (Contagious = con);
  }

int GetContagious() {
  return (Contagious);
  }

int SetCureChance(int amt) {
  return (CureChance = amt);
  }

int GetCureChance() {
  return (CureChance);
  }


int eventInfect(object who) {
  new(base_name(this_object()))->eventMove(who);
  
  if (userp(who))
  CHAT_D->eventSendChannel("Germ", "reports", who->GetCapName() + " has been infected with " + GetKeyName() + ".");
//  who->eventPrint("You have caught " + add_article(GetKeyName()) + ".");
  return 1;
  }

int eventDestruct() {
  set_heart_beat(0);
  if (environment()) {
    if (userp(environment()))
      CHAT_D->eventSendChannel("Germ", "reports", environment()->GetCapName() + " is cured of " + GetKeyName() + ".");
    }
  ::eventDestruct();
}

string *GetId() {
  return (::GetId() + ({ "germ" }) );
}

mixed direct_look_at_obj() { return 0; }

mixed direct_look_obj() { return 0; }

mixed direct_wield_obj() { return 0; }

direct_cast_str_on_obj() { return 0; }

/* Simulate a temperature */
int SetWarmth(int x) { return Warmth = x; }
int GetWarmth()      { return Warmth; }